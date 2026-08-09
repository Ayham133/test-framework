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
int eq_int(int x, int y){return x * y + 2;}
TEST(Equation, Math)
{
    ASSERT_EQ_INT(eq_int(1, 5), 5);
}

int main(void)
{
    run_all_tests();
    return EXIT_SUCCESS;
}
