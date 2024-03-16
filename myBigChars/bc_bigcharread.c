#include "myBigChars.h"

int
bc_bigcharread (int fd, int *big, int need_count, int *count)
{
  if (big == NULL || need_count < 1 || count == NULL)
    {
      *count = 0;
      return -1;
    }

  int cnt = read (fd, big, (sizeof (int)) * need_count * 2);

  if (cnt == -1)
    {
      *count = 0;
      return -1;
    }

  *count = cnt / (sizeof (int) * 2);

  return 0;
}