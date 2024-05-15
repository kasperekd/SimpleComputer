#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mySimpleComputer.h"


// Определение кодов операций
#define READ 0x0A
#define WRITE 0x0B
#define LOAD 0x14
#define STORE 0x15
#define ADD 0x1E
#define SUB 0x1F
#define DIVIDE 0x20
#define MUL 0x21
#define JUMP 0x28
#define JNEG 0x29
#define JZ 0x2A
#define HALT 0x2B
#define NOT 0x33
#define AND 0x34
#define OR 0x35
#define ASSIGNMENT 0xFF // Код операции для команды "="

// Преобразование символьного обозначения команды в ее код
int get_opcode(char *command) {
    if (strcmp(command, "READ") == 0) return READ;
    if (strcmp(command, "WRITE") == 0) return WRITE;
    if (strcmp(command, "LOAD") == 0) return LOAD;
    if (strcmp(command, "STORE") == 0) return STORE;
    if (strcmp(command, "ADD") == 0) return ADD;
    if (strcmp(command, "SUB") == 0) return SUB;
    if (strcmp(command, "DIVIDE") == 0) return DIVIDE;
    if (strcmp(command, "MUL") == 0) return MUL;
    if (strcmp(command, "JUMP") == 0) return JUMP;
    if (strcmp(command, "JNEG") == 0) return JNEG;
    if (strcmp(command, "JZ") == 0) return JZ;
    if (strcmp(command, "HALT") == 0) return HALT;
    if (strcmp(command, "NOT") == 0) return NOT;
    if (strcmp(command, "AND") == 0) return AND;
    if (strcmp(command, "OR") == 0) return OR;
    if (strcmp(command, "=") == 0) return ASSIGNMENT; // Добавлено для команды "="
    return -1; // Команда не найдена
}

// Функция трансляции программы
void translate_program(char *input_file, char *output_file) {
    FILE *input = fopen(input_file, "r");
    FILE *output = fopen(output_file, "wb");

    if (input == NULL || output == NULL) {
        printf("Ошибка открытия файлов.\n");
        return;
    }

    int instructions[MEM_SIZE];
    for (int i = 0; i < MEM_SIZE; i++)
    {
        instructions[i] = 0;
    }
    
    char line[256];

    // Считывание и трансляция инструкций
    while (fgets(line, sizeof(line), input)) {
        int address, operand, value;
        char command[10];
        
        if (line[0] == '=') { // Если строка начинается с "=", то это задание значения ячейки памяти
            sscanf(line, "= +%X ;", &operand);
            // instructions[address].address = address;
            // instructions[address].opcode = ASSIGNMENT;
            // instructions[address].operand = operand;
        } else {
            sscanf(line, "%d %s %X", &address, command, &operand);
            int opcode = get_opcode(command);
            if (opcode == -1) {
                printf("Неизвестная команда: %s\n", command);
                return;
            }
            sc_commandEncode(0,opcode, operand, &value);


            instructions[address] = value;
            // instructions[address].address = address;
            // instructions[address].opcode = opcode;
            // instructions[address].operand = operand;
        }
    }

    // Запись инструкций в файл
    fwrite(instructions, sizeof(int), MEM_SIZE, output);

    fclose(input);
    fclose(output);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Использование: %s файл.sa файл.o\n", argv[0]);
        return 1;
    }

    translate_program(argv[1], argv[2]);

    return 0;
}