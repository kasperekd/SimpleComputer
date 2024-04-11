#include "myReadkey.h"
#include "mySimpleComputer.h"
#include "sc_print.h"

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

  // BOXES
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

  for (int i = 0; i < 7; i++)
    {
      printTerm (i + 5, 1);
    }

  // rk_mytermsave();
  enum keys key;
  short cur_cell = 0;

  int columns = 10;
  int _rows = MEM_SIZE / columns;
  int lastRowElements = MEM_SIZE % columns;

  char isEdit = 0;

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
            mt_gotoXY (64, 17);
            if (!isEdit)
            {
              isEdit = 1;
              mt_setfgcolor (BLUE);
              printf ("Number of the edited cell: %d", cur_cell);
              mt_setdefaultcolor ();
            }
            else
            {
              isEdit = 0;
              printf ("                                      ");
            }              
              break;
            case KEY_ESC:
              break;
            case KEY_F5:
              break;
            case KEY_F6:
              break;
            case KEY_LOAD:
              break;
            case KEY_SAVE:
              break;
            case KEY_RUN:
              break;
            case KEY_STEP:
              break;
            case KEY_RESET:
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