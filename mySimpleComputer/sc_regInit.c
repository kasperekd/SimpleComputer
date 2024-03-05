#define ALLOW_REG_ACCESS
#include "../include/mySimpleComputer.h"

unsigned int FLAGS;
const unsigned int REG_SIZE = sizeof (FLAGS) * 8;

int
sc_regInit (void)
{
  FLAGS &= 0;
  return 0;
}