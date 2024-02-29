#define ALLOW_MEM_ACCESS
#include "mySimpleComputer.h"

int sc_memoryGet(int address, int * value)
{
    if (address > MEM_SIZE - 1 || MEM_SIZE < 0) 
    {
        return -1;
    }
    *value = MEMORY[address]; 
    return 0;
}
