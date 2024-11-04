//
// Created by georg on 2024-11-04.
//
#include "myrecord_sllist.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

NODE *sll_insert(NODE *head, const char *name, float score) {
    NODE *new_node = (NODE *)malloc(sizeof(NODE));
    if (!new_node) return head;
    strcpy(new_node->record.name, name);
    new_node->record.score = score;
    new_node->next = head;
    return new_node;
}

NODE *sll_search(NODE *head, const char *name) {
    NODE *current = head;
    while (current) {
        if (strcmp(current->record.name, name) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

NODE *sll_delete(NODE *head, const char *name) {
    NODE *current = head, *prev = NULL;
    while (current) {
        if (strcmp(current->record.name, name) == 0) {
            if (prev) prev->next = current->next;
            else head = current->next;
            free(current);
            return head;
        }
        prev = current;
        current = current->next;
    }
    return head;
}

void sll_clean(NODE *head) {
    while (head) {
        NODE *temp = head;
        head = head->next;
        free(temp);
    }
}
