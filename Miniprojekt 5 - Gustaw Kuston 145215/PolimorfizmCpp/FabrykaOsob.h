#include <iostream>
#include <stdio.h>
#include <string>
#include "Osoba.h"
#ifndef FABRYKAOSOB_H
#define FABRYKAOSOB_H

using namespace std;

class FabrykaOsob {
    public:
    virtual Osoba* utworz() = 0;
};

#endif
