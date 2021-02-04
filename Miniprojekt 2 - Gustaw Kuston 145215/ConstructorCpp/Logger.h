#include <iostream>
#ifndef LOGGER_H
#define LOGGER_H

class Logger 
{
public:
    void log(std::string x);
    bool pr;
    Logger(bool debug = true);
};

#endif