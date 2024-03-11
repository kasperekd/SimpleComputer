#include "sc_print.h"

int IO_LINE = 0;

void printTerm(int address, int input)
{
    mt_gotoXY(IN_OUT_X, IN_OUT_Y + IO_LINE);

    if (input) 
    {
        int value;
        sc_memoryGet(address, &value);

        printf("%02X> +%04X", address, value);
    } 
    else 
    {
        printf("%02X> ", address);
    }

    IO_LINE = (IO_LINE + 1) % 5;
}