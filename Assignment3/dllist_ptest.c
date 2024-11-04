//
// Created by georg on 2024-11-04.
//
#include "dllist.h"
#include <stdio.h>

void display_dll_forward(DLLIST *list) {
    NODE *current = list->head;
    printf("length %d forward ", list->length);
    while (current) {
        printf("%c ", current->data);
        current = current->next;
    }
    printf("\n");
}

void display_dll_backward(DLLIST *list) {
    NODE *current = list->tail;
    printf("length %d backward ", list->length);
    while (current) {
        printf("%c ", current->data);
        current = current->prev;
    }
    printf("\n");
}

int main() {
    DLLIST list = {NULL, NULL, 0};

    printf("Test: dll_insert_start\n");
    dll_insert_start(&list, 'A');
    display_dll_forward(&list);
    dll_insert_start(&list, 'B');
    display_dll_forward(&list);
    dll_insert_start(&list, 'C');
    display_dll_forward(&list);
    dll_insert_start(&list, 'D');
    display_dll_forward(&list);

    printf("\nTest: dll_insert_end\n");
    DLLIST list2 = {NULL, NULL, 0};
    dll_insert_end(&list2, 'A');
    display_dll_forward(&list2);
    dll_insert_end(&list2, 'B');
    display_dll_forward(&list2);
    dll_insert_end(&list2, 'C');
    display_dll_forward(&list2);
    dll_insert_end(&list2, 'D');
    display_dll_forward(&list2);
    display_dll_backward(&list2);

    printf("\nTest: dll_delete_start\n");
    dll_delete_start(&list);
    display_dll_forward(&list);
    dll_delete_start(&list);
    display_dll_forward(&list);
    dll_delete_start(&list);
    display_dll_forward(&list);
    dll_delete_start(&list);
    display_dll_forward(&list);

    printf("\nTest: dll_delete_end\n");
    dll_delete_end(&list2);
    display_dll_forward(&list2);
    dll_delete_end(&list2);
    display_dll_forward(&list2);
    dll_delete_end(&list2);
    display_dll_forward(&list2);
    dll_delete_end(&list2);
    display_dll_forward(&list2);

    return 0;
}
