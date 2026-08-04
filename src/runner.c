#include "../include/test.h"
#include "registry.h"
#include "test_internal.h"
#include "reporter.h"


void update_current_test_and_report_status()
{

    if(get_current_test_stattus())
    {
        reporter_test_succeeded();
        registry_inc_passed_tests();
    }
    else{
        reporter_test_failed();
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
    
    reporter_begin_test();
    for(size_t i = 0; i < registry_size(); i++)
    {
        Test current;

        // if the registry_get function failed.
        if(!register_get(i, &current))
            continue;

        set_current_test_to(&current);

        reporter_test_run();

        current.function();

        update_current_test_and_report_status();
    }

    reporter_test_summary();
    return true;
}
