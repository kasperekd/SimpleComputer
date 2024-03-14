#define ALLOW_REG_ACCESS
#include "mySimpleComputer.h"

int
sc_icounterGet (int *value)
{
  if (!value)
    {
      return -1;
    }
  *value = ICOUNTER;
  return 0;
}