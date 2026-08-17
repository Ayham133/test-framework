/**
 *
 * @file: filter.c
 *
 * This File handles filtring suits, disabling, and enabling tests.
 *
 *
 * @Date: 08/12/2026
 * @Author: Ayham Atallah.
 */


#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/test.h"
#include "suite.h"
#include "registry.h"
#include "reporter.h"
#include "test_internal.h"


/**
 * @brief       filters specific test suite in the registery.
 *
 * Loop through the registery and make any test with different suite than
 * this specific suite, disabled.
 *
 * @example: if the user filter_suite(Math),
 * then any other test with different suite will be disabled.
 *
 * @param suite     the specific suite to filter for
 *
 * @Note: the function will return if the registery is
 * empty(aka, doesn't containe any tests) or this specific
 * suite wasn't found in the registery.
 */
void filter_suite(const char *suite)
{
    if(registry_size() == 0 || suite == NULL || suite[0] == '\0')
        return;

    if(!registry_contains_suite(suite))
    {
        reporter_no_suites_were_found(suite);
        return;
    }

    Test current;
    for(int i = 0; i < registry_size(); i++)
    {
        if(!registry_get(i, &current))
            continue;

        if(strcmp(suite_get_name(current.suite), suite) != 0)// isn't the same
        {
            disable(current.name);
        }
    }
}

/**
 * @brief Filters the registry to tests belonging to a specific suite group.
 *
 * Iterates through all registered tests and disables any test whose suite
 * does not belong to the specified suite group.
 *
 * @example
 * If the user calls filter_suite_group(group1), where group1 contains
 * {"Math", "Pointers"}, only tests belonging to the "Math" or "Pointers"
 * suites will remain enabled.
 *
 * @param group The suite group to filter the registry by.
 *
 * @note The function returns without making changes if the registry is empty
 *       or if the specified suite group does not exist in the registry.
 */
void filter_suite_group(SuiteGroup *group)
{
    if (group == NULL || registry_size() == 0)
        return;

    if (!registry_contains_suite_group(group))
    {
        reporter_no_suites_group_were_found();
        return;
    }

    for (size_t j = 0; j < registry_size(); j++)
    {
        Test current;

        if (!registry_get(j, &current))
            continue;

        int found = 0;

        for (size_t i = 0; i < suite_group_size(group); i++)
        {
            Suite *suite = suite_group_get(group, i);

            if (suite == NULL)
                continue;

            if (strcmp(suite_get_name(current.suite),
                       suite_get_name(suite)) == 0)
            {
                found = 1;
                break;
            }
        }

        if (!found)
            disable(current.name);
    }
}


