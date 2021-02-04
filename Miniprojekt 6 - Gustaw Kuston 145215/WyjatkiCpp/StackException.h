#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#ifndef STACKEXCEPTION_H
#define STACKEXCEPTION_H

using namespace std;


class StackException : public exception {
    public:
    StackException();
    virtual const char* what() const noexcept override;
};

#endif
