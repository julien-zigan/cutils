#include "listutils.h"
#include <stdio.h>
#include <stdlib.h>

LIST *new_list()
{
    LIST *list;
    if (list = (LIST *)malloc(sizeof(LIST))) {
        list->previous = list->next = list;
    }
    return list;
}
