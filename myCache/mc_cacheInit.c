#include "myCache.h"

int
mc_cacheInit (void)
{
  for (int i = 0; i < CACHE_SIZE; i++)
    {
      cache[i].numberLine = -1;
      cache[i].lastAccess = 0;
      cache[i].isEmpty = 1;
    }
  return 0;
}