#include "../include/test.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "test_internal.h"



typedef  struct
{
    Test *tests;
    size_t size;
    size_t capacity;
    size_t failed;
    size_t passed;
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
 * @brief       get a test in the Registry.tests.
 *
 * @param index         the index of the wanted test.
 * @param out_value     a pointer to the address where the tets is needed to be.
 * @return [bool]       return true if the test was found, false if the index was invalide.
 */
bool register_get(const size_t index, Test *out_value)
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
void register_test(const char *name, const char *suit, TestFunction function)
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

    Test *new_test = test_init(name, suit, function);
    Registry.tests[Registry.size] = *new_test;
    Registry.size++;
}


