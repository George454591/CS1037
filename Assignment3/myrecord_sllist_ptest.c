//
// Created by georg on 2024-11-04.
//
#include "myrecord_sllist.h"
#include <stdio.h>

void display_sll(NODE *head) {
    NODE *current = head;
    printf("length %d ", head ? 1 : 0);
    while (current) {
        printf("%s %.1f ", current->record.name, current->record.score);
        current = current->next;
    }
    printf("\n");
}

int main() {
    NODE *head = NULL;
    printf("Test: sll_insert\n");
    head = sll_insert(head, "A9", 90.0);
    display_sll(head);
    head = sll_insert(head, "A8", 80.0);
    display_sll(head);
    head = sll_insert(head, "A7", 70.0);
    display_sll(head);
    head = sll_insert(head, "A6", 60.0);
    display_sll(head);

    printf("\nTest: sll_search\n");
    printf("sll_search(A8): %s\n", sll_search(head, "A8") ? "Found" : "Not Found");
    printf("sll_search(A5): %s\n", sll_search(head, "A5") ? "Found" : "Not Found");

    printf("\nTest: sll_delete\n");
    head = sll_delete(head, "A8");
    display_sll(head);
    head = sll_delete(head, "A9");
    display_sll(head);

    sll_clean(head);
    return 0;
}
