#define ALLOW_MEM_ACCESS
#include "../include/mySimpleComputer.h"
#include <stdio.h>

int
sc_memorySave (char *filename)
{
  FILE *file = fopen (filename, "wb");
  if (file == NULL)
    {
      return -1;
    }
  if (fwrite (MEMORY, sizeof (int), MEM_SIZE, file) != MEM_SIZE)
    {
      fclose (file);
      return -1;
    }
  fclose (file);
  return 0;
}