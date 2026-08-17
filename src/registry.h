#ifndef REGISTRY_H
#define REGISTRY_H

#include "../include/test.h"

typedef struct TestRegistry TestRegistry;

/**
 * @brief       returns the size of the Registry.
 */
size_t registry_size(void);

/**
 * @brief       return the number of passed tests in the Registry.
 */
size_t registry_passed_tests(void);

/**
 * @brief       return the number of failed tests in the Registry.
 */
size_t registry_failed_tests(void);

/**
 * @brief       return the number of disabled tests in the Registry.
 */
size_t registry_disabled_tests(void);

/**
 * @brief       increment passed tests counter in the Registry.
 */
void registry_inc_passed_tests(void);

/**
 * @brief       increment failed tests counter in the Registry.
 */
void registry_inc_failed_tests(void);

/**
 * @brief       increment disabled tests counter in the Registry.
 */
void registry_inc_disabled_tests(void);

/**
 *
 * @brief       check if the Registry is full or not.
 *
 * @return [bool]       return true if the Registry is full, false otherwise.
 */
static bool registry_is_full(void);

/**
 * @brief       check if the Registry.tests initialized or not.
 *
 * @return [bool]       return true if Registry.tests is initialized, false otherwise.
 */
static bool registry_is_initialized(void);

/**
 * @brief       resize the Registry capacity. double the capacity of Registry.
 *
 * @param [void]
 * @return [bool]   return true if the resizing is sucsessful, false otherwise.
 */
static bool registry_resize(void);

/**
 * @brief       returns the number of tests stored in the Registry.
 *
 * @param [void]
 * @return [int]    the number of tests in the Registry.
 */
int register_count(void);

/**
 * @brief       get a test in the Registry.tests.
 *
 * @param index         the index of the wanted test.
 * @param out_value     a pointer to the address where the tets is needed to be.
 * @return [bool]       return true if the test was found, false if the index was invalide.
 */
bool registry_get(const size_t index, Test *out_value);


/**
 * @brief       check if the Registry tests containes this suite.
 *
 * Loop through the Registry.tests and check
 * if one of the tests containes this suite.
 *
 * @param suite     the suite to search for.
 *
 * @Note: this function will return false if the
 * Registry is empty (aka doesn't have any tests)
 * or if this suite is either NULL or '\0'
 *
 * @return [bool]       return ture if Registry.tets
 *                      containes this suite, false otherwise
 */
bool registry_contains_suite(const char *suite);

/**
 * @brief       check if the Registry tests containes this suite group.
 *
 * Loop through the Registry.tests and check
 * if one of the tests containes this suite.
 *
 * @param group     the group to search for.
 *
 * @Note: this function will return false if the
 * Registry is empty (aka doesn't have any tests)
 * or if this suite is either NULL or empty
 *
 * @return [bool]       return ture if Registry.tets
 *                      containes this all the suite group, false otherwise
 */
bool registry_contains_suite_group(SuiteGroup *group);

/**
 * @brief               initiat the Registry with initial values like capacity to 20, size set to be zero, and allocate memory for tests.
 *
 * @param [void]
 * @return [bool]       return true if the initiation is sucsessful, false otherwise.
 */
static bool registry_init(void);

/**
 * @brief       report error messages to stderr stream.
 *
 * @param message       the error message to report.
 */
static void registry_error(const char *message);


#endif // !REGISTRY_H
