#define ALLOW_REG_ACCESS
#include "mySimpleComputer.h"

int
sc_regSet (int reg, int value)
{
  if (reg < 0 || reg > REG_SIZE - 1)
    {
      return -1;
    }
  if (value == 0)
    {
      FLAGS &= ~(1 << reg);
    }
  else
    {
      FLAGS |= (1 << reg);
    }
  return 0;
}