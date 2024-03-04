#include "../include/mySimpleComputer.h"

int
sc_commandEncode (int sign, int command, int operand, int *value)
{
  if (sign != 0 && sign != 1)
    {
      return -1;
    }
  if (command < 0 || command >= (1 << 7))
    {
      return -1;
    }
  if (operand < 0 || operand >= (1 << 10))
    {
      return -1;
    }

  *value = 0;
  if (sign == 1)
    {
      *value |= COMMAND_SIGN_BIT;
    }
  *value |= (command << COMMAND_COMMAND_SHIFT);
  *value |= (operand & COMMAND_OPERAND_BITS);

  return 0;
}