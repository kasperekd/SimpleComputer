#include "myCache.h"

int
mc_cacheage (int current)
{
  for (int i = 0; i < CACHE_SIZE; i++)
    {
      if (i == current)
        {
          cache[i].lastAccess = 0;
        }
      else
        {
          if (cache[i].isEmpty == 0)
            {
              cache[i].lastAccess = cache[i].lastAccess + 1;
            }
        }
    }

  return 0;
}