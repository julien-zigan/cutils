#ifndef __LISUTILS_H__
#define __LISUTILS_H__

typedef struct node{
    struct node *previous;
    struct node *next;
    void *data;
} NODE;

typedef NODE LIST;

extern LIST *new_list();
extern int insert(LIST *list, void *value);

#endif
