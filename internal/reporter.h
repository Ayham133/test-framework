#ifndef REPORTER_H
#define REPORTER_H

// Regular text
#define BLK "\033[0;30m"
#define _RED "\033[0;31m"
#define GRN "\033[0;32m"
#define YEL "\033[0;33m"
#define BLU "\033[0;34m"
#define MAG "\033[0;35m"
#define CYN "\033[0;36m"
#define WHT "\033[0;37m"

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
 * @param test      a pointer to the test.
 */
void reporter_test_run(Test test);

/**
 * @breif       print the report on the failed test.
 *
 * @param test      a pointer to the test.
 */
void reporter_test_failed(struct Test *test);

/**
 * @breif       print the report on the succeeded test.
 *
 * @param test      a pointer to the test.
 */
void reporter_test_succeeded(struct Test *test);

#endif // !REPORTER_H
