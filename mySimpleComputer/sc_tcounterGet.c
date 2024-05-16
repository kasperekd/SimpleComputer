#define ALLOW_REG_ACCESS
#include "mySimpleComputer.h"

int
sc_tcounterGet (int *value)
{
  if (!value)
    {
      return -1;
    }
  *value = tcounter;
  return 0;
}