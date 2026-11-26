/**
 * @file: timer.h
 *
 * The job of this headder file is to be a clock timer for the runner.c file.
 *
 * Date: 08/08/2026
 */

#ifndef TIMER_H
#define TIMER_H

#include <time.h>
#include <stdbool.h>


/**
 * @brief       Start the cpu clock.
 */
void timer_start(void);

/**
 * @brief       end the cpu clock and calculate the time (in ms) between start and end.
 *
 * @return [double]      return the time in ms.
 */
double timer_end(void);

#endif // !TIMER_H
