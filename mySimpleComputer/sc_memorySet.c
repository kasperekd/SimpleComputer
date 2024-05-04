#define ALLOW_MEM_ACCESS
#include "mySimpleComputer.h"

int
sc_memorySet (int address, int value)
{
  if (!sc_commandValidate (value))
    {
      return -1;
    }

  if (address > MEM_SIZE - 1 || MEM_SIZE < 0) // value > 0xffff
                                              //|| value < 0x0)
    {
      sc_regSet (REG_MEMORY_OUT_OF_BOUNDS, 1);
      return -1;
    }
  MEMORY[address] = value;
  return 0;
}