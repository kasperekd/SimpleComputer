#include "myBigChars.h"

int
bc_box (int x1, int y1, int x2, int y2, enum colors box_fg, enum colors box_bg,
        char *header, enum colors header_fg, enum colors header_bg)
{
  if (header != NULL)
    {
      printf ("┌");
      printf ("\033[%d;%dH", x1, y1);
      printf ("\033[48;5;%dm\033[38;5;%dm┌", box_bg, box_fg);
      for (int i = 1; i < y2 - 1; i++)
        {
          printf ("─");
        }
      printf ("┐\n");

      printf ("\033[%d;%dH", x1 + 1, y1);
      for (int i = 2; i < x2 - 1; i++)
        {
          printf ("\033[%d;%dH", x1 + i, y1);
          printf ("\033[48;5;%dm\033[38;5;%dm│\033[m\n", box_bg, box_fg);
        }

      for (int i = 2; i < x2 - 1; i++)
        {
          printf ("\033[%d;%dH", x1 + i, y1 + y2);
          printf ("\033[48;5;%dm\033[38;5;%dm│\033[m\n", box_bg, box_fg);
        }

      printf ("\033[%d;%dH", x1 + x2 - 1, y1);
      printf ("\033[48;5;%dm\033[38;5;%dm└", box_bg, box_fg);
      for (int i = 1; i < y2 - 1; i++)
        {
          printf ("─");
        }
      printf ("┘\033[m\n");

      printf ("\033[%d;%dH", x1, y1 + (y2 - strlen (header)) / 2);
      printf ("\033[48;5;%dm\033[38;5;%dm%s\033[m\n", header_bg, header_fg,
              header);
    }

  return 0;
}