#include "sc_print.h"

void
printCounters ()
{
  int icounter;
  sc_icounterGet (&icounter);
  printf ("Instruction Counter: %04X\n", icounter);
}