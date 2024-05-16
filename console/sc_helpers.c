#include "sc_helpers.h"

int
getFileName (char *filename)
{
  mt_setbgcolor (GREEN);
  int index = 0;
  char c;

  do
    {
      c = getchar ();

      if (c == 10)
        {
          filename[index] = '\0';
          mt_setdefaultcolor ();
          return 1;
        }
      else if (c == 27)
        {
          mt_setdefaultcolor ();
          return 0;
        }
      else if (c == 8 || c == 127)
        {
          if (index > 0)
            {
              index--;
              mt_setdefaultcolor ();
              printf ("\b \b");
              mt_setbgcolor (GREEN);
            }
        }
      else
        {
          printf ("%c", c);
          filename[index] = c;
          index++;
        }
    }
  while (1);
}

void
calculateCoordinates (int cellNumber, int *row, int *column)
{
  *row = (cellNumber / 10) + 2;
  *column = (cellNumber % 10) * 6 + 2;
}
void
drawBoxes ()
{
  bc_box (0, 0, 62, 16, WHITE, BLACK, "MEMORY", RED, BLACK);
  bc_box (0, 16, 62, 3, WHITE, BLACK, "DECODED (format)", RED, WHITE);
  bc_box (62, 0, 24, 4, WHITE, BLACK, "ACCUMMULATOR", RED, BLACK);
  bc_box (86, 0, 24, 4, WHITE, BLACK, "FLAGS", RED, BLACK);
  bc_box (62, 4, 24, 3, WHITE, BLACK, "COUNTER", RED, BLACK);
  bc_box (86, 4, 24, 3, WHITE, BLACK, "COMMAND", RED, BLACK);
  bc_box (62, 7, 48, 12, WHITE, BLACK, "EDITABLE CELL (enlarged)", RED, WHITE);
  bc_box (0, 19, 68, 7, WHITE, BLACK, "CPU CACHE", GREEN, WHITE);
  bc_box (68, 19, 11, 7, WHITE, BLACK, "IN--OUT", GREEN, WHITE);
  bc_box (79, 19, 31, 7, WHITE, BLACK, "KEYS", GREEN, WHITE);
}

void
drawFrame (int cur_cell)
{
  if (cur_cell < 0)
    cur_cell = MEM_SIZE - 1;
  if (cur_cell >= MEM_SIZE)
    cur_cell = 0;

  for (int i = 0; i < MEM_SIZE; i++)
    {
      if (i == cur_cell)
        {
          printCell (i, BLACK, WHITE);
          int val;
          sc_memoryGet (i, &val);
          printBigCell (val);
          printDecodedCommand (val);
          continue;
        }
      printCell (i, WHITE, BLACK);
    }
  printAccumulator ();
  printCounters ();
  printCommand ();
  printFlags ();
  printCache ();
  drawBoxes ();
}