#include "listutils.h"
#include <stdio.h>
#include <stdlib.h>

LIST *new_list()
{
    LIST *list;
    if (list = (LIST *)malloc(sizeof(LIST))) {
        list->previous = list->next = list;
        list->data = NULL;
    }
    return list;
}

int insert(LIST *list, void *value)
{
    if (list == NULL) {
        fprintf(stderr, "NULL passed as list\n");
        return -1;
    }
    NODE *node;
    if((node = (NODE *)malloc(sizeof(NODE))) == NULL) {
        fprintf(stderr, "Memory allocation failed \n");
        return -2;
    }
    node->previous = list;
    node->next = list->next;
    node->data = value;
    list->next = node;

    return 1;
}
