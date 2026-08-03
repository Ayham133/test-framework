#ifndef REPORTER_H
#define REPORTER_H

// Regular text
#define T_BLK "\033[0;30m"
#define T_RED "\033[0;31m"
#define T_GRN "\033[0;32m"
#define T_YEL "\033[0;33m"
#define T_BLU "\033[0;34m"
#define T_MAG "\033[0;35m"
#define T_CYN "\033[0;36m"
#define T_WHT "\033[0;37m"

// Reset
#define RESET "\033[0m"

#include "../include/test.h"

/**
 * @breif       print the starter message of the tests.
 */
void reporter_begin_test(void);

/**
 * @breif       print the end message of the tests.
 */
void reporter_end_test(void);

/**
 * @breif       print the running process of the test.
 *
 * @param name      the name of the test.
 */
void reporter_test_run(const char *name);

/**
 * @breif       print the report on the failed test.
 *
 * @param test      a pointer to the test.
 */
void reporter_test_failed(struct Test *test);

/**
 * @breif       print the report on the succeeded test.
 *
 * @param name      the name of the test.
 */
void reporter_test_succeeded(const char *name);

#endif // !REPORTER_H
