#include <time.h>
#include "timer.h"

/* startTimer:     sets the start time of the current timer
    @param *timer: the timer to start
*/
void startTimer(Timer *timer)
{
    timer->start_time = clock();
}

/* endTimer:       ends the timer and calculates the elapsed time from the start time. Assumes the timer was started.
    @param *timer: the timer to end
*/
void endTimer(Timer *timer)
{
    timer->end_time = clock();
    timer->elapsed = (double) timer->end_time - timer->start_time;
}