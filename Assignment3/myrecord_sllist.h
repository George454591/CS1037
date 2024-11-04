#ifndef MYRECORD_SLLIST_H
#define MYRECORD_SLLIST_H

#define NAMELEN 20

typedef struct {
    char name[NAMELEN];
    float score;
} RECORD;

typedef struct node {
    RECORD record;
    struct node *next;
} NODE;

NODE *sll_insert(NODE *head, const char *name, float score);
NODE *sll_search(NODE *head, const char *name);
NODE *sll_delete(NODE *head, const char *name);
void sll_clean(NODE *head);

#endif // MYRECORD_SLLIST_H
