#include "../internal/reporter.h"
#include "../include/test.h"
#include "../internal/registry.h"
#include "../internal/test_internal.h"
#include <stdio.h>


/**
 * @breif       print the starter message of the tests.
 */
void reporter_begin_test(void)
{
    printf(T_BLU "=============================================\n" RESET);
    printf("Running Tests\n");
    printf(T_BLU "=============================================\n" RESET);
}

/**
 * @breif       print the end message of the tests.
 */
void reporter_end_test(void)
{
    printf(T_BLU "=============================================\n" RESET);
    printf("End of Tests\n");
    printf(T_BLU "=============================================\n" RESET);
}

/**
 * @breif       print the running process of the test.
 *
 * @param test      a pointer to the test.
 */
void reporter_test_run()
{
    const char *name = get_current_test()->name;
    printf("[" T_YEL "RUN" RESET "   ] %s\n", name);
}

/**
 * @breif       print the report on the succeeded test.
 *
 * @param name      the name of the test.
 */
void reporter_test_succeeded()
{
    const char *name = get_current_test()->name;
    printf("[" T_GRN "OK" RESET "   ] %s\n", name);
}

/**
 * @breif       prints the test summary, total test, number of passed tests, number of failed tests.
 */
void reporter_test_summary(void)
{
    printf(T_BLU "=============================================\n" RESET);
    printf("Total tests: " RESET T_YEL"%d\n", register_count());
    printf("Passed: " T_GRN"%zu\n" RESET, registry_passed_tests());
    printf("Failed: " T_RED"%zu\n" RESET, registry_failed_tests());
    printf(T_BLU "=============================================\n" RESET);
}
