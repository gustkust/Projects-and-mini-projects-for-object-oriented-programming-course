#include <iostream>
#include <string>
#include <stdio.h>
#include "Adres.h"

using namespace std;


void Adres::set_mun(string m, string u, string n) {
    miejscowosc = new string(m);
    ulica = new string(u);
    numer = new string(n);
}

void Adres::get_mun() {
    cout << *miejscowosc << ", " << *ulica << " " << *numer << endl;
}
