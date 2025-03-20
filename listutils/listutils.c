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

static int impl_delete(NODE *node)
{
    node->previous->next = node->next;
    node->next->previous = node->previous;
    free(node);
    return 1;
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

int append(LIST *list, void *value)
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
    
    node->data = value;
    node->previous = list->previous;
    node->next = list;
    list->previous->next = node;
    list->previous = node;

    return 1;
}

    
NODE *search(LIST *list, void *value, char *type) 
{
    if (list == NULL) {
        fprintf(stderr, "NULL passed as list\n");
        return NULL;
    }
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


int delete(LIST *list, void *value, char *type) 
{
    if (list == NULL) {
        fprintf(stderr, "NULL passed as list\n");
        return -1;
    }
    NODE *iterator = list->next;
    while (iterator && (iterator != list)) {
        if(strcmp(type, "i") == 0) { 
            if(*(int *)iterator->data == *(int *)value) {
                impl_delete(iterator);
                return 1;
            }
        }
        if(strcmp(type, "l") == 0) {
            if(*(long *)iterator->data == *(long *)value) {
                impl_delete(iterator); return 1;
            }
        }
        if(strcmp(type, "f") == 0) {
            if(*(float *)iterator->data == *(float *)value) {
                impl_delete(iterator); return 1;
            }
        }
        if(strcmp(type, "d") == 0) {
            if(*(double *)iterator->data == *(double *)value) {
                impl_delete(iterator); return 1;
            }
        }
        if(strcmp(type, "s") == 0) {
            if((strcmp((char *)iterator->data, (char *)value)) == 0) {
                impl_delete(iterator); return 1;
            }
        }
        else {
            printf("Invalid type\n");
            return -1;
        }
        iterator = iterator->next;
    }
    return -1;
}

void print_list(LIST *list)
{
    if (list == NULL) {
        fprintf(stderr, "NULL passed as list\n");
        return;
    }
    NODE *iterator = list->next;
    int i = 0;
    while (iterator != list) {
        printf("%i. %s\n", ++i, iterator->data);
        iterator = iterator->next; 
    } 
}
