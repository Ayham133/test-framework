#include "test_internal.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static Test *current_test;

/**
 * @breif       init test pointer.
 */
Test *test_init(const char *name, const char *suit,  TestFunction function)
{
    if(function == NULL)
        return NULL;

    Test *new_test = malloc(sizeof(Test));

    new_test->name = name;
    new_test->suite = strdup(suit);
    new_test->function = function;
    new_test->passed = true;
    new_test->disabled = false;

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
 * @breif       update the current_test time.
 *
 * @param time_ms    time in ms.
 */
void set_current_test_execution_time_to(double time_ms)
{
    if(time_ms < 0.0){
        current_test->time = 0.0;
        return;
    }

    current_test->time = time_ms;
}

/**
 * @breif       update the current_test status.
 *
 * @param status    the boolean to update.
 */
void set_current_test_status_to(bool status)
{
    current_test->passed = status;
}

/**
 * @breif       return the current_test status.
 */
bool get_current_test_stattus(void)
{
    return current_test->passed;
}

/**
 * @breif       get the name of the current test.
 *
 * @return [char *]     return the name of the current test.
 * @Note: if current test is NULL, the function will return NULL.
 */
char *get_current_test_name(void)
{
    if(current_test == NULL)
        return NULL;

    char *temp = strdup(current_test->name);
    return temp;
}

/**
 * @breif       get the suite of the current test.
 *
 * @return [char *]     return the suite of the current test.
 * @Note: if current test is NULL, the function will return NULL.
 */
char *get_current_test_suite()
{
    if(current_test == NULL)
        return NULL;

    char *temp = current_test->suite;
    return temp;
}

/**
 * @breif       get the time in ms of the current test.
 *
 * @return [double]     return the time in ms of the current test.
 * @Note: if current test is NULL, the function will return 0.0
 */
double get_current_test_time(void)
{
    if(current_test == NULL)
        return 0.0;

    return current_test->time;
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

void print_current_test(void)
{
    printf("name: %s\n: ", current_test->name);
    printf("disabled: %b\n", current_test->disabled);
}
