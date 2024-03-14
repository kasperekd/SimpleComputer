#include "sc_print.h"

void
printCounters ()
{
  int icounter;
  sc_icounterGet (&icounter);

  mt_gotoXY (COUNT_X, COUNT_Y);

  printf ("T: 00 IC: +%04X", icounter);
}