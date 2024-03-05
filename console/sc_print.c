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
      printf ("Flags: %c%c%c\n", (flags & (1 << REG_OVERFLOW)) ? 'O' : '_',
              (flags & (1 << REG_DIVISION_BY_ZERO)) ? 'Z' : '_',
              (flags & (1 << REG_MEMORY_OUT_OF_BOUNDS)) ? 'M' : '_');
    }
}

void
printDecodedCommand (int value)
{
  printf ("DEC: %d ", value);
  printf ("OCT: %o ", value);
  printf ("HEX: %X ", value);
  printf ("BIN: ");
  for (int i = 15; i >= 0; i--)
    {
      printf ("%d", (value >> i) & 1);
    }
// printf ("");
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