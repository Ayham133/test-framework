#include "../include/test.h"
#include <stdlib.h>


// Multiable Assertion in a single test,
// so you could have a daynamic testing enviroment.
TEST(equals, Math)
{
    ASSERT_TRUE(1 == 1);
    ASSERT_TRUE(1 == 1);
    ASSERT_TRUE(1 != 1); // false assert
    ASSERT_FALSE(1 != 1);
    ASSERT_TRUE(1 == 1);
    ASSERT_TRUE(1 == 1);
}

TEST(null_test, Null)
{
    ASSERT_NULL(NULL);
}


int main(void)
{
    filter_suite("Null");
    run_all_tests();
    return EXIT_SUCCESS;
}
