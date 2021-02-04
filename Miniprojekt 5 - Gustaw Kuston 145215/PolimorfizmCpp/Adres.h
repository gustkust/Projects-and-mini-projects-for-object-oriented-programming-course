#include <iostream>
#include <stdio.h>
#include <string>
#ifndef ADRES_H
#define ADRES_H

using namespace std;


class Adres {
    private:
    string* miejscowosc;
    string* ulica;
    string* numer;

    public:
    void set_mun(string m, string u, string n);
    void get_mun();
};

#endif
