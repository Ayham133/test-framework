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
 * @brief       filters specific suite group in the registery.
 *
 * Loop through the registery and make any test with different suite than
 * any of the suites in this group disabled.
 *
 * @example: if the user filter_suite_group(group1),
 * and group1 = {"Math", "Pointers"}, then the runner
 * will only run the tests with a suite "Math" and "Pointers"
 *
 * @param group     the group to filter by
 *
 * @Note: the function will return if the registery is
 * empty(aka, doesn't containe any tests) or this specific
 * suite group wasn't found in the registery.
 */
void filter_suite_group(SuiteGroup *group)
{
    if(group == NULL || registry_size() == 0)
        return;

    if(!registry_contains_suite_group(group))
    {
        reporter_no_suites_group_were_found();
        return;
    }

    char *suite_name;
    Suite *current_suite;
    for (int i = 0; i < suite_group_size(group); i++) {

        if(!suite_group_get(group, i, current_suite))
            continue;

        suite_name = suite_get_name(current_suite);


        Test current;
        for(int i = 0; i < registry_size(); i++)
        {
            if(!registry_get(i, &current))
                continue;

            if(strcmp(suite_get_name(current.suite), suite_name) != 0)// isn't the same
            {
                disable(current.name);
            }
        }
    }

}
