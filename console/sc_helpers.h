#ifndef _HELPERS_H
#define _HELPERS_H 1

#include "IRC.h"
#include "myReadkey.h"
#include "mySimpleComputer.h"
#include "sc_print.h"
#include <stdlib.h>

int getFileName (char *filename);
void calculateCoordinates (int cellNumber, int *row, int *column);
void drawBoxes ();
void drawFrame (int cur_cell);

#endif