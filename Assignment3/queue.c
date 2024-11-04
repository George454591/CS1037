//
// Created by georg on 2024-11-04.
//
#include "queue.h"
#include <stdlib.h>
#include <stdio.h>

void enqueue(Queue *q, char data) {
    NODE *new_node = (NODE *)malloc(sizeof(NODE));
    if (!new_node) return;
    new_node->data = data;
    new_node->next = NULL;
    if (!q->rear) {
        q->front = q->rear = new_node;
    } else {
        q->rear->next = new_node;
        q->rear = new_node;
    }
    q->length++;
}

char dequeue(Queue *q) {
    if (!q->front) return '\0';
    NODE *temp = q->front;
    char data = temp->data;
    q->front = q->front->next;
    if (!q->front) q->rear = NULL;
    free(temp);
    q->length--;
    return data;
}

void queue_clean(Queue *q) {
    while (q->front) {
        dequeue(q);
    }
}
