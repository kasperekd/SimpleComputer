#define ALLOW_MEM_ACCESS
#include "mySimpleComputer.h"
#include <stdio.h>

int
sc_memoryLoad (char *filename)
{
  FILE *file = fopen (filename, "rb");
  if (file == NULL)
    {
      return -1;
    }
  int temp_memory[MEM_SIZE];
  if (fread (temp_memory, sizeof (int), MEM_SIZE, file) != MEM_SIZE)
    {
      fclose (file);
      return -1;
    }
  for (int i = 0; i < MEM_SIZE; i++)
    {
      MEMORY[i] = temp_memory[i];
    }
  fclose (file);
  return 0;
}