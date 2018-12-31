#ifndef TIMER_H
#define TIMER_H

#include <ctime>

class Timer
{
public:
    Timer();
    void reset();
    double elapsed();
private:
    timespec beg_, end_;
};

#endif // TIMER_H
