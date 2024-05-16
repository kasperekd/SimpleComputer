#include "IRC.h"

void
setSignals ()
{
  signal (SIGALRM, IRC);
  signal (SIGUSR1, IRC);
}

void
setTimer ()
{
  struct itimerval timer;
  timer.it_value.tv_sec = 0;
  timer.it_value.tv_usec = 500000; // в микросекундах
  timer.it_interval.tv_sec = 0;
  timer.it_interval.tv_usec = 500000;

  setitimer (ITIMER_REAL, &timer, NULL);
}

void
IRC (int signum)
{
  int ic, tc;
  sc_icounterGet (&ic);
  sc_tcounterGet (&tc);
  if (tc != 0)
    {
      sc_tcounterSet (--tc);
      drawFrame (ic);
      // interface (font_array);
      return;
    }

  if (signum == SIGALRM)
    {
      int ignorePre, C, M, Z, O;
      sc_regGet (REG_INVALID_COMMAND, &C);
      sc_regGet (REG_MEMORY_OUT_OF_BOUNDS, &M);
      sc_regGet (REG_OVERFLOW, &O);
      sc_regGet (REG_DIVISION_BY_ZERO, &Z);

      C += M + Z + O;

      if (C > 0)
        {
          sc_regSet (REG_IMPULSE_IGNORE, 1);
          return;
        }

      sc_regGet (REG_IMPULSE_IGNORE, &ignorePre);
      if (!ignorePre)
        {
          CU ();
          int ignoreAfter;
          sc_regGet (REG_IMPULSE_IGNORE, &ignoreAfter);

          // int ic;
          // sc_icounterGet (&ic);
          if (ignorePre == ignoreAfter)
            {
              if (ic < 99 && ic >= 0)
                {
                  sc_icounterSet (++ic);
                }
              else if (ic >= 99)
                {
                  sc_icounterSet (0);
                }
            }
          drawFrame (ic);
        }
    }
  else if (signum == SIGUSR1)
    {
      sc_accumulatorSet (0);
      sc_icounterSet (0);
      sc_regSet (REG_IMPULSE_IGNORE, 1);

      sc_regSet (REG_INVALID_COMMAND, 0);
      sc_regSet (REG_MEMORY_OUT_OF_BOUNDS, 0);
      sc_regSet (REG_OVERFLOW, 0);
      sc_regSet (REG_DIVISION_BY_ZERO, 0);
    }
}
