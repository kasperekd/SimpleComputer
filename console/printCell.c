#include "sc_print.h"

void
printCell (int address, enum colors fg, enum colors bg)
{
  int x = RAM_X;
  int y = RAM_Y;

  int cell_x = x + (address % 10) * 6 + 1;
  int cell_y = y + (address / 10) * 1;

  mt_setfgcolor (fg);
  mt_setbgcolor (bg);

  mt_gotoXY (cell_x, cell_y);

  int value;
  sc_memoryGet (address, &value);

if (value > 0)
{
  printf ("+");
}
else{
  printf ("-");
}

  printf ("%04X", value);
  mt_setdefaultcolor ();

  printf (" ");
}