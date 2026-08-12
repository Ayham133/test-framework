#include "../include/test.h"
#include "test_internal.h"
#include <stdbool.h>
#include <stdio.h>


/**
 * @brief   build the test.
 *
 * @param condition     the condition to be tested.
 * @param str           a string of the condition, used to print the message of the test itself when reporting.
 * @param file          the name of the file.
 * @param line          the line number.
 */
void test_assert_true(int condition, const char *str, const char *file, int line)
{
    #ifdef Debug
    printf("Running Assertion\n");
    #endif
    if(!condition)
    {
        printf("\tAssertation failed\n");
        printf("\tExpretion: %s\n", str);
        printf("\tFile: %s, at line: %d\n\n", file, line);
        set_current_test_status_to(false);
    }
}

/**
 * @brief   build the test. tests the condition if it is equal to the actual.
 *
 * @param condition             the condition to be tested.
 * @param condition_str         a string of the condition, used to print the message of the test itself when reporting.
 * @param actual_str            a string of the actual, used to print the message of the test itself when reporting.
 * @param file                  the name of the file.
 * @param line                  the line number.
 */
void test_assert_eq(int condition, int actual, const char *condition_str, const char *actual_str, const char *file, int line)
{
    #ifdef Debug
    printf("Running Assertion\n");
    #endif
    if(condition != actual)
    {
        printf("\tAssertation failed\n");
        printf("\tExpretion: %s\n", condition_str);
        printf("\tActual: %s\n", actual_str);
        printf("\tFile: %s, at line: %d\n\n", file, line);
        set_current_test_status_to(false);
    }
}

/**
 * @brief   assert the test and check if the pointer is null or not.
 *
 * @param pointer     the ginirc pointer to check if it is null or not.
 * @param str           a string of the condition, used to print the message of the test itself when reporting.
 * @param file          the name of the file.
 * @param line          the line number.
 */
void test_assert_null(void *pointer, const char *str, const char *file, int line)
{
    #ifdef Debug
    printf("Running Assertion\n");
    #endif
    if(pointer != NULL)
    {
        printf("\tAssertation failed\n");
        printf("\tExpretion: %s is not NULL, Expected to be NULL\n", str);
        printf("\tFile: %s, at line: %d\n\n", file, line);
        set_current_test_status_to(false);
    }
}

/**
 * @brief   assert the test and check if the pointer is NOT null or not.
 *
 * @param pointer     the ginirc pointer to check if it is NOT null or not.
 * @param str           a string of the condition, used to print the message of the test itself when reporting.
 * @param file          the name of the file.
 * @param line          the line number.
 */
void test_assert_not_null(void *pointer, const char *str, const char *file, int line)
{
    #ifdef Debug
    printf("Running Assertion\n");
    #endif
    if(pointer == NULL)
    {
        printf("\tAssertation failed\n");
        printf("\tExpretion: %s is NULL, Expected to be Not NULL\n", str);
        printf("\tFile: %s, at line: %d\n\n", file, line);
        set_current_test_status_to(false);
    }
}

/**
 * @brief   build the test.
 *
 * @param condition     the condition to be tested.
 * @param str           a string of the condition, used to print the message of the test itself when reporting.
 * @param file          the name of the file.
 * @param line          the line number.
 */
void test_assert_false(int condition, const char *str, const char *file, int line)
{
    #ifdef Debug
    printf("Running Assertion\n");
    #endif
    if(condition)
    {
        printf("\tAssertation failed\n");
        printf("\tExpretion: %s is True, Expected to be False.\n", str);
        printf("\tFile: %s, at line: %d\n\n", file, line);
        set_current_test_status_to(false);
    }
}

/**
 * @brief       build test, assertion an int equation test with the equation and the expected resutls.
 *
 * @param condition         the condition to test for.
 * @param condition_str     the stringfied version of the condition, used for output.
 * @param actual            the actual expected resutls for the equation.
 * @param actual_str        the stringfied version of the actual, used for output.
 * @param file              the name of the file.
 * @param line              the line number.
 *
 * @Note: this function will edit the status of the current_test variable in src/test_internal.c file.
 */
void test_assert_eq_int(int condition, const char *condition_str, int actual, const char *actual_str, const char *file, int line)
{
    #ifdef Debug
    printf("Running Assertion\n");
    #endif
    if (condition != actual) {
        printf("\tAssertation failed\n");
        printf("\t\t%s\n", condition_str);
        printf("\tActual:\n");
        printf("\t\t%s\n", actual_str);
        printf("\tFile: %s, at line: %d\n\n", file, line);
        set_current_test_status_to(false);
    }

}
