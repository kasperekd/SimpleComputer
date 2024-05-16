#ifndef RPN_H
#define RPN_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct NODE
{
  char data;
  struct NODE* next;
} Node;

void stack_push(char data, Node** top);
void stack_print(Node* top);
char stack_pop(Node** top);
char stack_top(Node* top);
int checkPriority(char sign);
char* translateToRPN(char* inf, char rpn[]);

#endif