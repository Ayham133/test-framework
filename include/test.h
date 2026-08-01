#ifndef TEST_H
#define TEST_H

#define TEST(name)  \
        void test_##name(void)

#define ASSERT_TRUE(condition)  \
    test_assert((condition), #condition, __FILE__, __LINE__);

#define ASSERT_EQ(condition, actual)    \
    test_assert_eq((condition), (actual), #condition, #actual, __FILE__, __LINE__);

/**
 * @brief   build the test.
 *
 * @param condition     the condition to be tested.
 * @param str           a string of the condition, used to print the message of the test itself when reporting.
 * @param file          the name of the file.
 * @param line          the line number.
 */
void test_assert(int condition, char *str, char *file, int line);

/**
 * @brief   build the test. tests the condition if it is equal to the actual.
 *
 * @param condition             the condition to be tested.
 * @param condition_str         a string of the condition, used to print the message of the test itself when reporting.
 * @param actual_str            a string of the actual, used to print the message of the test itself when reporting.
 * @param file                  the name of the file.
 * @param line                  the line number.
 */
void test_assert_eq(int condition, int actual, char *condition_str, char *actual_str, char *file, int line);

#endif // !TEST_H
