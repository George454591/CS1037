// stack_ptest.c

#include <stdio.h>
#include <stdlib.h>

#include "stack.h"
#include "common.h"

void display_stack(Stack s) {
    printf("Stack (length %d): ", s.length);
    NODE *current = s.top;
    while (current != NULL) {
        printf("%c ", current->data);
        current = current->next;
    }
    printf("\n");
}

void test_push() {
    Stack sk = {NULL, 0};
    char test_data[] = {'1', '2', '+', '3', 'a'};

    printf("Testing push:\n");
    for (int i = 0; i < sizeof(test_data) / sizeof(test_data[0]); i++) {
        push(&sk, test_data[i]);
        display_stack(sk);
    }
    stack_clean(&sk);
}

void test_pop() {
    Stack sk = {NULL, 0};
    char test_data[] = {'1', '2', '+', '3', 'a'};

    printf("Testing pop:\n");
    for (int i = 0; i < sizeof(test_data) / sizeof(test_data[0]); i++) {
        push(&sk, test_data[i]);
    }
    while (sk.length > 0) {
        NODE *popped = pop(&sk);
        if (popped != NULL) {
            printf("Popped: %c\n", popped->data);
            free(popped);
        }
        display_stack(sk);
    }
    stack_clean(&sk);
}

int main() {
    test_push();
    test_pop();
    return 0;
}
