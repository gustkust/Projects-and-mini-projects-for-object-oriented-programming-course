#include <iostream>
#include <stdio.h>
#include <string>
#include "Adres.h"
#include "Osoba.h"
#ifndef STUDENT_H
#define STUDENT_H

using namespace std;

class Student : public Osoba {
    private:
    int *oceny[20];
    public:
    Student();
    Student(const Student &n);
    Student(Student&& n);
    Student(string iin, string du, string m, string u, string n);
    ~Student();
    void set_o(int i_przedmiotu, int ocena);
    void get_o(int i_przedmiotu);
    void get_wo();
    void przedstaw();
};

#endif
