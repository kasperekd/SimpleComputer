#ifndef MY_CONTROLLER_H
#define MY_CONTROLLER_H

#include "mySimpleComputer.h"

#define CACHE_LINE_SIZE 10
#define CACHE_SIZE 5

typedef struct
{
  int dataLine[CACHE_LINE_SIZE];
  int numberLine;
  int lastAccess;
  int isEmpty;

} CacheLine;

extern CacheLine cache[CACHE_SIZE];

int mc_cacheInit ();
int mc_cacheage (int current);
int mc_cacheload (int numberLine);
int mc_controllerread (int address, int *value);
int mc_controllerwrite (int address, int value);

#endif