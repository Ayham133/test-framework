#include "../internal/reporter.h"
#include <stdio.h>


/**
 * @breif       print the starter message of the tests.
 */
void reporter_begin_test(void)
{
    printf("========================================\n");
    printf("Running Tests\n");
    printf("========================================\n");
}

/**
 * @breif       print the end message of the tests.
 */
void reporter_end_test(void)
{
    printf("========================================\n");
    printf("End of Tests\n");
    printf("========================================\n");
}

/**
 * @breif       print the running process of the test.
 *
 * @param test      a pointer to the test.
 */
void reporter_test_run(const char *name)
{
       printf("[" T_YEL "RUN" RESET "   ] %s\n", name);
}

/**
 * @breif       print the report on the succeeded test.
 *
 * @param name      the name of the test.
 */
void reporter_test_succeeded(const char *name)
{
       printf("[" T_GRN "OK" RESET "   ] %s\n", name);
}
