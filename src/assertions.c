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
void test_assert(int condition, char *str, char *file, int line)
{
    if(!condition)
    {
        printf("Assertation failed!!\n");
        printf("Expretion: %s\n", str);
        printf("File: %s, at line: %d\n", file, line);
    }

}
