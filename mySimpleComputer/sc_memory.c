#define ALLOW_MEM_ACCESS
#include "mySimpleComputer.h"

int sc_memoryInit(void)
{
    for (int i = 0; i < MEM_SIZE; i++)
    {
        MEMORY[i] = 0;
    }
    return 0;
}

int sc_memorySet(int address, int value)
{
    if (address > MEM_SIZE - 1 || MEM_SIZE < 0) 
    {
        return -1;
    }
    MEMORY[address] = value;
    return 0;
}

int sc_memoryGet(int address, int * value)
{
    if (address > MEM_SIZE - 1 || MEM_SIZE < 0) 
    {
        return -1;
    }
    *value = MEMORY[address]; 
    return 0;
}
