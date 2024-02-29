#define ALLOW_REG_ACCESS
#include "../include/mySimpleComputer.h"

int sc_accumulatorSet (int value)
{
    if (value < -2147483648 || value > 2147483647)
    {
        return -1;
    }
    ACCUMULATOR = value;
    return 0;
}