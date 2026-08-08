/**
 * @file: timer.c
 *
 * The implementation file of timer.h
 *
 * Date: 08/08/2026
 */


#include "timer.h"
#include <stdbool.h>
#include <time.h>

static clock_t start, end;
static bool is_timer_running = false;

/**
 * @brief       Start the cpu clock.
 */
void timer_start(void)
{
    if(is_timer_running)return;

    start = clock();
    is_timer_running = true;
}

/**
 * @brief       end the cpu clock and calculate the time (in ms) between start and end.
 *
 * @return [double]      return the time in ms.
 */
double timer_end(void)
{
    if(!is_timer_running)return 0.0;

    end = clock();
    is_timer_running = false;
    double time_ms = ((double) (end - start) * 1000.0) / CLOCKS_PER_SEC;

    return time_ms;
}
