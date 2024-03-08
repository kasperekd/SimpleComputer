#include "../include/mySimpleComputer.h"
#include "sc_print.h"

int
main ()
{
  // 1
  sc_memoryInit ();
  sc_accumulatorInit ();
  sc_icounterInit ();
  sc_regInit ();

  // 2
  for (int i = 0; i < MEM_SIZE; i++)
    {
      sc_memorySet (i, i);
    }

  for (int i = 0; i < MEM_SIZE; i++)
    {
      printf (" |%d| ", i);
      //printCell (i);
      if (i % 3 == 2)
        {
          printf ("\n");
        }
    }
  printf ("\n\n");


  return 0;
}