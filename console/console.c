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

  //BOXES
  bc_box (0, 0, 62, 16, WHITE, BLACK, "MEMORY", RED, BLACK);
  bc_box (0, 16, 62, 3, WHITE, BLACK, "DECODED", RED, BLACK);
  bc_box (63, 0, 22, 4, WHITE, BLACK, "ACCUMMULATOR", RED, BLACK);
  bc_box (86, 0, 21, 4, WHITE, BLACK, "FLAGS", RED, BLACK);
  bc_box (63, 4, 22, 3, WHITE, BLACK, "COUNTER", RED, BLACK);

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

  mt_gotoXY (1, 23);
  printf ("\n");

  return 0;
}