#include "myBigChars.h"

int
bc_printA (char *str)
{
  char buff[strlen (str)];
  sprintf (buff, "\E(0%s\E(B", str);
  if (write (1, buff, strlen (buff)) == -1)
    {
      return -1;
    }

  return 0;
}