#ifndef _PRINT_H
#define _PRINT_H 1
#include <stdlib.h>
#include <stdio.h>
#include "myBigChars.h"
#include "mySimpleComputer.h"
#include "myTerm.h"

#define RAM_X 1
#define RAM_Y 2

#define ACC_X 65
#define ACC_Y 2

#define FLAGS_X 93
#define FLAGS_Y 2

#define COUNT_X 64
#define COUNT_Y 5

#define COMMAND_X 93
#define COMMAND_Y 5

#define DEC_X 2
#define DEC_Y 17

#define IN_OUT_X 69
#define IN_OUT_Y 20
extern int IO_LINE;

#define BIGCHAR_X 64
#define BIGCHAR_Y 8

#define MIN_T_SIZE_X BIGCHAR_X + 45
#define MIN_T_SIZE_Y IN_OUT_Y + 7

extern int *font[18];

void printCell (int address, enum colors fg, enum colors bg);
void printFlags ();
void printDecodedCommand (int value);
void printAccumulator ();
void printCounters ();
void printTerm (int address, int input);
void printCommand ();
void printBigCell (int val);

#endif