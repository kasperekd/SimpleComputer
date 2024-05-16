#define ALLOW_REG_ACCESS
#include "mySimpleComputer.h"

int
sc_tcounterSet (int value)
{
  tcounter = value;
  return 0;
}