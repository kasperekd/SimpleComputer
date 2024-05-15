#include "myReadkey.h"
#include "mySimpleComputer.h"
#include "myTerm.h"
#include <ctype.h>

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
      sc_regSet (REG_INVALID_COMMAND, 1);
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
                  sc_regSet (REG_INVALID_COMMAND, 1);
                  return 0;
                }
            }
          int command, operand, val;
          char _command[3], _operand[3];
          _command[0] = digits[0];
          _command[1] = digits[1];
          _command[2] = '\0';

          _operand[0] = digits[2];
          _operand[1] = digits[3];
          _operand[2] = '\0';

          command = strtol (_command, NULL, 16);
          operand = strtol (_operand, NULL, 16);
          // *value = strtol (digits, NULL, 16);
          if (sign == '-')
            {
              if (sc_commandEncode (1, command, operand, &val))
              {
                return -1;
              }
            }
          else
            {
              if (sc_commandEncode (0, command, operand, &val))
              {
                return -1;
              }
            }
          *value = val;
          rk_mytermrestore ();
          mt_setdefaultcolor ();
          return 1;
        }
      digits[i] = c;
    }
  sc_regSet (REG_INVALID_COMMAND, 1);
  rk_mytermrestore ();
  mt_setdefaultcolor ();

  return 0;
}
