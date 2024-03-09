#include "sc_print.h"

void printTerm(int address, int input)
{
    static int values[4] = {0};
    static int currentIndex = 0;

    if (input) {
        printf("%02d> +%04X\n", address, values[currentIndex]);
        values[currentIndex] = 0; 
    } else {
        printf("%02d> \n", address);
    }

    currentIndex = (currentIndex + 1) % 4;
}