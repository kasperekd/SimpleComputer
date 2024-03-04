#define ALLOW_REG_ACCESS
#include "../include/mySimpleComputer.h"

int
sc_regGet (int reg, int *value)
{
  if (reg < 0 || reg > REG_SIZE - 1 || value == NULL)
    {
      return -1;
    }
  *value = (FLAGS & (1 << reg)) ? 1 : 0;
  return 0;
}