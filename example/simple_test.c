#include "../include/test.h"
#include <stdlib.h>


TEST(equals, Math)
{
    ASSERT_TRUE(1 == 1);
}

TEST(subtraction, Math)
{
    ASSERT_EQ( 1 - 1, 0);
}

TEST(Condition, Math)
{
    ASSERT_FALSE(1 == 2);
}

TEST(NullPointer, Pointer)
{
    char *name = NULL;
    ASSERT_NULL(name);
}

TEST(NotNullPointer, Pointer)
{
    char *name = "name";
    ASSERT_NOT_NULL(name);
}


int main(void)
{
    disable("NullPointer");
    filter_suite("Pointer");
    run_all_tests();
    return EXIT_SUCCESS;
}
