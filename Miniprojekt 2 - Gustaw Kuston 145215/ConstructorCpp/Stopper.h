#include <iostream>
#ifndef STOPPER_H
#define STOPPER_H

class Stopper
{
public:
    time_t beginning;
    time_t ending;
    time_t cur = 0;
    void start();
    void stop();
    void reset();
    void w_time();
};

#endif