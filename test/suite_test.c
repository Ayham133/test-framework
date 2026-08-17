#include <stdlib.h>
#include <string.h>
#include "../include/test.h"
#include "../src/suite.h"

TEST(suite_group_init_not_null, Suitegroup)
{
    SuiteGroup *group = suite_group_init();

    ASSERT_EQ_INT(suite_group_size(group), 0);
    ASSERT_NOT_NULL(group);
}

TEST(suite_group_add, Suitegroup)
{
    SuiteGroup *group = suite_group_init();

    suite_group_add(group, "Math");

    ASSERT_EQ_INT(suite_group_size(group), 1);

    Suite *current;
    ASSERT_TRUE(suite_group_get(group, 0, current));

    ASSERT_NOT_NULL(current);
    ASSERT_TRUE(strcpy(suite_get_name(current), "Math") == 0);
}

TEST(suite_group_add_null, Suitegroup)
{
    SuiteGroup *group = suite_group_init();

    ASSERT_FALSE(suite_group_add(group, NULL));
    ASSERT_EQ_INT(suite_group_size(group), 0);
}

TEST(suite_group_add_to_null_group, Suitegroup)
{
    SuiteGroup *group = NULL;
    ASSERT_FALSE(suite_group_add(group, NULL));
}

int main(void)
{
    run_all_tests();
    return EXIT_SUCCESS;
}
