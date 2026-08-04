#ifndef TEST_INTERNAL_H
#define TEST_INTERNAL_H

#include "../include/test.h"
#include <stddef.h>

struct Test
{
    const char *name;
    TestFunction function;
    bool passed;
};

/**
 * @breif       init test pointer.
 */
Test *test_init(const char *name,  TestFunction function);

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
 * @breif       return the current_test status.
 */
bool get_current_test_stattus(void);

/**
 * @breif       return the current_test pointer.
 *
 * @return      return the current_test pointer.
 */
Test *get_current_test(void);

void print_current_test(void);

#endif // !TEST_INTERNAL_H

