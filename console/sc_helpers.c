#include "sc_helpers.h"

int getFileName(char *filename)
{
  rk_mytermsave();
  rk_mytermregime(1, 0, 1, 1, 1);
  rk_mytermrestore();
  mt_setbgcolor(GREEN);

  char buffer[64];
  buffer[63] = '\0';
  char c;

  for (int i = 0; i < 64; i++)
  {
    c = getchar();
    if (c == 27)
    {
      rk_mytermrestore();
      mt_setdefaultcolor();
      return 0;
    }
    if (c == 10)
    {
      buffer[i] = '\0';
      strcpy(filename, buffer);
      rk_mytermrestore();
      mt_setdefaultcolor();
      return 1;
    }
    buffer[i] = c;
  }

  rk_mytermrestore();
  mt_setdefaultcolor();

  return 0;
}

void calculateCoordinates(int cellNumber, int *row, int *column)
{
  *row = (cellNumber / 10) + 2;
  *column = (cellNumber % 10) * 6 + 2;
}
void drawBoxes()
{
  bc_box(0, 0, 62, 16, WHITE, BLACK, "MEMORY", RED, BLACK);
  bc_box(0, 16, 62, 3, WHITE, BLACK, "DECODED (format)", RED, WHITE);
  bc_box(62, 0, 24, 4, WHITE, BLACK, "ACCUMMULATOR", RED, BLACK);
  bc_box(86, 0, 24, 4, WHITE, BLACK, "FLAGS", RED, BLACK);
  bc_box(62, 4, 24, 3, WHITE, BLACK, "COUNTER", RED, BLACK);
  bc_box(86, 4, 24, 3, WHITE, BLACK, "COMMAND", RED, BLACK);
  bc_box(62, 7, 48, 12, WHITE, BLACK, "EDITABLE CELL (enlarged)", RED, WHITE);
  bc_box(0, 19, 68, 7, WHITE, BLACK, "CPU CACHE", GREEN, WHITE);
  bc_box(68, 19, 11, 7, WHITE, BLACK, "IN--OUT", GREEN, WHITE);
  bc_box(79, 19, 31, 7, WHITE, BLACK, "KEYS", GREEN, WHITE);
}

void drawFrame(int cur_cell)
{
    if (cur_cell < 0)
        cur_cell = MEM_SIZE - 1;
    if (cur_cell >= MEM_SIZE)
        cur_cell = 0;

    for (int i = 0; i < MEM_SIZE; i++)
    {
        if (i == cur_cell)
        {
            printCell(i, BLACK, WHITE);
            int val;
            sc_memoryGet(i, &val);
            printBigCell(val);
            printDecodedCommand(val);
            continue;
        }
        printCell(i, WHITE, BLACK);
    }
    printAccumulator();
    printCounters();
    printCommand();
    printFlags();
    drawBoxes();
}