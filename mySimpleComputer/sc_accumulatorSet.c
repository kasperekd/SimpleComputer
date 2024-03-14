#define ALLOW_REG_ACCESS
#include "mySimpleComputer.h"

int
sc_accumulatorSet (int value)
{
  if (value < 0x0 || value > 0xffff)
    {
      return -1;
    }
  ACCUMULATOR = value;
  return 0;
}