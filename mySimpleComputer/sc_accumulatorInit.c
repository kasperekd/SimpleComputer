#define ALLOW_REG_ACCESS
#include "mySimpleComputer.h"

int ACCUMULATOR;

int
sc_accumulatorInit (void)
{
  ACCUMULATOR = 0;
  return 0;
}