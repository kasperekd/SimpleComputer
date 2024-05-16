#define ALLOW_REG_ACCESS
#include "mySimpleComputer.h"

int tcounter;

int
sc_tcounterInit (void)
{
  tcounter = 0;
  return 0;
}