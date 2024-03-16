#include "myBigChars.h"

int
bc_strlen (char *str)
{
  if (str == NULL)
    {
      return 0;
    }

  int length = 0;
  uint8_t byte;

  while (*str != '\0')
    {
      byte = (uint8_t)*str;

      if ((byte & 0xC0) != 0x80)
        {
          if ((byte & 0x80) == 0 || (byte & 0xC0) == 0xC0)
            {
              length++;
            }
          else
            {
              return 0;
            }
        }

      str++;
    }

  return length;
}