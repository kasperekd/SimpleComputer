#include "mySimpleComputer.h"

int
sc_commandEncode (int sign, int command, int operand, int *value)
{
  // if (sign != 0 && sign != 1)
  //   {
  //     sc_regSet (REG_INVALID_COMMAND, 1);
  //     return -1;
  //   }
  // if (command < 0 || command >= 0x7F)
  //   {
  //     sc_regSet (REG_INVALID_COMMAND, 1);
  //     return -1;
  //   }
  // if (operand < 0 || operand >= 0xFF)
  //   {
  //     sc_regSet (REG_INVALID_COMMAND, 1);
  //     return -1;
  //   }

  int val = 0;
  if (sign == 1)
    {
      val |= COMMAND_SIGN_BIT;
    }
  val |= (command << COMMAND_COMMAND_SHIFT);
  val |= (operand & COMMAND_OPERAND_BITS);

  if (sc_commandValidate(val))
  {
    *value = val;
    return 1;
  }

  return 0;
}