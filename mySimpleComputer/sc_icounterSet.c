#define ALLOW_REG_ACCESS
#include "mySimpleComputer.h"

int
sc_icounterSet (int value)
{
  if (value < 0x0 || value > 0xffff)
    {
      return 0;
    }
  ICOUNTER = value;
  return 1;
}