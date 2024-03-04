#define ALLOW_REG_ACCESS
#include "../include/mySimpleComputer.h"

int
sc_regInit (void)
{
  FLAGS &= 0;
  return 0;
}