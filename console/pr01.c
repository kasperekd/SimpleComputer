#include "../include/mySimpleComputer.h"
#include "sc_print.h"

int
main ()
{
  sc_memoryInit ();
  sc_regInit ();
  sc_icounterInit ();

  sc_memoryLoad ("mem");

  int cell;
  for (int i = 0; i < MEM_SIZE; i++)
    {
      if (i % 8 == 0)
        {
          printf ("\n");
        }
      sc_memoryGet (i, &cell);
      printf ("%d ", cell);
    }

  sc_accumulatorSet (99999);

  int a;
  int status = sc_accumulatorGet (&a);
  printf ("status: %d", status);
  printf ("ACCUMULATOR %d", a);
  return 0;
}