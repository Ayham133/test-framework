#include "../include/test.h"
#include <stdlib.h>


// Multiable Assertion in a single test,
// so you could have a daynamic testing enviroment.
TEST(equals, Math)
{
    ASSERT_TRUE(1 == 1);
    ASSERT_TRUE(1 == 1);
    ASSERT_FALSE(1 != 1);
    ASSERT_TRUE(1 == 1);
    ASSERT_TRUE(1 == 1);
}

TEST(null_test, Null)
{
    ASSERT_NULL(NULL);
}

int max(int a, int b){return (a > b)?a:b;}

TEST(eq_int, EQ)
{
    ASSERT_EQ_INT(max(2, 1), 1);
}


int main(void)
{
    filter_suite("EQ");
    run_all_tests();
    return EXIT_SUCCESS;
}
