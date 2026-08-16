#ifndef TEST_INTERNAL_H
#define TEST_INTERNAL_H

#include "../include/test.h"
#include <stddef.h>

struct Test
{
    const char *name;
    char *suite;
    double time;
    TestFunction function;
    bool passed;
    bool disabled;
};

/**
 * @breif       init test pointer.
 */
Test *test_init(const char *name, const char *suit,  TestFunction function);

/**
 * @breif       set the current test pointer to the current test in the Registry.
 *
 * @param test      the pointer of the current test in the Registry.
 */
void set_current_test_to(Test *test);

/**
 * @breif       update the current_test status.
 *
 * @param status    the boolean to update.
 */
void set_current_test_status_to(bool status);

/**
 * @breif       update the current_test time.
 *
 * @param time_ms    time in ms.
 */
void set_current_test_execution_time_to(double time_ms);

/**
 * @breif       return the current_test status.
 */
bool get_current_test_stattus(void);

/**
 * @breif       get the name of the current test.
 *
 * @return [char *]     return the name of the current test.
 * @Note: if current test is NULL, the function will return NULL.
 */
char *get_current_test_name(void);

/**
 * @breif       get the suite of the current test.
 *
 * @return [char *]     return the suite of the current test.
 * @Note: if current test is NULL, the function will return NULL.
 */
char *get_current_test_suite();

/**
 * @breif       get the time in ms of the current test.
 *
 * @return [double]     return the time in ms of the current test.
 * @Note: if current test is NULL, the function will return 0.0
 */
double get_current_test_time(void);

/**
 * @breif       return the current_test pointer.
 *
 * @return      return the current_test pointer.
 */
Test *get_current_test(void);

void print_current_test(void);

#endif // !TEST_INTERNAL_H

