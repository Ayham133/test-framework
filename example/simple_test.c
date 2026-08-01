#include "../include/test.h"
#include <stdio.h>
#include <stdlib.h>


TEST(Math)
{

    ASSERT_EQ(1 == 2, 1 != 2);
}

int main(void)
{

    printf("Testing\n");
    register_test(test_Math, "test_Math");

    return EXIT_SUCCESS;
}
