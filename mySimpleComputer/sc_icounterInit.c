#define ALLOW_REG_ACCESS
#include "mySimpleComputer.h"

int ICOUNTER;

int
sc_icounterInit (void)
{
  ICOUNTER = 0;
  return 0;
}