#include "sc_print.h"

void
printDecodedCommand (int value)
{
  mt_gotoXY (DEC_X, DEC_Y);
  printf ("DEC: %d | ", value);
  printf ("OCT: %o | ", value);
  printf ("HEX: %X | ", value);
  printf ("BIN: ");
  for (int i = 15; i >= 0; i--)
    {
      printf ("%d", (value >> i) & 1);
    }
}