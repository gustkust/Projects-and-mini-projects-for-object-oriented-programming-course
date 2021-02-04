#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include "StackEmptyException.h"

using namespace std;


StackEmptyException::StackEmptyException() {}

StackEmptyException::StackEmptyException(string p) {
    message = p;
}

const char* StackEmptyException::what() const noexcept {
    return "Juz nie ma elementow.";
}
