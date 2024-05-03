#include "ALU.h"

int ADD(int operand)
{
    int a, b;
    sc_accumulatorGet(&a);
    sc_memoryGet(operand, &b);

    int sign1, command1, _operand1;
    int sign2, command2, _operand2;
    int normalValue1, normalValue2;
    
    sc_commandDecode(a, &sign1, &command1, &_operand1);
    sc_commandDecode(b, &sign2, &command2, &_operand2);
    
    normalValue1 = (command1 << COMMAND_COMMAND_SHIFT) ^ _operand1;
    normalValue2 = (command2 << COMMAND_COMMAND_SHIFT) ^ _operand2;
    
	int result = (sign1 == 0 ? -normalValue1 : normalValue1) + (sign2 == 0 ? -normalValue2 : normalValue2);

    int sign_result = (result < 0) ? 1 : 0;
    int normal_result = (result < 0) ? -result : result;
    int command_result = normal_result >> COMMAND_COMMAND_SHIFT;
    int operand_result = normal_result & COMMAND_OPERAND_BITS;

	int encoded_result;
    sc_commandEncode(sign_result, command_result, operand_result, &encoded_result);
    sc_accumulatorSet(encoded_result);
    return 0;
}

int SUB(int operand)
{
    int a, b;
    sc_accumulatorGet(&a);
    sc_memoryGet(operand, &b);

    int sign1, command1, _operand1;
    int sign2, command2, _operand2;
    int normalValue1, normalValue2;
    
    sc_commandDecode(a, &sign1, &command1, &_operand1);
    sc_commandDecode(b, &sign2, &command2, &_operand2);
    
    normalValue1 = (command1 << COMMAND_COMMAND_SHIFT) ^ _operand1;
    normalValue2 = (command2 << COMMAND_COMMAND_SHIFT) ^ _operand2;
    
	int result = (sign1 == 0 ? -normalValue1 : normalValue1) - (sign2 == 0 ? -normalValue2 : normalValue2);

    int sign_result = (result < 0) ? 1 : 0;
    int normal_result = (result < 0) ? -result : result;
    int command_result = normal_result >> COMMAND_COMMAND_SHIFT;
    int operand_result = normal_result & COMMAND_OPERAND_BITS;

	int encoded_result;
    sc_commandEncode(sign_result, command_result, operand_result, &encoded_result);
    sc_accumulatorSet(encoded_result);
    return 0;
}

int DIVIDE (int operand)
{
    int a, b;
    sc_accumulatorGet(&a);
    sc_memoryGet(operand, &b);

    int sign1, command1, _operand1;
    int sign2, command2, _operand2;
    int normalValue1, normalValue2;
    
    sc_commandDecode(a, &sign1, &command1, &_operand1);
    sc_commandDecode(b, &sign2, &command2, &_operand2);
    
    normalValue1 = (command1 << COMMAND_COMMAND_SHIFT) ^ _operand1;
    normalValue2 = (command2 << COMMAND_COMMAND_SHIFT) ^ _operand2;
    
	int result = (sign1 == 0 ? -normalValue1 : normalValue1) / (sign2 == 0 ? -normalValue2 : normalValue2);

    int sign_result = (result < 0) ? 1 : 0;
    int normal_result = (result < 0) ? -result : result;
    int command_result = normal_result >> COMMAND_COMMAND_SHIFT;
    int operand_result = normal_result & COMMAND_OPERAND_BITS;

	int encoded_result;
    sc_commandEncode(sign_result, command_result, operand_result, &encoded_result);
    sc_accumulatorSet(encoded_result);
    return 0;
}

int MUL (int operand)
{
    int a, b;
    sc_accumulatorGet(&a);
    sc_memoryGet(operand, &b);

    int sign1, command1, _operand1;
    int sign2, command2, _operand2;
    int normalValue1, normalValue2;
    
    sc_commandDecode(a, &sign1, &command1, &_operand1);
    sc_commandDecode(b, &sign2, &command2, &_operand2);
    
    normalValue1 = (command1 << COMMAND_COMMAND_SHIFT) ^ _operand1;
    normalValue2 = (command2 << COMMAND_COMMAND_SHIFT) ^ _operand2;
    
	int result = (sign1 == 0 ? -normalValue1 : normalValue1) * (sign2 == 0 ? -normalValue2 : normalValue2);

    int sign_result = (result < 0) ? 1 : 0;
    int normal_result = (result < 0) ? -result : result;
    int command_result = normal_result >> COMMAND_COMMAND_SHIFT;
    int operand_result = normal_result & COMMAND_OPERAND_BITS;

	int encoded_result;
    sc_commandEncode(sign_result, command_result, operand_result, &encoded_result);
    sc_accumulatorSet(encoded_result);
    return 0;
}

int NOT(int operand) {
    int word;
    sc_memoryGet(operand, &word);
    
    word = ~word;

    sc_memorySet(operand, word);
    return 0;
}

int AND(int operand) {
    int accumulator, word;
    sc_accumulatorGet(&accumulator);
    sc_memoryGet(operand, &word);

    int result = accumulator & word;

    sc_accumulatorSet(result);
    return 0;
}

int OR(int operand) {
    int accumulator, word;
    sc_accumulatorGet(&accumulator);
    sc_memoryGet(operand, &word);

    int result = accumulator | word;

    sc_accumulatorSet(result);
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
					DIVIDE(operand);
					break;
			case 0x21:
					MUL(operand);
					break;
			case 0x33:
					NOT(operand);
					break;
			case 0x34:
					AND(operand);
					break;
			case 0x35:
					OR(operand);
					break;
		}
    return 0;
}