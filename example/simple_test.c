#include "../include/test.h"
#include <stdio.h>
#include <stdlib.h>


TEST(Math)
{
    ASSERT_EQ(1 != 2, 1 == 2);
}

TEST(Sub)
{
    ASSERT_EQ( 1 - 1, 0);
}

int main(void)
{

    printf("Testing\n");
    run_all_tests();

    return EXIT_SUCCESS;
}
