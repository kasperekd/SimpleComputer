#include "mySimpleComputer.h"
#include <stdio.h>

int main()
{
    sc_memoryInit();
    sc_memorySet(1, 1);
    
    int cell;
    sc_memoryGet(1, &cell);

    printf("%d\n",cell);

    return 0;
}