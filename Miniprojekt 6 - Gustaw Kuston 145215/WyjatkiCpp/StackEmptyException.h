#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include "StackException.h"
#ifndef STACKEMPTYEXCEPTION_H
#define STACKEMPTYEXCEPTION_H

using namespace std;


class StackEmptyException : public StackException {
    string message;
    public:
    StackEmptyException();
    StackEmptyException(string p);
    virtual const char* what() const noexcept override;
};

#endif
