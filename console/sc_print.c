#include "sc_print.h"
#include "../include/mySimpleComputer.h"

void
printCell (int address)
{
  int value;
  sc_memoryGet (address, &value);
  printDecodedCommand (value);
}

void
printFlags ()
{
  int flags;
  if (sc_regGet (0, &flags) == 0)
    {
      printf ("Flags: %c%c%c\n", (flags & REG_OVERFLOW) ? 'O' : '_',
              (flags & REG_DIVISION_BY_ZERO) ? 'Z' : '_',
              (flags & REG_MEMORY_OUT_OF_BOUNDS) ? 'M' : '_');
    }
}

void
printDecodedCommand (int value)
{
  printf ("dec: %d | ", value);
  printf ("oct: %o | ", value);
  printf ("hex: %X | ", value);
  printf ("bin: ");
  for (int i = 15; i >= 0; i--)
    {
      printf ("%d", (value >> i) & 1);
    }
  //printf ("");
}

void
printAccumulator ()
{
  int accumulator;
  sc_accumulatorGet (&accumulator);
  printf ("Accumulator: %04X\n", accumulator);
}

void
printCounters ()
{
  int icounter;
  sc_icounterGet (&icounter);
  printf ("Instruction Counter: %04X\n", icounter);
}