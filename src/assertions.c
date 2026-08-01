#include "../include/test.h"
#include <stdio.h>


/**
 * @brief   build the test.
 *
 * @param condition     the condition to be tested.
 * @param str           a string of the condition, used to print the message of the test itself when reporting.
 * @param file          the name of the file.
 * @param line          the line number.
 */
void test_assert(int condition, const char *str, const char *file, int line)
{
    if(!condition)
    {
        printf("Assertation failed!!\n");
        printf("Expretion: %s\n", str);
        printf("File: %s, at line: %d\n", file, line);
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
    if(condition != actual)
    {
        printf("Assertation failed!!\n");
        printf("Expretion: %s\n", condition_str);
        printf("Actual: %s\n", actual_str);
        printf("File: %s, at line: %d\n", file, line);
    }

}
