#include "../include/mySimpleComputer.h"
#include <stdio.h>

int main()
{
    sc_memoryInit();    
    sc_regInit();

    sc_memoryLoad("mem");

    // int cell;
    // for (int i = 0; i < MEM_SIZE; i++)
    // {
    //     if (i % 8 == 0)
    //     {
    //         printf("\n");
    //     }
    //     sc_memoryGet(i, &cell);
    //     printf("%d ",cell);
    // }

    //printf("%d\n", REG_SIZE);
    //sc_memorySave("mem");

    return 0;
}