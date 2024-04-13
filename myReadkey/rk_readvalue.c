#include <ctype.h>
#include "myReadkey.h"
#include "myTerm.h"

int
rk_readvalue (int *value, int timeout)
{
  rk_mytermsave ();
  rk_mytermregime (0, timeout, 1, 1, 1);
  rk_mytermrestore ();

  mt_setfgcolor (RED);
  mt_setbgcolor (WHITE);
  char sign;
  char digits[6];

  *value = 0;
  char c;
  sign = getchar ();
  if (sign != '+' && sign != '-')
    {
      return 0;
    }

  for (int i = 0; i < 5; i++)
    {
      c = getchar ();
      if (c == 27)
        {
          rk_mytermrestore ();
          mt_setdefaultcolor ();
          return 0;
        }
      if (c == 10)
        {
          digits[i] = '\0';
          for (int j = 0; digits[j] != '\0'; j++)
            {
              if (!isxdigit (digits[j]))
                {
                  rk_mytermrestore ();
                  mt_setdefaultcolor ();
                  return 0;
                }
            }
          *value = strtol (digits, NULL, 16);
          if (sign == '-')
            *value *= -1;
          rk_mytermrestore ();
          mt_setdefaultcolor ();
          return 1;
        }
      digits[i] = c;
    }
  rk_mytermrestore ();
  mt_setdefaultcolor ();

  return 0;
}
