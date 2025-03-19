#include "listutils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define STRBUFSZ 255
#define GREEN "\e[0;32m"
#define WHT "\e[0;37m"
#define RED "\e[0;31m"
#define YELLOW "\e[0;33m"

void NODETestForStringInput(int *tests, int *passed, int *failed)
{
    (*tests)++;
    printf("Test %i: NODETestForStringInput\t\t", *tests);
    
    NODE node;
    char *data;
    data = (char *)malloc(STRBUFSZ);
    assert(data && "Memory alloction failed");
    strcpy(data, "Expected result");
    
    node.data = (void *)data;
    
    if(strcmp(data, (char *)node.data) != 0) {
        printf(RED"failed"WHT"\n");
        (*failed)++;
        return; 
    }

    (*passed)++;
    printf(GREEN"passed"WHT"\n");
    free(data);
}

void NODETestForNumericalInput(int *tests, int *passed, int *failed)
{
    (*tests)++;
    printf("Test %i: NODETestForNumericalInput\t", *tests);
    
    NODE node;
    double *data;
    data = (double *)malloc(sizeof(double));
    assert(data && "Memory alloction failed");
    *data = 47.11; 
    node.data = (void *)data;
    
    if(*(double *)node.data != *data) {
        printf(RED"failed"WHT"\n");
        (*failed)++;
        return; 
    }

    (*passed)++;
    printf(GREEN"passed"WHT"\n");
    free(data);
}

void new_listTest(int *tests, int *passed, int *failed)
{
    (*tests)++;
    printf("Test %i: new_listTest\t\t\t", *tests);
    
    LIST *list;
    list = new_list();
    
    if(list->next != list || list->previous != list) {
        printf(RED"failed"WHT"\n");
        (*failed)++;
        return; 
    }

    (*passed)++;
    printf(GREEN"passed"WHT"\n");
    free(list);
}

int main(void)
{
    int tests, passed, failed;
    tests = passed = failed = 0;
    puts("");
    printf(YELLOW"Running Tests...\n"WHT"\n");

    NODETestForStringInput(&tests, &passed, &failed);
    NODETestForNumericalInput(&tests, &passed, &failed);
    new_listTest(&tests, &passed, &failed);
    puts("");
    printf(YELLOW"Tests run: %i, "GREEN"passed: %i, "RED"failed: %i"WHT, tests, passed, failed);
    puts("\n");
    return EXIT_SUCCESS;
}
