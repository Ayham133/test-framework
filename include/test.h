#ifndef TEST_H
#define TEST_H

#include <stdbool.h>
#include <stddef.h>

#define TEST(name)                          \
        void test_##name(void);             \
                                            \
        static void register_##name(void)   \
        __attribute__((constructor));       \
                                            \
        static void register_##name(void)   \
        {                                   \
            register_test(test_##name, #name);     \
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



typedef void (*TestFunction)(void);

typedef struct Test Test;

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
 */
void register_test(void(*function)(void), const char *name);

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
bool register_get(const size_t index, Test *out_value);

/**
 * @brief       run all the tests in the registery. and report there status.
 *
 * @param [void]
 * @return [void]
 */
bool run_all_tests(void);

#endif // !TEST_H
