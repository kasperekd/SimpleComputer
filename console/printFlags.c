#include "sc_print.h"

void
printFlags ()
{
  int flags;
  if (sc_regGet (0, &flags) == 0)
    {
      printf ("Flags: %c%c%c\n", (flags & (1 << REG_OVERFLOW)) ? 'O' : '_',
              (flags & (1 << REG_DIVISION_BY_ZERO)) ? 'Z' : '_',
              (flags & (1 << REG_MEMORY_OUT_OF_BOUNDS)) ? 'M' : '_');
    }
}