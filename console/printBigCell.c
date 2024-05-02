#include "sc_print.h"

int *font[18];

void
printBigCell (int val)
{

  int sign, command, operand;
    sc_commandDecode(val, &sign, &command, &operand);

  int normalValue = (command << 8) ^ operand;
  int signIndex;
    if (sign == 0)
    {
      signIndex = 17;
    }
    else
    {
      signIndex = 16;
    }

  int firstDigit = (normalValue & 0xF000) >> 12;
  int secondDigit = (normalValue & 0x0F00) >> 8;
  int thirdDigit = (normalValue & 0x00F0) >> 4;
  int fourthDigit = normalValue & 0x000F;

  bc_printbigchar (font[signIndex], BIGCHAR_X, BIGCHAR_Y, WHITE, BLACK);
  bc_printbigchar (font[firstDigit], BIGCHAR_X + 9, BIGCHAR_Y, WHITE, BLACK);
  bc_printbigchar (font[secondDigit], BIGCHAR_X + 18, BIGCHAR_Y, WHITE, BLACK);
  bc_printbigchar (font[thirdDigit], BIGCHAR_X + 27, BIGCHAR_Y, WHITE, BLACK);
  bc_printbigchar (font[fourthDigit], BIGCHAR_X + 36, BIGCHAR_Y, WHITE, BLACK);
}