#include "sc_print.h"

void
printDecodedCommand (int value)
{
  mt_gotoXY (DEC_X, DEC_Y);
  printf (
      "                                                                  ");
  mt_gotoXY (DEC_X, DEC_Y);

  int sign, command, operand;
    sc_commandDecode(value, &sign, &command, &operand);

  int normalValue = (command << COMMAND_COMMAND_SHIFT) ^ operand;
  char signChar;
    if (sign == 0)
    {
      signChar = '-';
    }
    else
    {
      signChar = ' ';
    }
  printf ("DEC:%c%05d | ",signChar, normalValue);
  printf ("OCT:%c%06o | ",signChar, normalValue);
  printf ("HEX:%c%04X  ",signChar, normalValue);
  printf ("BIN: ");
  for (int i = 15; i >= 0; i--)
    {
      printf ("%d", (value >> i) & 1);
    }
}