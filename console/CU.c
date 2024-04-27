#include "CU.h"

int READ(int operand)
{
    mt_gotoXY (1, 26);
    mt_printText("INPUT > ");

    int value;
    rk_readvalue(&value,0);
    
    if (value < 0x0 || value > 0xffff)
    {
      sc_regSet(REG_MEMORY_OUT_OF_BOUNDS, 1);
      return -1;
    }
    
    sc_memorySet(operand, value);
    printTerm(operand, 0);

    return 0;
}

int WRITE(int operand)
{

    return 0;
}

int LOAD(int operand)
{

    return 0;
}

int STORE(int operand)
{

    return 0;
}

int JUMP(int operand)
{

    return 0;
}

int JNEG(int operand)
{

    return 0;
}

int JZ(int operand)
{

    return 0;
}

int HALT()
{

    return 0;
}

void CU()
{
    int icount;
    if (sc_icounterGet(&icount) < 0)
    {
        sc_regSet(REG_IMPULSE_IGNORE, 1);
        return;
    }
     
    int value = 0;
    if (sc_memoryGet(icount, &value) < 0)
    {
        sc_regSet(REG_MEMORY_OUT_OF_BOUNDS, 1);
        return;
    }
    
    int sign, command, operand;
    if (sc_commandDecode(value, &sign, &command, &operand)< 0 )
    {
        sc_regSet(REG_IMPULSE_IGNORE, 1);
		return;
    }

    if ((command >= 0x1E) && (command <= 0x21))
	{
		ALU(command, operand);
	}
    else
	{
		switch(command)
		{
			case 0x0A:
					READ(operand);
					break;
			case 0x0B:
					WRITE(operand);
					break;
			case 0x14:
					LOAD(operand);
					break;
			case 0x15:
					STORE(operand);
					break;
			case 0x28:
					JUMP(operand);
					break;
			case 0x29:
					JNEG(operand);
					break;
			case 0x2A:
					JZ(operand);
					break;
			case 0x2B:
					HALT();
					break;
		}
	}
    //printTerm(icount, 0);
}