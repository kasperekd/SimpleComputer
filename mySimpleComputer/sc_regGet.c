#define ALLOW_REG_ACCESS
#include "mySimpleComputer.h"

int
sc_regGet (int reg, int *value)
{
  if (!value)
    {
      return -1;
    }
  if (reg == REG_OVERFLOW || reg == REG_DIVISION_BY_ZERO
      || reg == REG_MEMORY_OUT_OF_BOUNDS)
    {
      *value = (FLAGS & (1 << reg)) ? 1 : 0;
      return 0;
    }
  else if (reg == 0)
    {
      *value = FLAGS;
      return 0;
    }
  return -1;
}