#include "Stopper.h"
#include <iostream>
#include <ctime>

void Stopper::start() {
    beginning = time(0);
}
void Stopper::stop() {
    ending = time(0);
    cur = cur + ending - beginning;
}
void Stopper::reset() {
    beginning = 0;
    cur = 0;
}
void Stopper::w_time() {
    std::cout << cur << std::endl;
}

