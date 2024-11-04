#include "queue.h"
#include <stdio.h>

void display_queue(Queue q) {
    NODE *current = q.front;
    printf("length %d data ", q.length);
    while (current) {
        printf("%c ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Queue q = {NULL, NULL, 0};
    printf("Test: enqueue\n");
    enqueue(&q, '(');
    display_queue(q);
    enqueue(&q, '2');
    display_queue(q);
    enqueue(&q, '+');
    display_queue(q);
    enqueue(&q, '3');
    display_queue(q);
    enqueue(&q, ')');
    display_queue(q);

    printf("\nTest: dequeue\n");
    dequeue(&q);
    display_queue(q);
    dequeue(&q);
    display_queue(q);
    dequeue(&q);
    display_queue(q);

    queue_clean(&q);
    return 0;
}
