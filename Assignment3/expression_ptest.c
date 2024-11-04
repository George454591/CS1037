#include "expression.h"
#include "queue.h"
#include <stdio.h>

void display_queue(Queue queue) {
    NODE *current = queue.front;
    while (current) {
        printf("%c ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    char *tests[] = {"1+2", "(1+2*3)", "10-((3*4)+8)/4"};
    int num_tests = sizeof(tests) / sizeof(tests[0]);

    printf("Test: infix_to_postfix\n");
    for (int i = 0; i < num_tests; i++) {
        Queue q = {NULL, NULL, 0};
        infix_to_postfix(tests[i], &q);
        printf("infix_to_postfix(%s): ", tests[i]);
        display_queue(q);
        queue_clean(&q);
    }

    printf("\nTest: evaluate_postfix\n");
    for (int i = 0; i < num_tests; i++) {
        Queue q = {NULL, NULL, 0};
        infix_to_postfix(tests[i], &q);
        printf("evaluate_postfix(");
        display_queue(q);
        printf("): %d\n", evaluate_postfix(q));
        queue_clean(&q);
    }

    return 0;
}
