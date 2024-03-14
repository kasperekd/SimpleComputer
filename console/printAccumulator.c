#include "sc_print.h"

void
printAccumulator ()
{
  int accumulator;
  sc_accumulatorGet (&accumulator);

  mt_gotoXY (ACC_X, ACC_Y);

  printf ("SC: +%04x HEX %04X", accumulator, accumulator);
}