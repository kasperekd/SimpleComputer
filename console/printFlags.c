#include "sc_print.h"

void
printFlags ()
{
  int flags;
  mt_gotoXY (FLAGS_X, FLAGS_Y);
  if (sc_regGet (0, &flags) == 0)
    {
      printf ("%c %c %c %c %c", (flags & (1 << REG_OVERFLOW)) ? 'O' : '_',
              (flags & (1 << REG_DIVISION_BY_ZERO)) ? 'Z' : '_',
              (flags & (1 << REG_MEMORY_OUT_OF_BOUNDS)) ? 'M' : '_',
              (flags & (1 << REG_IMPULSE_IGNORE)) ? 'I' : '_',
              (flags & (1 << REG_INVALID_COMMAND)) ? 'C' : '_');
    }
}