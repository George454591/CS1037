//
// Created by georg on 2024-11-04.
//
#include "dllist.h"
#include <stdlib.h>
#include <stdio.h>

NODE *new_node(char value) {
    NODE *node = (NODE *)malloc(sizeof(NODE));
    if (node) {
        node->data = value;
        node->next = NULL;
        node->prev = NULL;
    }
    return node;
}

void dll_insert_start(DLLIST *list, char value) {
    NODE *node = new_node(value);
    if (!node) return;

    node->next = list->head;
    if (list->head) list->head->prev = node;
    list->head = node;
    if (!list->tail) list->tail = node;
    list->length++;
}

void dll_insert_end(DLLIST *list, char value) {
    NODE *node = new_node(value);
    if (!node) return;

    node->prev = list->tail;
    if (list->tail) list->tail->next = node;
    list->tail = node;
    if (!list->head) list->head = node;
    list->length++;
}

void dll_delete_start(DLLIST *list) {
    if (!list->head) return;

    NODE *node = list->head;
    list->head = node->next;
    if (list->head) list->head->prev = NULL;
    else list->tail = NULL;
    free(node);
    list->length--;
}

void dll_delete_end(DLLIST *list) {
    if (!list->tail) return;

    NODE *node = list->tail;
    list->tail = node->prev;
    if (list->tail) list->tail->next = NULL;
    else list->head = NULL;
    free(node);
    list->length--;
}

void dll_clean(DLLIST *list) {
    while (list->head) {
        dll_delete_start(list);
    }
}
