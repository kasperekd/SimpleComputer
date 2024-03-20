#include "myBigChars.h"
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
    if (argc == 2) {
        filename = argv[1];
    } else {
        filename = "font.dat";
    }
  FILE *file = fopen (filename, "rb");
  int font[36];
  if (file != NULL)
    {
      fread (font, sizeof (int), sizeof (font) / sizeof (int), file);
      fclose (file);
    }
  else
    {
      printf ("Error opening file.\n");
      return -1;
    }

  sc_memoryInit ();
  sc_accumulatorInit ();
  sc_icounterInit ();
  sc_regInit ();

  bc_box (0, 0, 16, 62, WHITE, BLACK, "MEMORY", RED, BLACK);

  for (int i = 0; i < MEM_SIZE; i++)
    {
      sc_memorySet (i, i);
    }

  for (int i = 0; i < MEM_SIZE; i++)
    {
      if (i == 10)
        {
          printCell (i, BLACK, WHITE);
          continue;
        }
      printCell (i, WHITE, BLACK);
    }

  sc_icounterSet (0x7F);

  printAccumulator ();
  printCounters ();
  printCommand ();
  printDecodedCommand (2);
  printFlags ();

  for (int i = 0; i < 7; i++)
    {
      printTerm (i + 5, 1);
    }

  mt_gotoXY (1, 23);
  printf ("\n");

  // bc_printA("a");

  return 0;
}