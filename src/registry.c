#include "../include/test.h"
#include <stddef.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "test_internal.h"
#include "suite.h"


typedef  struct
{
    Test *tests;
    size_t size;
    size_t capacity;
    size_t failed;
    size_t passed;
    size_t disabled;
}TestRegistry;


static TestRegistry Registry;

/**
 * @brief       returns the size of the Registry.
 */
size_t registry_size(void)
{
    return Registry.size;
}

/**
 * @brief       return the number of passed tests in the Registry.
 */
size_t registry_passed_tests(void)
{
    return Registry.passed;
}

/**
 * @brief       return the number of failed tests in the Registry.
 */
size_t registry_failed_tests(void)
{
    return Registry.failed;
}

/**
 * @brief       return the number of disabled tests in the Registry.
 */
size_t registry_disabled_tests(void)
{
    return Registry.disabled;
}

/**
 * @brief       increment passed tests counter in the Registry.
 */
void registry_inc_passed_tests(void)
{
    Registry.passed++;
}

/**
 * @brief       increment failed tests counter in the Registry.
 */
void registry_inc_failed_tests(void)
{
    Registry.failed++;
}
/**
 * @brief       increment disabled tests counter in the Registry.
 */
void registry_inc_disabled_tests(void)
{
    Registry.disabled++;
}

/**
 * @brief       get a test in the Registry.tests.
 *
 * @param index         the index of the wanted test.
 * @param out_value     a pointer to the address where the tets is needed to be.
 * @return [bool]       return true if the test was found, false if the index was invalide.
 */
bool registry_get(const size_t index, Test *out_value)
{
    if(index > Registry.size)
        return false;

    *out_value = Registry.tests[index];
    return true;
}


/**
 * @brief       returns the number of tests stored in the Registry.
 *
 * @param [void]
 * @return [int]    the number of tests in the Registry.
 */
int register_count(void)
{
    if (Registry.tests == NULL || Registry.size == 0)
        return 0;

    return Registry.size;
}

/**
 *
 * @brief       check if the Registry is full or not.
 *
 * @return [bool]       return true if the Registry is full, false otherwise.
 */
static bool registry_is_full(void)
{
    return Registry.capacity == Registry.size;
}

/**
 * @brief       check if the Registry.tests initialized or not.
 *
 * @return [bool]       return true if Registry.tests is initialized, false otherwise.
 */
static bool registry_is_initialized(void)
{
    return Registry.tests != NULL;
}

/**
 * @brief       resize the Registry capacity. double the capacity of Registry.
 *
 * @param [void]
 * @return [bool]   return true if the resizing is sucsessful, false otherwise.
 */
static bool registry_resize(void)
{
    size_t newCapacity = Registry.capacity * 2;
    Test *newTests = realloc(Registry.tests, newCapacity *sizeof(Test));

    if(newTests == NULL)
        return false;

    Registry.capacity = newCapacity;
    Registry.tests = newTests;
    return true;
}

/**
 * @brief               initiat the Registry with initial values like capacity to 20, size set to be zero, and allocate memory for tests.
 *
 * @param [void]
 * @return [bool]       return true if the initiation is sucsessful, false otherwise.
 */
static bool registry_init(void)
{

    Registry.capacity = 20;
    Registry.size = 0;

    Registry.tests = malloc(sizeof(Test) * Registry.capacity);


    if (!registry_is_initialized())
    {
        return false;
    }

    return true;
}

/**
 * @brief       report error messages to stderr stream.
 *
 * @param message       the error message to report.
 */
static void registry_error(const char *message)
{
    fprintf(stderr, "Registry Error: %s\n", message);
}

/**
 * @brief       register tests to the test registery.
 *
 * @param   function        a pointer to the test function.
 * @param   name            a string that containes the name of the function.
 * @param   suit            the suit of the test.
 */
void register_test(const char *name, const char *suite, TestFunction function)
{
    if(!registry_is_initialized())
    {
        if(!registry_init())
        {
            registry_error("Failed to initialize registry.");
            return;
        }
    }

    if(registry_is_full())
    {
        if(!registry_resize())
        {
            registry_error("Failed to resize registry.");
            return;
        }
    }

    Test *new_test = test_init(name, suite, function);
    Registry.tests[Registry.size] = *new_test;
    Registry.size++;
}

/**
 * @brief       check if the Registry tests containes this suite.
 *
 * Loop through the Registry.tests and check
 * if one of the tests containes this suite.
 *
 * @param suite     the suite to search for.
 *
 * @Note: this function will return false if the
 * Registry is empty (aka doesn't have any tests)
 * or if this suite is either NULL or '\0'
 *
 * @return [bool]       return ture if Registry.tets
 *                      containes this suite, false otherwise
 */
bool registry_contains_suite(const char *suite)
{
    if(registry_size() == 0 || suite == NULL || suite[0] == '\0')
        return false;
    
    for (int i = 0; i < Registry.size; i++) {
        if(strcmp(suite_get_name(Registry.tests[i].suite), suite) == 0)// is the same
            return true;
    }

    return false;// the Registry.tets doesn't containe this suite.
}

/**
 * @brief       allows the user to disable a test by its name.
 * 
 * Loop throw the registery and make the
 * boolean value of disabled to true.
 *
 * @param name      the name of the test to be disabled.
 *
 * @Note: the function will return if the registery is
 * empty or the registery does not containe the name of
 * the test.
 */
void disable(const char *name)
{
    if (registry_size() == 0 || name == NULL || name[0] == '\0')
        return;

    for (int i = 0; i < Registry.size; i++) {
        if (strcmp(Registry.tests[i].name, name) == 0) {
            Registry.tests[i].disabled = true;
            return;
        }
    }
}

/**
 * @brief       allows the user to enable a disabled test.
 *
 * Loop throw the registery and make the
 * boolean value of disabled to false.
 *
 * @param name  the name of the disabled test to be enabled.
 *
 * @Note: the function will return if the registery is
 * NULL or the registery does not containe the name of
 * the test.
 */
void enable(const char *name)
{
    if (registry_size() == 0 || name == NULL || name[0] == '\0')
        return;

    for(int i = 0; i < Registry.size; i++)
    {
        if(strcmp(Registry.tests[i].name, name) == 0)
        {
            Registry.tests[i].disabled = false;
            return;
        }
    }
}

/**
 * @brief       check if the Registry tests containes this suite group.
 *
 * Loop through the Registry.tests and check
 * if one of the tests containes this suite.
 *
 * @param group     the group to search for.
 *
 * @Note: this function will return false if the
 * Registry is empty (aka doesn't have any tests)
 * or if this suite is either NULL or empty
 *
 * @return [bool]       return ture if Registry.tets
 *                      containes this all the suite group, false otherwise
 */
bool registry_contains_suite_group(SuiteGroup *group)
{
    if(registry_size() == 0 || group == NULL)
        return false;

    Test *current;
    Suite *suite;
    for (int j = 0; j < suite_group_size(group); j++) {

        if(!suite_group_get(group, j, suite))
            continue;

        if(!registry_contains_suite(suite_get_name(suite)))
            return false;
    }

    return true;
}
