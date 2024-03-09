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

  mt_clrscr();

  // 2
  for (int i = 0; i < MEM_SIZE; i++)
    {
      sc_memorySet (i, i);
    }

  // printf("\n\n");
  // printTerm(4,0);
  // printf("\n\n");

  for (int i = 0; i < MEM_SIZE; i++)
    {
      printCell (i, BLACK, WHITE);
    }


  sc_regSet (REG_OVERFLOW, 0);
  sc_regSet (REG_DIVISION_BY_ZERO, 1);
  sc_regSet (REG_MEMORY_OUT_OF_BOUNDS, 1);

  sc_icounterSet (0xA);

  printAccumulator();
  printFlags();
  printCounters();
  printCommand();
  printDecodedCommand(2);

  return 0;
}