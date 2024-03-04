#define ALLOW_REG_ACCESS
#include "../include/mySimpleComputer.h"

int
sc_regGet (int reg, int *value)
{
  if (reg < 0 || reg > REG_SIZE - 1 || value == NULL
      || reg != REG_OVERFLOW || reg != REG_DIVISION_BY_ZERO
      || reg != REG_MEMORY_OUT_OF_BOUNDS)
    {
      return -1;
    }
  *value = (FLAGS & (1 << reg)) ? 1 : 0;
  return 0;
}