#include "reporter.h"
#include "registry.h"
#include "test_internal.h"
#include <stdio.h>


/**
 * @breif       print the starter message of the tests.
 */
void reporter_begin_test(void)
{
    printf(T_BLU "=============================================\n" T_RESET);
    printf("Running Tests\n");
    printf(T_BLU "=============================================\n" T_RESET);
}

/**
 * @breif       print the end message of the tests.
 */
void reporter_end_test(void)
{
    printf(T_BLU "=============================================\n" T_RESET);
    printf("End of Tests\n");
    printf(T_BLU "=============================================\n" T_RESET);
}

/**
 * @breif       print the running process of the test.
 *
 * @param test      a pointer to the test.
 */
void reporter_test_run()
{
    const char *name = get_current_test_name();
    const char *suite = get_current_test_suite();
    printf("[" T_YEL "RUN" T_RESET  "      ]"  "  %s [%s]\n", name, suite);
}

/**
 * @breif       print the report on the succeeded test.
 *
 */
void reporter_test_succeeded()
{
    const char *name = get_current_test_name();
    const double time_ms = get_current_test_time();
    printf("[     " T_GRN  "PASS" T_RESET "]"  "  %s (%.3f ms)\n\n", name, time_ms);
}

/**
 * @breif       print the report on the failed test.
 *
 * @param test      a pointer to the test.
 */
void reporter_test_failed(void)
{
    const char *name = get_current_test_name();
    printf("[     "     T_RED  "FAIL" T_RESET "]"  "  %s\n\n", name);
}

/**
 * @breif       prints the test summary, total test, number of passed tests, number of failed tests.
 */
void reporter_test_summary(void)
{
    printf(T_BLU "=============================================\n" T_RESET);
    printf("Total tests: " T_YEL"%d\n" T_RESET, register_count());
    printf("Passed: " T_GRN"%zu\n" T_RESET, registry_passed_tests());
    printf("Failed: " T_RED"%zu\n" T_RESET, registry_failed_tests());
    printf(T_BLU "=============================================\n" T_RESET);
}
