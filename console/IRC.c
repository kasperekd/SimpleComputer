#include "IRC.h"

void
setSignals ()
{
  signal (SIGALRM, IRC);
  signal (SIGUSR1, IRC);

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
  if (signum == SIGALRM)
    {
      int ignorePre;
      sc_regGet (REG_IMPULSE_IGNORE, &ignorePre);
      if (!ignorePre)
        {
          CU ();
          int ignoreAfter;
          sc_regGet (REG_IMPULSE_IGNORE, &ignoreAfter);

          int ic;
          sc_icounterGet (&ic);
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
