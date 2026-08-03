#include "../internal/test_internal.h"
#include <stdlib.h>

/**
 * @breif       init test pointer.
 */
Test *test_init(const char *name,  TestFunction function)
{
    if(function == NULL)
        return NULL;

    Test *new_test = malloc(sizeof(Test));

    new_test->name = name;
    new_test->function = function;
    new_test->passed = true;

    return new_test;
}
