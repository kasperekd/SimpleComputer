#include "sc_print.h"

void
printAccumulator ()
{
  int accumulator;
  sc_accumulatorGet (&accumulator);
  printf ("Accumulator: %04X\n", accumulator);
}