#ifndef STACK_H
#define STACK_H

#include "common.h"

typedef struct {
    NODE *top;
    int length;
} Stack;

NODE *stack_new_node(char data);
void push(Stack *s, char data);
NODE *pop(Stack *s);
void stack_clean(Stack *s);

#endif // STACK_H
