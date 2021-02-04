#include <iostream>
#include <stdio.h>
#include <string>
#include "Student.h"
#include "FabrykaOsob.h"
#ifndef FABRYKASTUDENTOW_H
#define FABRYKASTUDENTOW_H

using namespace std;

class FabrykaStudentow : public FabrykaOsob {
    public:
    Student* utworz();
};

#endif
