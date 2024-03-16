#include "myBigChars.h"

int
bc_bigcharwrite (int fd, int *big, int count)
{
  if (big == NULL || count < 1)
    {
      return -1;
    }
  if (write (fd, big, (sizeof (int)) * count * 2) == -1)
    {
      return -1;
    }
  return 0;
}