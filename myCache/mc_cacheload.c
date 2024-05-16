#include "myCache.h"
#include "mySimpleComputer.h"

int
mc_cacheload (int numberLine)
{
  int buffer[10];
  int j = 0;
  sc_tcounterSet (10);
  // usleep (2 * 500000); //TODO Не забыть выставить на 10
  for (int i = numberLine; i < numberLine + 10; i++)
    {
      if (i > 127)
        {
          buffer[j] = 0;
          j++;
          continue;
        }

      sc_memoryGet (i, &buffer[j]);
      j++;
    }

  for (int i = 0; i < CACHE_SIZE; i++)
    {
      if (cache[i].isEmpty == 1)
        {
          for (int j = 0; j < CACHE_LINE_SIZE; j++)
            {
              cache[i].dataLine[j] = buffer[j];
            }
          cache[i].isEmpty = 0;
          cache[i].numberLine = numberLine;
          return 0;
        }
    }

  int leastUsedLine = 0;
  int ageLine = 0;

  for (int i = 0; i < CACHE_SIZE; i++)
    {
      if (cache[i].lastAccess > ageLine)
        {
          ageLine = cache[i].lastAccess;
          leastUsedLine = i;
        }
    }

  for (int i = 0; i < 10; i++)
    {
      sc_memorySet (cache[leastUsedLine].numberLine + i,
                    cache[leastUsedLine].dataLine[i]);
      cache[leastUsedLine].dataLine[i] = buffer[i];
    }
  cache[leastUsedLine].numberLine = numberLine;
  cache[leastUsedLine].lastAccess = 0;

  return 0;
}