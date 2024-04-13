#include "myReadkey.h"
#include "mySimpleComputer.h"
#include "sc_print.h"
#include <stdlib.h>

int
getFileName (char *filename)
{
  rk_mytermsave ();
  rk_mytermregime (0, 0, 1, 1, 1);
  rk_mytermrestore ();
  mt_setbgcolor (GREEN);

  char buffer[64];
  buffer[63] = '\0';
  char c;

  for (int i = 0; i < 64; i++)
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
          buffer[i] = '\0';
          strcpy (filename, buffer);
          rk_mytermrestore ();
          mt_setdefaultcolor ();
          return 1;
        }
      buffer[i] = c;
    }

  rk_mytermrestore ();
  mt_setdefaultcolor ();

  return 0;
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

int
main (int argc, char *argv[])
{
  if (!(isatty (fileno (stdout)) || isatty (fileno (stdin))))
    {
      return -1;
    }

  int rows, cols;
  mt_getscreensize (&rows, &cols);

  if (cols < MIN_T_SIZE_X || rows < MIN_T_SIZE_Y)
    {
      printf ("\nWrong terminal size\nMinimal: Rows - %d Cols - %d\nCurrent: "
              "Rows - %d Cols - %d\n",
              MIN_T_SIZE_Y, MIN_T_SIZE_X, rows, cols);
      return -1;
    }

  mt_clrscr ();

  // READING FONTS
  char *filename;
  if (argc == 2)
    {
      filename = argv[1];
    }
  else
    {
      filename = "font.dat";
    }
  FILE *file = fopen (filename, "rb");
  int fontData[36];
  if (file != NULL)
    {
      fread (fontData, sizeof (int), sizeof (fontData) / sizeof (int), file);
      fclose (file);
    }
  else
    {
      printf ("Error opening file.\n");
      return -1;
    }

  for (int i = 0; i < 18; ++i)
    {
      font[i] = &fontData[i * 2];
    }

  sc_memoryInit ();
  sc_accumulatorInit ();
  sc_icounterInit ();
  sc_regInit ();

  short cur_cell = 0;
  for (int i = 0; i < MEM_SIZE; i++)
    {
      sc_memorySet (i, i + 0xf000);
    }

  for (int i = 0; i < MEM_SIZE; i++)
    {
      if (i == 0)
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

  sc_icounterSet (0x7F);

  printAccumulator ();
  printCounters ();
  printCommand ();
  printFlags ();

  // KEYS TEXT
  mt_gotoXY (80, 20);
  printf ("l - load  s - save  i - reset");
  mt_gotoXY (80, 21);
  printf ("r - run   t - step");
  mt_gotoXY (80, 22);
  printf ("ESC - exit");
  mt_gotoXY (80, 23);
  printf ("F5 - accumulator");
  mt_gotoXY (80, 24);
  printf ("F6 - instruction counter");

  drawBoxes ();

  for (int i = 0; i < 7; i++)
    {
      printTerm (i + 5, 1);
    }

  // rk_mytermsave();
  enum keys key;

  int columns = 10;
  int _rows = MEM_SIZE / columns;
  int lastRowElements = MEM_SIZE % columns;

  char isEdit;
  int newValue;

  char filenameSL[64];
  // 0 - nothing, 1 - memory, 2 - accumulator, 3 - IC
  // char inputState = 0;
  while (1)
    {
      mt_gotoXY (1, 26);
      if (rk_readkey (&key) == 0)
        {
          switch (key)
            {
            case KEY_UP:
              if (cur_cell - columns < 0)
                {
                  if (cur_cell / columns == _rows - 1)
                    {
                      if (cur_cell % columns == 0)
                        {
                          cur_cell = (MEM_SIZE + 2) - lastRowElements;
                        }
                      else
                        {
                          cur_cell -= (columns - 1);
                        }
                    }
                  else
                    {
                      cur_cell
                          = (MEM_SIZE + 2) - (columns - (cur_cell % columns));
                    }
                }
              else
                {
                  cur_cell -= columns;
                }
              break;
            case KEY_DOWN:
              if (cur_cell + columns >= MEM_SIZE)
                {
                  cur_cell %= columns;
                }
              else
                {
                  cur_cell += columns;
                }
              break;
            case KEY_LEFT:
              if (cur_cell % columns == 0)
                {
                  if (MEM_SIZE - cur_cell == 8)
                    {
                      cur_cell += 7;
                    }
                  else
                    {
                      cur_cell += columns - 1;
                    }
                }
              else
                {
                  cur_cell--;
                }
              break;
            case KEY_RIGHT:
              if ((cur_cell + 1) % columns == 0 || cur_cell + 1 == MEM_SIZE)
                {
                  if (MEM_SIZE - cur_cell < 7)
                    {
                      cur_cell -= 7;
                    }
                  else
                    {
                      cur_cell -= columns - 1;
                    }
                }
              else
                {
                  cur_cell++;
                }
              break;
            case KEY_ENTER:
              isEdit = 0;
              if (!isEdit)
                {
                  isEdit = 1;

                  mt_setfgcolor (BLUE);
                  mt_setbgcolor (BLACK);
                  mt_gotoXY (64, 17);
                  printf ("Number of the edited cell: %d", cur_cell);
                  mt_setdefaultcolor ();

                  int row, column;
                  calculateCoordinates (cur_cell, &row, &column);
                  mt_gotoXY (column, row);

                  if (rk_readvalue (&newValue, 0))
                    {
                      sc_memorySet (cur_cell, newValue);
                    }
                }
              else
                {
                  isEdit = 0;
                }
              mt_setfgcolor (BLUE);
              mt_gotoXY (64, 17);
              mt_setdefaultcolor ();
              printf ("                                      ");
              break;
            case KEY_ESC:
              exit (0);
              break;
            case KEY_F5:
              mt_gotoXY (ACC_X + 4, ACC_Y);

              if (rk_readvalue (&newValue, 0))
                {
                  sc_accumulatorSet (newValue);
                }
              break;
            case KEY_F6:
              mt_gotoXY (COUNT_X + 15, COUNT_Y);

              if (rk_readvalue (&newValue, 0))
                {
                  sc_icounterSet (newValue);
                }
              break;
            case KEY_LOAD:
              mt_gotoXY (1, 26);
              printf (
                  "                                                       "
                  "                                                       ");
              mt_gotoXY (1, 26);
              printf ("Enter the name of the file to upload: ");
              if (getFileName (filenameSL))
                {
                  sc_memoryLoad (filenameSL);
                }
              break;
            case KEY_SAVE:
              mt_gotoXY (1, 26);
              printf (
                  "                                                       "
                  "                                                       ");
              mt_gotoXY (1, 26);
              printf ("Enter the name of the file to save: ");
              if (getFileName (filenameSL))
                {
                  sc_memorySave (filenameSL);
                }

              break;
            case KEY_RUN:
              break;
            case KEY_STEP:
              break;
            case KEY_RESET:
              cur_cell = 0;
              for (int i = 0; i < MEM_SIZE; i++)
                {
                  sc_memorySet (i, 0x0);
                }
              sc_accumulatorSet (0);
              sc_icounterSet (0);
              break;
            default:
              break;
            }

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
          drawBoxes ();
        }
      else
        {
          printf ("       ");
        }
    }

  mt_gotoXY (1, 27);
  printf ("\n");

  return 0;
}
