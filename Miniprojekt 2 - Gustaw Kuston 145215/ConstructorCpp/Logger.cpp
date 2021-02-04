#include "Logger.h"
#include <iostream>
#include <ctime>

void Logger::log(std::string x) {
time_t now = time(0);
char* ct = ctime(&now);
std::cout << ct << std::endl;
if (pr != false) {
    std::cout << x << std::endl;
}
}

Logger::Logger(bool debug) {
    pr = debug;
}
