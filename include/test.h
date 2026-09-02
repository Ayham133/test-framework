#ifndef TEST_H
#define TEST_H

#include <stdbool.h>
#include <stddef.h>

#define TEST(name, suite)                    \
        void test_##name(void);             \
                                            \
        static void register_##name(void)   \
        __attribute__((constructor));       \
                                            \
        static void register_##name(void)   \
        {                                   \
            register_test(#name, #suite, test_##name); \
        }                                   \
                                            \
        void test_##name(void)


#define REGISTER_TEST(name) \
    register_test(name, #name);

#define ASSERT_TRUE(condition)  \
    test_assert_true((condition), #condition, __FILE__, __LINE__);

#define ASSERT_FALSE(condition) \
    test_assert_false((condition), #condition, __FILE__, __LINE__);

#define ASSERT_NULL(pointer)    \
    test_assert_null((pointer), #pointer, __FILE__, __LINE__);

#define ASSERT_NOT_NULL(pointer)   \
    test_assert_not_null((pointer), #pointer, __FILE__, __LINE__);

#define ASSERT_EQ_INT(condition, actual)  \
    test_assert_eq_int((condition), #condition, actual, #actual, __FILE__, __LINE__);


typedef void (*TestFunction)(void);

typedef struct Test Test;

typedef struct SuiteGroup SuiteGroup;

/**
 * @brief       build test, assertion an int equation test with the equation and the expected resutls.
 *
 * @param condition         the condition to test for.
 * @param condition_str     the stringfied version of the condition, used for output.
 * @param actual            the actual expected resutls for the equation.
 * @param actual_str        the stringfied version of the actual, used for output.
 * @param file              the name of the file.
 * @param line              the line number.
 *
 * @Note: this function will edit the status of the current_test variable in src/test_internal.c file.
 */
void test_assert_eq_int(int condition, const char *condition_str, int actual, const char *actual_str, const char *file, int line);

/**
 * @brief   build the test.
 *
 * @param condition     the condition to be tested.
 * @param str           a string of the condition, used to print the message of the test itself when reporting.
 * @param file          the name of the file.
 * @param line          the line number.
 */
void test_assert_true(int condition, const char *str, const char *file, int line);

/**
 * @brief   build the test.
 *
 * @param condition     the condition to be tested.
 * @param str           a string of the condition, used to print the message of the test itself when reporting.
 * @param file          the name of the file.
 * @param line          the line number.
 */
void test_assert_false(int condition, const char *str, const char *file, int line);
/**
 * @brief   build the test. tests the condition if it is equal to the actual.
 *
 * @param condition             the condition to be tested.
 * @param condition_str         a string of the condition, used to print the message of the test itself when reporting.
 * @param actual_str            a string of the actual, used to print the message of the test itself when reporting.
 * @param file                  the name of the file.
 * @param line                  the line number.
 */
void test_assert_eq(int condition, int actual, const char *condition_str, const char *actual_str, const char *file, int line);

/**
 * @brief   assert the test and check if the pointer is null or not.
 *
 * @param pointer     the ginirc pointer to check if it is null or not.
 * @param str           a string of the condition, used to print the message of the test itself when reporting.
 * @param file          the name of the file.
 * @param line          the line number.
 */
void test_assert_null(void *pointer, const char *str, const char *file, int line);

/**
 * @brief   assert the test and check if the pointer is NOT null or not.
 *
 * @param pointer     the ginirc pointer to check if it is NOT null or not.
 * @param str           a string of the condition, used to print the message of the test itself when reporting.
 * @param file          the name of the file.
 * @param line          the line number.
 */
void test_assert_not_null(void *pointer, const char *str, const char *file, int line);

/**
 * @brief       register tests to the test registery.
 *
 * @param   function        a pointer to the test function.
 * @param   name            a string that containes the name of the function.
 * @param   suit            the suit of the test.
 */
void register_test(const char *name, const char *suit, void(*function)(void));

/**
 * @brief       allows the user to disable a test by its name.
 * 
 * Loop through the registery and make the
 * boolean value of disabled to true.
 *
 * @param name      the name of the test to be disabled.
 *
 * @Note: the function will return if the registery is
 * NULL or the registery does not containe the name of
 * the test.
 */
void disable(const char *name);

/**
 * @brief       allows the user to enable a disabled test.
 *
 * Loop through the registery and make the
 * boolean value of disabled to false.
 *
 * @param name  the name of the disabled test to be enabled.
 *
 * @Note: the function will return if the registery is
 * NULL or the registery does not containe the name of
 * the test.
 */
void enable(const char *name);

/**
 * @brief       filters specific test suite in the registery.
 *
 * Loop through the registery and make any test with different suite than
 * this specific suit, disabled.
 *
 * @example: if the user filter_suite(Math),
 * then the runner will only run the tests with a suite "Math"
 *
 * @param suite     the specific suite to filter for
 *
 * @Note: the function will return if the registery is
 * empty(aka, doesn't containe any tests) or this specific
 * wasn't found in the registery.
 */
void filter_suite(const char *suite);

/**
 * @brief       filters specific suite group in the registery.
 *
 * Loop through the registery and make any test with different suite than
 * any of the suites in this group disabled.
 *
 * @example: if the user filter_suite_group(group1),
 * and group1 = {"Math", "Pointers"}, then the runner
 * will only run the tests with a suite "Math" and "Pointers"
 *
 * @param group     the group to filter by
 *
 * @Note: the function will return if the registery is
 * empty(aka, doesn't containe any tests) or this specific
 * suite group wasn't found in the registery.
 */
void filter_suite_group(SuiteGroup *group);

/**
 * @brief       filters specific test suite in the registery.
 *
 * Loop through the registery and make any test with different suite than
 * this specific suite, disabled.
 *
 * @example: if the user filter_suite(Math),
 * then any other test with different suite will be disabled.
 *
 * @param suite     the specific suite to filter for
 *
 * @Note: the function will return if the registery is
 * empty(aka, doesn't containe any tests) or this specific
 * suite wasn't found in the registery.
 */
void filter_suite(const char *suite);

/**
 *
 * @brief       initiate a suite group.
 *
 * Allocating new memory for a suite group.
 *
 * @param [void]
 * @return      return the pointer for the new SuiteGroup.
 *
 * @Note:
 */
SuiteGroup *suite_group_init();

/**
 * @brief       add a new suite to this suite_group
 *
 * allcoate memory for a new Suite and if the suite_group
 * is full, resize it and then add the new suite.
 *
 * @param suite_group       the list to add to.
 * @param suite             the name of the suite that will be added.
 *
 * @return [bool]           return ture if the adding process successeded
 *                          false otherwise.
 *
 * @Note: this function will return false if this suite_group is null or empyt,
 * or if the suite string is null or '\0', and this function will return false
 * for any other errors.
 */
bool suite_group_add(SuiteGroup *suite_group, const char *suite);

/**
 * @brief       run all the tests in the registery. and report there status.
 *
 * @param [void]
 * @return [void]
 */
bool run_all_tests(void);

#endif // !TEST_H
