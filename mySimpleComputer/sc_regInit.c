#define ALLOW_REG_ACCESS
#include "mySimpleComputer.h"

int sc_regInit (void)
{
    FLAGS &= 0;
    return 0;
}