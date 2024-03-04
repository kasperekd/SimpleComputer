#include "../include/mySimpleComputer.h"
#include "sc_print.h"

int
main ()
{
  sc_memoryInit ();
  sc_accumulatorInit ();
  sc_icounterInit ();
  sc_regInit ();

  //sc_memoryLoad ("mem");

  for (int i = 0; i < MEM_SIZE; i++)
  {
    sc_memorySet(i,10 + i);
  }
  for (int i = 0; i < MEM_SIZE; i++)
  {
    printf(" |%d| ",i);
    printCell(i);
    if (i % 3 == 2)
    {
      printf("\n");
    }
  }
  printf("\n");
  

  // int cell;
  // for (int i = 0; i < MEM_SIZE; i++)
  //   {
  //     if (i % 8 == 0)
  //       {
  //         printf ("\n");
  //       }
  //     sc_memoryGet (i, &cell);
  //     printf ("%d ", cell);
  //   }

  // sc_accumulatorSet (99999);

  // int a;
  // int status = sc_accumulatorGet (&a);
  // printf ("status: %d", status);
  // printf ("ACCUMULATOR %d", a);
  // return 0;
}