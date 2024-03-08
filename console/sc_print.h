#ifndef _PRINT_H
#define _PRINT_H 1
#include "../include/mySimpleComputer.h"
#include "../include/myTerm.h"
#include <stdio.h>

#define RAM_X 1
#define RAM_Y 2

#define FLAGS_X 80
#define FLAGS_Y 2

void printCell (int address, enum colors fg, enum colors bg);
void printFlags ();
void printDecodedCommand (int value);
void printAccumulator ();
void printCounters ();

#endif