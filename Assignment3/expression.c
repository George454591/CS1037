//
// Created by georg on 2024-11-04.
//
#include "expression.h"
#include "stack.h"
#include "queue.h"
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>

int precedence(char op) {
    // Define precedence for operators
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return 0;
    }
}

int is_operator(char c) {
    // Check if character is an operator
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

void infix_to_postfix(const char *infix, Queue *postfix_queue) {
    // Convert infix expression to postfix notation
    Stack operator_stack = {NULL, 0};
    while (*infix) {
        if (isdigit(*infix)) {
            enqueue(postfix_queue, *infix);
        } else if (*infix == '(') {
            push(&operator_stack, *infix);
        } else if (*infix == ')') {
            while (operator_stack.top && operator_stack.top->data != '(') {
                enqueue(postfix_queue, pop(&operator_stack)->data);
            }
            pop(&operator_stack); // Remove '(' from stack
        } else if (is_operator(*infix)) {
            while (operator_stack.top && precedence(operator_stack.top->data) >= precedence(*infix)) {
                enqueue(postfix_queue, pop(&operator_stack)->data);
            }
            push(&operator_stack, *infix);
        }
        infix++;
    }
    while (operator_stack.top) {
        enqueue(postfix_queue, pop(&operator_stack)->data);
    }
}

int evaluate_postfix(Queue queue) {
    // Evaluate postfix expression
    Stack eval_stack = {NULL, 0};
    NODE *current = queue.front;
    while (current) {
        if (isdigit(current->data)) {
            push(&eval_stack, current->data - '0');
        } else if (is_operator(current->data)) {
            int right = pop(&eval_stack)->data;
            int left = pop(&eval_stack)->data;
            int result;
            switch (current->data) {
                case '+': result = left + right; break;
                case '-': result = left - right; break;
                case '*': result = left * right; break;
                case '/': result = left / right; break;
                default: result = 0;
            }
            push(&eval_stack, result);
        }
        current = current->next;
    }
    return pop(&eval_stack)->data;
}
int evaluate_infix(const char *infix) {
    Queue postfix_queue = {0};           // Initialize an empty queue for postfix
    infix_to_postfix(infix, &postfix_queue);   // Convert infix to postfix
    int result = evaluate_postfix(postfix_queue); // Evaluate the postfix expression
    queue_clean(&postfix_queue);          // Clean up the queue
    return result;
}