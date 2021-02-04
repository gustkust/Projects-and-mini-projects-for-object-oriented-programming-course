#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include "StackException.h"
#ifndef STACKFULLEXCEPTION_H
#define STACKFULLEXCEPTION_H

using namespace std;


class StackFullException : public StackException {
    int element = 0;
    int maxStackSize = 0;
    string message;
    public:
    StackFullException();
    StackFullException(string p, int e, int s);
    virtual const char* what() const noexcept override;
};

#endif
