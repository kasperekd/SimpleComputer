#include "../include/mySimpleComputer.h"
#include <stdio.h>

int main()
{
    sc_memoryInit();
    // sc_memorySet(1, 1);
    // sc_memorySet(3, 1);
    // sc_memorySet(1, 1);
    // sc_memorySet(4, 1);
    // sc_memorySet(30, 1);
    // sc_memorySet(9, 1);
    
    sc_memoryLoad("mem");

    int cell;
    for (int i = 0; i < MEM_SIZE; i++)
    {
        if (i % 8 == 0)
        {
            printf("\n");
        }
        sc_memoryGet(i, &cell);
        printf("%d ",cell);
    }

    //sc_memorySave("mem");

    return 0;
}