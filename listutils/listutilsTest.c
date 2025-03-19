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

int tests = 0;
int passed = 0;
int failed = 0;

void begin_tests()
{
    puts("");
    printf(YELLOW"Running Tests...\n"WHT"\n");
}

void end_tests()
{
    puts("");
    printf(YELLOW"Tests run: %i, "GREEN"passed: %i, "RED"failed: %i"WHT, tests, passed, failed);
    puts("\n");
}

void setup_test(const char *function_name) 
{
    tests++;
    printf("Test %i: %30s\t", tests, function_name);
}

void pass()
{
    passed++;
    printf(GREEN"passed"WHT"\n");
}

void fail()
{
    failed++;
    printf(RED"failed"WHT"\n");
}

void NODETestForStringInput()
{
    setup_test(__FUNCTION__);
    NODE node;
    char *data;
    data = (char *)malloc(STRBUFSZ);
    assert(data && "Memory alloction failed");
    strcpy(data, "Expected result");
    
    node.data = (void *)data;
    
    if(strcmp(data, (char *)node.data) != 0) {
        fail();
        return; 
    }
    pass();
    free(data);
}

void NODETestForNumericalInput()
{
    setup_test(__FUNCTION__);
    NODE node;
    double *data;
    data = (double *)malloc(sizeof(double));
    assert(data && "Memory alloction failed");
    *data = 47.11; 
    
    node.data = (void *)data;
    
    if(*(double *)node.data != *data) {
        fail();
        return; 
    }
    pass();
    free(data);
}

void new_listTest()
{
    setup_test(__FUNCTION__);
    LIST *list;

    list = new_list();
    
    if(list->next != list || list->previous != list) {
        fail();
        return; 
    }
    pass();
    free(list);
}

void insertTest()
{
    setup_test(__FUNCTION__);

    LIST *list = new_list();

    int i;
    for (i = 0; i < 10; i++) {
        char *data = (char *)malloc(STRBUFSZ);
        assert(data && "Memory alloction failed");
        sprintf(data, "Test Data %i", i);
        insert(list, (void *)data);
    }
    
    NODE *iterator = list->next;
    while(iterator != list) {
        char cmpdata[12];
        sprintf(cmpdata, "Test Data %i", --i);
        if (strcmp(iterator->data, cmpdata) != 0) {
            fail();
            return;
        }
        iterator = iterator->next;
    }
    
    pass();
    //TODO: free
}

int main(void)
{
    begin_tests();

    NODETestForStringInput();
    NODETestForNumericalInput();
    new_listTest();
    insertTest();
    
    end_tests();
    return EXIT_SUCCESS;
}
