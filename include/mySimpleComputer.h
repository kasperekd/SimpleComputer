#pragma once
#ifndef _MYSIMPLECOMPYTER_H_
#define _MYSIMPLECOMPYTER_H_ 1

#include <stddef.h>

#define MEM_SIZE 128

#ifdef ALLOW_MEM_ACCESS
extern int MEMORY[MEM_SIZE];
#endif

#ifdef ALLOW_REG_ACCESS
extern unsigned int FLAGS;
extern const unsigned int REG_SIZE;
extern int ACCUMULATOR;
extern int ICOUNTER;
#endif

#define REG_OVERFLOW 0x01
#define REG_DIVISION_BY_ZERO 0x02
#define REG_MEMORY_OUT_OF_BOUNDS 0x03
#define REG_IMPULSE_IGNORE 0x04
#define REG_INVALID_COMMAND 0x05

#define COMMAND_SIZE 0x010
#define COMMAND_SIGN_BIT 0x8000
#define COMMAND_COMMAND_BITS 0xFF00
#define COMMAND_COMMAND_SHIFT 0x8
#define COMMAND_OPERAND_BITS 0x00FF

int sc_memoryInit (void);
int sc_memorySet (int address, int value);
int sc_memoryGet (int address, int *value);
int sc_memorySave (char *filename);
int sc_memoryLoad (char *filename);

int sc_regInit (void);
int sc_regSet (int register, int value);
int sc_regGet (int register, int *value);

int sc_accumulatorInit (void);
int sc_accumulatorSet (int value);
int sc_accumulatorGet (int *value);

int sc_icounterInit (void);
int sc_icounterSet (int value);
int sc_icounterGet (int *value);

int sc_commandEncode (int sign, int command, int operand, int *value);
int sc_commandDecode (int value, int *sign, int *command, int *operand);
int sc_commandValidate (int command);

#endif