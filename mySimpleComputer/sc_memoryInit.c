#define ALLOW_MEM_ACCESS
#include "mySimpleComputer.h"

int MEMORY[MEM_SIZE];

int
sc_memoryInit (void)
{
  for (int i = 0; i < MEM_SIZE; i++)
    {
      MEMORY[i] = 0;
    }
  return 0;
}