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
      sc_memorySet (i, i + 30000);
    }

  for (int i = 0; i < MEM_SIZE; i++)
    {
      if (i == 120)
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

  mt_gotoXY (1, 26);
  printf ("\n");

  return 0;
}