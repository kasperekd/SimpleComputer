#include "sc_print.h"

void
printAccumulator ()
{
  int accumulator;
  sc_accumulatorGet (&accumulator);

  mt_gotoXY (ACC_X, ACC_Y);

  int sign, command, operand;
  sc_commandDecode (accumulator, &sign, &command, &operand);

  int normalValue = (command << 8) ^ operand;
  char signChar;
  if (sign == 0)
    {
      signChar = '-';
    }
  else
    {
      signChar = '+';
    }

  printf ("SC: %c%04X HEX: %04X", signChar, normalValue, accumulator);
}