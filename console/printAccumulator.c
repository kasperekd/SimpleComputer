#include "sc_print.h"

void
printAccumulator ()
{
  int accumulator;
  sc_accumulatorGet (&accumulator);

  mt_gotoXY (ACC_X, ACC_Y);

  printf ("SC: ");
  if (accumulator >= 0)
    {
      printf ("+");
    }
  else
    {
      printf ("-");
    }
  printf ("%04x HEX: %04X", accumulator, accumulator);
}