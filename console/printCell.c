#include "sc_print.h"

void
printCell (int address, enum colors fg, enum colors bg)
{
  int value;
  sc_memoryGet (address, &value);
  printDecodedCommand (value);
}