#ifndef _PRINT_H
#define _PRINT_H 1
#include <stdio.h>
#include "mySimpleComputer.h"
#include "myTerm.h"
#include "myBigChars.h"

#define RAM_X 1
#define RAM_Y 2

#define ACC_X 65
#define ACC_Y 2

#define FLAGS_X 89
#define FLAGS_Y 2

#define COUNT_X 65
#define COUNT_Y 5

#define COMMAND_X 89
#define COMMAND_Y 5

#define DEC_X 2
#define DEC_Y 17

#define IN_OUT_X 67
#define IN_OUT_Y 18
extern int IO_LINE;

#define BIGCHAR_X 65
#define BIGCHAR_Y 6

#define MIN_T_SIZE_X BIGCHAR_X + 45
#define MIN_T_SIZE_Y IN_OUT_Y + 6

extern int *font[18];

void printCell (int address, enum colors fg, enum colors bg);
void printFlags ();
void printDecodedCommand (int value);
void printAccumulator ();
void printCounters ();
void printTerm (int address, int input);
void printCommand ();
void printBigCell(int val);

#endif