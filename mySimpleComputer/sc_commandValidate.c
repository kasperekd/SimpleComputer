#include "mySimpleComputer.h"

int
sc_commandValidate (int command)
{
int sign, _command, operand;

  if (!sc_commandDecode(command, &sign, &_command, &operand))
  {
    return 0;
  }
  
    if (sign != 0 && sign != 1) {
        sc_regSet(REG_INVALID_COMMAND, 1);
        return 0;
    }
    if (_command < 0 || _command > 0x7F) {
        sc_regSet(REG_INVALID_COMMAND, 1);
        return 0;
    }
    if (operand < 0 || operand > 0xFF) {
        sc_regSet(REG_INVALID_COMMAND, 1);
        return 0;
    }
    return 1;

  // if (command < 0 || command >= (1 << 7))
  //   {
  //     sc_regSet (REG_INVALID_COMMAND, 1);
  //     return -1;
  //   }
  // else
  //   {
  //     sc_regSet (REG_INVALID_COMMAND, 0);
  //     return 0;
  //   }
}