#include "../include/mySimpleComputer.h"

int
sc_commandValidate (int command)
{
  if (command < 0 || command >= (1 << 7))
    {
      return -1;
    }
  else
    {
      return 0;
    }
}