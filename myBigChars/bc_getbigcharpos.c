#include "myBigChars.h"

int
bc_getbigcharpos (int *big, int x, int y, int *value)
{
  if (big == NULL || value == NULL || x < 0 || y < 0 || x > 7 || y > 7)
    {
      return -1;
    }

  int bc_position = x < 4 ? 0 : 1;
  x = x % 4;

  *value = big[bc_position] >> ((x * 8) + y) & 1;

  return 0;
}