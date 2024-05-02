#include "ALU.h"

int ADD(int operand)
{
    int a, b;
    sc_accumulatorGet(&a);
    sc_memoryGet(operand, &b);

    sc_accumulatorSet(a + b);

    return 0;
}

int SUB(int operand)
{
    int a, b;
    sc_accumulatorGet(&a);
    sc_memoryGet(operand, &b);

    sc_accumulatorSet(a - b);

    return 0;
}

int ALU(int command, int operand)
{
    switch(command)
		{
			case 0x1E:
					ADD(operand);
					break;
			case 0x1F:
					SUB(operand);
					break;
			case 0x20:
					// DIVIDE(operand);
					break;
			case 0x21:
					// MUL(operand);
					break;
		}
    return 0;
}