#define ALLOW_REG_ACCESS
#include "mySimpleComputer.h"

int
sc_regGet (int reg, int *value)
{
  if (!value)
    {
      return -1;
    }
  if (reg > 0x0 && reg < 0xff)
    {
      *value = ((FLAGS & (1 << reg)) ? 1 : 0);
      return 0;
    }
  else if (reg == 0)
    {
      *value = FLAGS;
      return 0;
    }
  return -1;
}