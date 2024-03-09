#ifndef _PRINT_H
#define _PRINT_H 1
#include "../include/mySimpleComputer.h"
#include "../include/myTerm.h"
#include <stdio.h>

#define RAM_X 1
#define RAM_Y 2

#define ACC_X 63
#define ACC_Y 2

#define COUNT_X 63
#define COUNT_Y 4

#define FLAGS_X 83
#define FLAGS_Y 2

#define DEC_X 2
#define DEC_Y 16

void printCell (int address, enum colors fg, enum colors bg);
void printFlags ();
void printDecodedCommand (int value);
void printAccumulator ();
void printCounters ();

#endif