#include "mySimpleComputer.h"

int
sc_commandValidate (int command)
{
  if (command < 0 || command >= (1 << 7))
    {
      sc_regSet(REG_INVALID_COMMAND, 1);
      return -1;
    }
  else
    {
      sc_regSet(REG_INVALID_COMMAND, 0);
      return 0;
    }
}