#define ALLOW_REG_ACCESS
#include "../include/mySimpleComputer.h"

int
sc_icounterGet (int *value)
{
  if (!(*value <= 2147483647 && *value >= -2147483647))
    {
      return -1;
    }
  *value = ICOUNTER;
  return 0;
}