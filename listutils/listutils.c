#include "listutils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

NODE *search(LIST *list, void *value, char *type) 
{
    NODE *iterator = list->next;
    while (iterator && (iterator != list)) {
        if(strcmp(type, "i") == 0) { 
            if(*(int *)iterator->data == *(int *)value) {
                return iterator;
            }
        }
        if(strcmp(type, "l") == 0) {
            if(*(long *)iterator->data == *(long *)value) {
                return iterator;
            }
        }
        if(strcmp(type, "f") == 0) {
            if(*(float *)iterator->data == *(float *)value) {
                return iterator;
            }
        }
        if(strcmp(type, "d") == 0) {
            if(*(double *)iterator->data == *(double *)value) {
                return iterator;
            }
        }
        if(strcmp(type, "s") == 0) {
            if((strcmp((char *)iterator->data, (char *)value)) == 0) {
                return iterator;
            }
        }
        else {
            printf("Invalid type\n");
            return NULL;
        }
        iterator = iterator->next;
    }
    return NULL;
}
