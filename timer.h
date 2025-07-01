#include <time.h>
#pragma once

typedef struct  {
    clock_t start_time;
    clock_t end_time;
    double elapsed;
} Timer;

void startTimer(Timer *timer);
void endTimer(Timer *timer);