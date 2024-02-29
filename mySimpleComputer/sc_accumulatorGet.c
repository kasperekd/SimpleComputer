#define ALLOW_REG_ACCESS
#include "../include/mySimpleComputer.h"

int sc_accumulatorGet (int *value)
{
    if (sizeof(*value) != sizeof(ACCUMULATOR))
    {
        return -1;
    }
    *value = ACCUMULATOR;
    return 0;
}