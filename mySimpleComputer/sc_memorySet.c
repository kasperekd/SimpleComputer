#define ALLOW_MEM_ACCESS
#include "../include/mySimpleComputer.h"

int
sc_memorySet (int address, int value)
{
  if (address > MEM_SIZE - 1 || MEM_SIZE < 0)
    {
      return -1;
    }
  MEMORY[address] = value;
  return 0;
}