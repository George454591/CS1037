#ifndef QUEUE_H
#define QUEUE_H
#include"common.h"


typedef struct {
    NODE *front;
    NODE *rear;
    int length;
} Queue;

void enqueue(Queue *q, char data);
char dequeue(Queue *q);
void queue_clean(Queue *q);

#endif // QUEUE_H
