#include "mySimpleComputer.h"

int
sc_commandDecode (int value, int *sign, int *command, int *operand)
{
  int signBit = (value & COMMAND_SIGN_BIT) ? 0 : 1;
  *sign = signBit;
  *command = (value & COMMAND_COMMAND_BITS) >> (COMMAND_COMMAND_SHIFT);
  *operand = value & COMMAND_OPERAND_BITS;

  if ((*command) < 0 || (*command) >= (1 << COMMAND_COMMAND_SHIFT)
      || (*operand) < 0 || (*operand) >= (1 << 10))
    {
      sc_regSet (REG_INVALID_COMMAND, 1);
      return -1;
    }

  return 0;
}
