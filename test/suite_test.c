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

    Suite *current = suite_group_get(group, 0 );

    ASSERT_NOT_NULL(current);
    ASSERT_TRUE(strcpy(suite_get_name(current), "Math") != 0);
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

TEST(str_eq, String)
{
    ASSERT_TRUE(true);
}

TEST(subtract, Math)
{
    ASSERT_EQ_INT(1-1, 0);
}


int main(void)
{
    SuiteGroup *group = suite_group_init();
    suite_group_add(group, "Suitegroup");
    suite_group_add(group, "Math");

    filter_suite_group(group);
    run_all_tests();
    return EXIT_SUCCESS;
}
