#include "IRC.h"
#include "myReadkey.h"
#include "mySimpleComputer.h"
#include "sc_helpers.h"
#include "sc_print.h"
#include <stdlib.h>

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
  sc_regSet (REG_IMPULSE_IGNORE, 1);
  setSignals ();
  setTimer ();

  int cur_cell = 0;
  for (int i = 0; i < MEM_SIZE; i++)
    {
      sc_memorySet (i, 0x0000);
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

  sc_icounterSet (0);

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

  // for (int i = 0; i < 7; i++)
  //   {
  //     printTerm (i + 5, 1);
  //   }

  // rk_mytermsave();
  enum keys key;

  int columns = 10;
  int _rows = MEM_SIZE / columns;
  int lastRowElements = MEM_SIZE % columns;

  char isEdit;
  int newValue;
  int ignoreFlag;

  char filenameSL[64];
  // 0 - nothing, 1 - memory, 2 - accumulator, 3 - IC
  // char inputState = 0;
  //-----------------------TEST MEM-----------------------//
  // sc_memorySet(0,0x9100);// test

  // sc_memorySet(14,0x2B00); // END
  //  sc_memorySet(8,0x2803); // JUMP
  // sc_memorySet(3,0x0A78); // READ
  // sc_memorySet(4,0x1578); // STORE
  // sc_memorySet(13,0x1478); // LOAD
  // sc_memorySet(5,0x290F); // JNEG
  // sc_memorySet(7,0x2A0F); // JZ
  // sc_memorySet(110,0x8010); // set for add
  // sc_memorySet(5,0x1E6E); // ADD
  // sc_memorySet(5,0x1F6E); // SUB
  // sc_memorySet(5,0x206E); // DIVIDE
  // sc_memorySet(2,0x0100); // CPUINFO
  // sc_memorySet(3,0x3300);

  // sc_icounterSet(0x0000);

  //-----------------------TEST MEM-----------------------//
  while (1)
    {
      mt_gotoXY (1, 26);
      if (rk_readkey (&key) == 0)
        {
          int ignore;
          sc_regGet (REG_IMPULSE_IGNORE, &ignore);
          if (ignore)
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
                          cur_cell = (MEM_SIZE + 2)
                                     - (columns - (cur_cell % columns));
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
                  if ((cur_cell + 1) % columns == 0
                      || cur_cell + 1 == MEM_SIZE)
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
                      "                                                      "
                      " ");
                  mt_gotoXY (1, 26);
                  printf ("Enter the name of the file to upload: ");
                  if (getFileName (filenameSL))
                    {
                      sc_memoryLoad (filenameSL);
                    }
                  mt_gotoXY (1, 26);
                  printf (
                      "                                                       "
                      "                                                      "
                      " ");
                  mt_gotoXY (1, 26);
                  break;
                case KEY_SAVE:
                  mt_gotoXY (1, 26);
                  printf (
                      "                                                       "
                      "                                                      "
                      " ");
                  mt_gotoXY (1, 26);
                  printf ("Enter the name of the file to save: ");
                  if (getFileName (filenameSL))
                    {
                      sc_memorySave (filenameSL);
                    }
                  mt_gotoXY (1, 26);
                  printf (
                      "                                                       "
                      "                                                      "
                      " ");
                  mt_gotoXY (1, 26);
                  break;
                default:
                  break;
                }
            }

          switch (key)
            {
            case KEY_RUN:
              sc_regGet (REG_IMPULSE_IGNORE, &ignoreFlag);
              if (ignoreFlag)
                {
                  sc_regSet (REG_IMPULSE_IGNORE, 0);
                  sc_icounterGet (&cur_cell);
                }
              else
                {
                  sc_regSet (REG_IMPULSE_IGNORE, 1);
                }
              break;
            case KEY_STEP:
              alarm (0);
              sc_regSet (REG_IMPULSE_IGNORE, 0);
              IRC (SIGALRM);
              sc_regSet (REG_IMPULSE_IGNORE, 1);
              setTimer ();
              sc_icounterGet (&cur_cell);
              break;
            case KEY_RESET:
              cur_cell = 0;
              IRC (SIGUSR1);
              break;
            default:
              break;
            }

          if (!ignore)
            {
              sc_icounterGet (&cur_cell);
            }

          drawFrame (cur_cell);
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
