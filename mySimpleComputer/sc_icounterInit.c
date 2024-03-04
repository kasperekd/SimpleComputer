#define ALLOW_REG_ACCESS
#include "../include/mySimpleComputer.h"

int
sc_icounterInit (void)
{
  ICOUNTER = 0;
  return 0;
}