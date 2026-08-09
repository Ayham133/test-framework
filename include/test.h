#ifndef TEST_H
#define TEST_H

#include <stdbool.h>
#include <stddef.h>

#define TEST(name, suit)                    \
        void test_##name(void);             \
                                            \
        static void register_##name(void)   \
        __attribute__((constructor));       \
                                            \
        static void register_##name(void)   \
        {                                   \
            register_test(#name, #suit, test_##name); \
        }                                   \
                                            \
        void test_##name(void)


#define REGISTER_TEST(name) \
    register_test(name, #name);

#define ASSERT_TRUE(condition)  \
    test_assert((condition), #condition, __FILE__, __LINE__);

#define ASSERT_FALSE(condition) \
    test_assert_false((condition), #condition, __FILE__, __LINE__);

#define ASSERT_EQ(condition, actual)    \
    test_assert_eq((condition), (actual), #condition, #actual, __FILE__, __LINE__);

#define ASSERT_NULL(pointer)    \
    test_assert_null((pointer), #pointer, __FILE__, __LINE__);

#define ASSERT_NOT_NULL(pointer)   \
    test_assert_not_null((pointer), #pointer, __FILE__, __LINE__);

#define ASSERT_EQ_INT(condition, actual)  \
    test_assert_eq_int((condition), #condition, actual, #actual, __FILE__, __LINE__);


typedef void (*TestFunction)(void);

typedef struct Test Test;

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
void test_assert(int condition, const char *str, const char *file, int line);

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
 * Loop throw the registery and make the
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
 * Loop throw the registery and make the
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
 * @brief       run all the tests in the registery. and report there status.
 *
 * @param [void]
 * @return [void]
 */
bool run_all_tests(void);

#endif // !TEST_H
