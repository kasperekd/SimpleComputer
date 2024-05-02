#include "sc_print.h"

void
printCommand ()
{
  mt_gotoXY (COMMAND_X, COMMAND_Y);

  int valueMEM, valueIC;
  int icResult = sc_icounterGet (&valueIC);
  int memoryResult = sc_memoryGet (valueIC, &valueMEM);

  int sign, command, operand;
  int decodeResult = sc_commandDecode (valueMEM, &sign, &command, &operand);

  if (decodeResult == -1 || icResult == -1 || memoryResult == -1)
    {
      printf ("!");
      printf ("+ FF : FF");
      sc_regSet (REG_MEMORY_OUT_OF_BOUNDS, 1);
    }
  else
    {
      printf ("%c ", ((sign) ? '+' : '-'));
      printf ("%02X : ", command);
      printf ("%02X", operand);
    }
}