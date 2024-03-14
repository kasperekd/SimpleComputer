#ifndef _PRINT_H
#define _PRINT_H
#include <stdio.h>
#include "mySimpleComputer.h"

void printCell (int address);
void printFlags ();
void printDecodedCommand (int value);
void printAccumulator ();
void printCounters ();

#endif