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
      printCell (i);
      if (i % 3 == 2)
        {
          printf ("\n");
        }
    }
  printf ("\n\n");

  // 3
  int addr = 0;
  int over_value = 0xffff + 0x1;
  int state = sc_memorySet (addr, over_value);
  printf ("Addr: %d set: %d state: %d", addr, over_value, state);
  printf ("\n");

  // 4
  sc_regSet (REG_OVERFLOW, 0);
  sc_regSet (REG_DIVISION_BY_ZERO, 1);
  sc_regSet (REG_MEMORY_OUT_OF_BOUNDS, 5);
  printFlags ();

  // 5
  printf ("Incorrect reg status: %d", sc_regSet (0xff, 1));
  printf ("\n");

  // 6
  sc_accumulatorSet (0xA1);
  int acc_state;
  sc_accumulatorGet (&acc_state);
  printf ("Accumulator state: %d", acc_state);
  printf ("\n");

  // 7
  int ac_status = sc_accumulatorSet (0xffff + 0xf);
  int acc_state2;
  sc_accumulatorGet (&acc_state2);
  printf ("Accumulator incorrect status: %d", ac_status);
  printf ("\n");

  // 8
  sc_icounterSet (0xA);
  int ic_state;
  sc_icounterGet (&ic_state);
  printf ("Counter state: %d", ic_state);
  printf ("\n");

  // 9
  int ic_status = sc_icounterSet (0xffff + 0xf);
  int ic_state2;
  sc_accumulatorGet (&ic_state2);
  printf ("Counter incorrect status: %d", ic_status);
  printf ("\n");

  // 10
  int mem_val;
  int acc_val;
  sc_memoryGet (10, &mem_val);
  sc_accumulatorGet (&acc_val);
  printf ("Decoded memory: %d\n", mem_val);
  printf ("Decoded accumulator: %d\n", acc_val);

  // 11
  int com_val;
  sc_commandEncode (0, 3, 7, &com_val);
  printf ("Encoded command: ");
  printDecodedCommand (com_val);
  printf ("\n");

  return 0;
}