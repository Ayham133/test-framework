#include "../include/test.h"
#include <stdlib.h>


TEST(Math)
{
    ASSERT_TRUE(1 == 1);
}

TEST(Sub)
{
    ASSERT_EQ( 1 - 1, 0);
}

TEST(Condition)
{
    ASSERT_FALSE(1 == 2);
}

TEST(NullPointer)
{
    char *name = NULL;
    ASSERT_NULL(name);
}

TEST(NotNullPointer)
{
    char *name = "name";
    ASSERT_NOT_NULL(name);
}

int main(void)
{
    run_all_tests();
    return EXIT_SUCCESS;
}
