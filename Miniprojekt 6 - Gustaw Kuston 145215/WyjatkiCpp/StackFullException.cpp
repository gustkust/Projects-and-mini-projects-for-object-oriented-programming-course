#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include "StackFullException.h"

using namespace std;


StackFullException::StackFullException() {}

StackFullException::StackFullException(string p, int e, int s) {
    element = e;
    maxStackSize = s;
    message = p;
}

const char* StackFullException::what() const noexcept {
    string tmp1 = to_string(maxStackSize);
    string tmp2 = to_string(element);
    string tmp3 = "Za duzo elementów. Maksymalna ilość elementów to " + tmp1 + ", a dodawany element to " + tmp2;
    const char* r = tmp3.c_str();
    return r;
}