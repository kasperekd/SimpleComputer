#define ALLOW_MEM_ACCESS
#include "mySimpleComputer.h"

int
sc_memorySet (int address, int value)
{
  if (address > MEM_SIZE - 1 || MEM_SIZE < 0 || value > 0xffff || value < -0xffff)
    {
      return -1;
    }
  MEMORY[address] = value;
  return 0;
}