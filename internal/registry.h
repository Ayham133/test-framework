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
 * @brief       increment passed tests counter in the Registry.
 */
void registry_inc_passed_tests(void);

/**
 * @brief       increment failed tests counter in the Registry.
 */
void registry_inc_failed_tests(void);

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
