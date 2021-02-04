#include <iostream>
#include <stdio.h>
#include <string>
#include "Pracownik.h"
#include "FabrykaOsob.h"
#ifndef FABRYKAPRACOWNIKOW_H
#define FABRYKAPRACOWNIKOW_H

using namespace std;

class FabrykaPracownikow : public FabrykaOsob {
    public:
    Pracownik* utworz();
};

#endif
