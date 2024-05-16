#include "sc_print.h"

void
printCounters ()
{
  int icounter, tcounter;
  sc_icounterGet (&icounter);
  sc_tcounterGet (&tcounter);

  mt_gotoXY (COUNT_X, COUNT_Y);

  printf (" T: %02d     ", tcounter);
  printf ("IC: ");
  if (icounter >= 0)
    {
      printf ("+");
    }
  else
    {
      printf ("-");
    }

  printf ("%04X", icounter);
}