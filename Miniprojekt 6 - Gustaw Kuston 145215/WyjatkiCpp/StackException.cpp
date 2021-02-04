#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include "StackException.h"

using namespace std;


const char* StackException::what() const noexcept {
        return "Bledna operacja na stosie!";
    }

StackException::StackException() {}
