#define ALLOW_MEM_ACCESS
#include "mySimpleComputer.h"
#include <stdio.h>

int
sc_memorySave (char *filename)
{
  FILE *file = fopen (filename, "wb");
  if (file == NULL)
    {
      return -1;
    }
  int newMEMORY[128];
  for (int i = 0; i < MEM_SIZE; i++)
    {
      int tmp;
      if (sc_memoryGet (i, &tmp))
        {
          newMEMORY[i] = tmp;
        }
      else
        {
          return -1;
        }
    }

  if (fwrite (newMEMORY, sizeof (int), MEM_SIZE, file) != MEM_SIZE)
    {
      fclose (file);
      return -1;
    }
  fclose (file);
  return 0;
}