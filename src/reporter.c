#include "../internal/reporter.h"
#include "../include/test.h"
#include "../internal/test_internal.h"
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
void reporter_test_run(Test test)
{
       printf("[" YEL "RUN" RESET "   ] %s\n", test.name);
}
