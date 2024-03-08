#ifndef _PRINT_H
#define _PRINT_H 1
#include "../include/mySimpleComputer.h"
#include "../include/myTerm.h"
#include <stdio.h>

void printCell (int address);
void printFlags ();
void printDecodedCommand (int value);
void printAccumulator ();
void printCounters ();

#endif