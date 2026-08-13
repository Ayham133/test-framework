/**
 * @file: suite.c
 *
 * @brief   this file contains all the implementation code for suites and SuiteGroup.
 *
 * Date: 08/13/2026
 */

#include "../include/test.h"
#include <stdlib.h>

typedef struct Suite
{
    char *name;
}Suite;

typedef struct SuiteGroup
{
    Suite *suites;
    size_t number_of_suites;
}SuiteGroup;

/**
 *
 * @brief       initiate a suite group.
 *
 * Allocating new memory for a suite group.
 *
 * @param [void]
 * @return      return the pointer for the new SuiteGroup.
 *
 * @Note:
 */
SuiteGroup *suite_group_init()
{
    SuiteGroup *new_suite_group = malloc(sizeof(SuiteGroup));

    new_suite_group->number_of_suites = 0;
    
}
