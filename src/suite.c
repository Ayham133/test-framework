/**
 * @file: suite.c
 *
 * @brief   this file contains all the implementation code for suites and SuiteGroup.
 *
 * Date: 08/13/2026
 */

#include "../include/test.h"
#include "suite.h"
#include <stdlib.h>
#include <string.h>

typedef struct Suite
{
    char *name;
}Suite;

/**
 * @brief       initiate suite
 *
 * Allocate memory for the suite struct.
 *
 * @param name      the name of the suite
 *
 * @return      return the pointer for the new suite
 *
 * @Note: this function will return NULL if the allocation failed,
 * or if the string name is NULL or '\0'.
 */
Suite *suite_init(const char *name)
{
    if(name == NULL || name[0] == '\0')
        return NULL;

    Suite *new_suite = malloc(sizeof(Suite));

    if(new_suite == NULL)
        return  NULL;

    new_suite->name = malloc(strlen(name) + 1);
    strcpy(new_suite->name, name);

    return new_suite;
}

/**
 * @brief       get the name of the requeseted suite.
 *
 * @param suite         pointer to the requeseted suite
 *
 * @return              return the name of the requeseted suite.
 * @Note: this function will return NULL if the suite is Null,
 */
char *suite_get_name(Suite *suite)
{
    if(suite == NULL)
        return NULL;

    return suite->name;
}

typedef struct SuiteGroup
{
    Suite *suites;
    size_t capacity;
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
    if(new_suite_group == NULL)
        return NULL;

    new_suite_group->capacity = 10;
    new_suite_group->number_of_suites = 0;
    new_suite_group->suites = malloc(sizeof(Suite) * new_suite_group->capacity);

    return new_suite_group;
}

/**
 * @brife       check if this suite_group is full or not.
 *
 * @return [bool]   return true if this suite group is full, false otherwise.
 *
 * @Note: this function will return false if this suite_group is Null, or 
 * any other errors.
 */
bool suite_group_is_full(SuiteGroup *suite_group)
{
    return suite_group->number_of_suites == suite_group->capacity;
}

/**
 * @brife       check if this suite_group is empty or not.
 *
 * @return [bool]   return true if this suite group is empty, false otherwise.
 *
 * @Note: this function will return false if this suite_group is Null, or 
 * any other errors.
 */
bool suite_group_is_empty(SuiteGroup *suite_group){return suite_group->number_of_suites == 0;}

/**
 * @brife       get the requeseted suite from this suite_group list
 *
 * After authenticating the index and this suite_group list, return the
 * suite at the requeseted index
 *
 * @param suite_group       this suite_group requeseted
 * @param index             the index requeseted
 * @param out_value         the place where the requeseted suite will be stored
 *
 * @return [bool]           return true if there were no errors, false otherwise.
 *
 * @Note: this function will return false, if this suite_group is null or empyt,
 * and this function will returh false if the index is out of bound, and if the
 * out_value is null
 */
Suite *suite_group_get(const SuiteGroup *group, size_t index)
{
    if (group == NULL || index >= group->number_of_suites)
        return NULL;

    return &group->suites[index];
}

/**
 * @brief       add a new suite to this suite_group
 *
 * allcoate memory for a new Suite and if the suite_group
 * is full, resize it and then add the new suite.
 *
 * @param suite_group       the list to add to.
 * @param suite             the name of the suite that will be added.
 *
 * @return [bool]           return ture if the adding process successeded
 *                          false otherwise.
 *
 * @Note: this function will return false if this suite_group is null or empyt,
 * or if the suite string is null or '\0', and this function will return false
 * for any other errors.
 */
bool suite_group_add(SuiteGroup *suite_group, const char *suite)
{
    if(suite_group == NULL || suite == NULL || suite[0] == '\0')
        return false;

    Suite *new_suite = suite_init(suite);

    if(suite_group_is_empty(suite_group))
    {
        suite_group->suites[0] = *new_suite;
        suite_group->number_of_suites++;
        return true;
    }
    unsigned size = suite_group->number_of_suites;
    suite_group->suites[size] = *new_suite;
    suite_group->number_of_suites++;
    return true;
}

/**
 * @brief       get the size of the requeseted group
 *
 * @param group     the requeseted group
 * @return          return the size of the requeseted group.
 *
 * @Note: this function will return zero if the group is NULL,
 * or empty.
 */
unsigned suite_group_size(SuiteGroup *group)
{
    if(group == NULL)
        return 0;

    return group->number_of_suites;
}
