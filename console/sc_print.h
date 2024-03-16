#ifndef _PRINT_H
#define _PRINT_H 1
#include "mySimpleComputer.h"
#include "myTerm.h"
#include <stdio.h>

#define RAM_X 1
#define RAM_Y 2

#define ACC_X 63
#define ACC_Y 2

#define FLAGS_X 83
#define FLAGS_Y 2

#define COUNT_X 63
#define COUNT_Y 4

#define COMMAND_X 83
#define COMMAND_Y 4

#define DEC_X 2
#define DEC_Y 16

#define IN_OUT_X 67
#define IN_OUT_Y 18
extern int IO_LINE;

#define MIN_T_SIZE_X FLAGS_X + 12
#define MIN_T_SIZE_Y IN_OUT_Y + 6

void printCell (int address, enum colors fg, enum colors bg);
void printFlags ();
void printDecodedCommand (int value);
void printAccumulator ();
void printCounters ();
void printTerm (int address, int input);
void printCommand ();

#endif