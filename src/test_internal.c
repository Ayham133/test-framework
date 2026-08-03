#include "../internal/test_internal.h"
#include <stdlib.h>

static Test *current_test;

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

/**
 * @breif       set the current test pointer to the current test in the Registry.
 *
 * @param test      the pointer of the current test in the Registry.
 */
void set_current_test_to(Test *test)
{
    if(test == NULL)
        return;

    current_test = test;
}

/**
 * @breif       return the current_test pointer.
 *
 * @return      return the current_test pointer.
 */
Test *get_current_test(void)
{
    return current_test;
}
