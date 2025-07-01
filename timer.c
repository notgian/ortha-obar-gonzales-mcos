#include <time.h>

typedef struct  {
    clock_t start_time;
    clock_t end_time;
    double elapsed;
} Timer;

void startTimer(Timer *timer)
{
    timer->start_time = clock();
}

void endTimer(Timer *timer)
{
    timer->end_time = clock();
    timer->elapsed = (double) timer->end_time - timer->start_time;
}