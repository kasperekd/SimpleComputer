#include "myBigChars.h"

int
bc_printbigchar (int big_char[2], int x, int y, enum colors fg, enum colors bg)
{
  mt_gotoXY (x, y);
  mt_setbgcolor (fg);
  mt_setbgcolor (bg);

  int jY = 0;
  int jX = 0;
  for (int i = 31; i >= 0; i--)
    {
      if (i % 8 == 7)
        {
          jY++;
          jX = 0;
          mt_gotoXY (x, y + jY);
        }
      mt_gotoXY (x + jX, y + jY);
      if ((big_char[0] >> i) & 1)
        {
          bc_printA (CKBOARD);
        }
      else
        {
          printf (" ");
        }
      jX++;
    }

  jX = 0;
  for (int i = 31; i >= 0; i--)
    {
      if (i % 8 == 7)
        {
          jY++;
          jX = 0;
          mt_gotoXY (x, y + jY);
        }
      mt_gotoXY (x + jX, y + jY);
      if ((big_char[1] >> i) & 1)
        {
          bc_printA (CKBOARD);
        }
      else
        {
          printf (" ");
        }
      jX++;
    }

  mt_setdefaultcolor ();
  return 1;
}