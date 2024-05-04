#include "sc_print.h"

int IO_LINE = 0;

void
printTerm (int address, int input)
{
  mt_gotoXY (IN_OUT_X, IN_OUT_Y + IO_LINE);
  mt_setdefaultcolor ();
  char reg = '>';

  if (input < 1)
    {
      reg = '<';
    }
  int value;
  sc_memoryGet (address, &value);

  printf ("%02X%c +%04X", address, reg, value);

  IO_LINE = (IO_LINE + 1) % 5;
}