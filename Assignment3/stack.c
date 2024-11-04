//
// Created by georg on 2024-11-04.
//
#include "stack.h"
#include <stdlib.h>
#include <stdio.h>

NODE *stack_new_node(char data) {
    NODE *new_node = (NODE *)malloc(sizeof(NODE));
    if (!new_node) return NULL;
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void push(Stack *s, char data) {
    NODE *new_node = stack_new_node(data);
    if (!new_node) return;
    new_node->next = s->top;
    s->top = new_node;
    s->length++;
}

NODE *pop(Stack *s) {
    if (!s->top) return NULL;
    NODE *temp = s->top;
    s->top = s->top->next;
    s->length--;
    return temp;
}

void stack_clean(Stack *s) {
    while (s->top) {
        NODE *temp = s->top;
        s->top = s->top->next;
        free(temp);
    }
    s->length = 0;
}
