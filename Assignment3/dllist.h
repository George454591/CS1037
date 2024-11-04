#ifndef DLLIST_H
#define DLLIST_H

typedef struct node {
    char data;
    struct node *next;
    struct node *prev;
} NODE;

typedef struct {
    NODE *head;
    NODE *tail;
    int length;
} DLLIST;

NODE *new_node(char value);
void dll_insert_start(DLLIST *list, char value);
void dll_insert_end(DLLIST *list, char value);
void dll_delete_start(DLLIST *list);
void dll_delete_end(DLLIST *list);
void dll_clean(DLLIST *list);

#endif // DLLIST_H
