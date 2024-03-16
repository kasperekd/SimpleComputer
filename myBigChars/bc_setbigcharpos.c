#include "myBigChars.h"

int
bc_setbigcharpos (int *big, int x, int y, int value)
{

  if (big == NULL || x < 0 || y < 0 || x > 7 || y > 7 || value > 1
      || value < 0)
    {
      return -1;
    }

  int bc_position = x < 4 ? 0 : 1;
  x = x % 4;

  if (value == 1)
    {
      big[bc_position] |= 1 << (x * 8 + y);
    }
  else
    {
      big[bc_position] &= ~(1 << (x * 8 + y));
    }

  return 0;
}