#include "../include/test.h"
#include "../internal/registry.h"
#include "../internal/test_internal.h"
#include "../internal/reporter.h"


void update_current_test_and_report_status(Test *current)
{
    if(current == NULL)
        return;

    if(current->passed)
    {
        reporter_test_succeeded(current->name);
        registry_inc_passed_tests();
    }
    else{
        reporter_test_failed(current);
        registry_inc_failed_tests();
    }

}

/**
 * @brief       run all the tests in the registery. and report there status.
 *
 * @param [void]
 * @return [void]
 */
bool run_all_tests(void)
{
    if(registry_size() == 0)
        return false;

    for(size_t i = 0; i < registry_size(); i++)
    {
        Test current;

        // if the registry_get function failed.
        if(!register_get(i, &current))
            continue;

        set_current_test_to(&current);

        reporter_test_run(current.name);

        current.function();

        update_current_test_and_report_status(&current);
    }
    return true;
}
