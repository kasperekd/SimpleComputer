#include "myCache.h"

int
mc_controllerread (int address, int *value)
{
  int numberLine;
  int offset;
  if (address < 10)
    {
      numberLine = 0;
      offset = address;
    }
  else
    {
      numberLine = (address / 10) * 10;
      offset = address % 10;
    }

  for (int i = 0; i < CACHE_SIZE; i++)
    {
      if (cache[i].numberLine == numberLine)
        {
          *value = cache[i].dataLine[offset];
          mc_cacheage (i);
          return 0;
        }
    }

  mc_cacheload (numberLine);
  for (int i = 0; i < CACHE_SIZE; i++)
    {
      if (cache[i].numberLine == numberLine)
        {
          *value = cache[i].dataLine[offset];
          return 0;
        }
    }

  return 0;
}