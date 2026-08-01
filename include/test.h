#ifndef TEST_H
#define TEST_H

#define TEST(name)  \
        void test_##name(void)

#define REGISTER_TEST(name) \
    register_test(name, #name);

#define ASSERT_TRUE(condition)  \
    test_assert((condition), #condition, __FILE__, __LINE__);

#define ASSERT_EQ(condition, actual)    \
    test_assert_eq((condition), (actual), #condition, #actual, __FILE__, __LINE__);



typedef void (*TestFunction)(void);


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
 * @brief       register tests to the test registery.
 *
 * @param   function        a pointer to the test function.
 * @param   name            a string that containes the name of the function.
 */
void register_test(void(*function)(void), const char *name);

/**
 * @brief       run all the tests in the registery. and report there status.
 *
 * @param [void]
 * @return [void]
 */
void run_all_tests(void);

#endif // !TEST_H
