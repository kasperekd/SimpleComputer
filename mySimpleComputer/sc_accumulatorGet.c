#define ALLOW_REG_ACCESS
#include "mySimpleComputer.h"

int
sc_accumulatorGet (int *value)
{
  if (!value)
    {
      return -1;
    }
  *value = ACCUMULATOR;
  return 0;
}