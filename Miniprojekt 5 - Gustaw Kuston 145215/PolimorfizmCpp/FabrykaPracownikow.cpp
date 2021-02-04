#include <iostream>
#include <string>
#include <stdio.h>
#include "Osoba.h"
#include "FabrykaPracownikow.h"

using namespace std;

Pracownik* FabrykaPracownikow::utworz() {
    string i;
    string in;
    string du;
    string m;
    string u;
    string n;
    cout << "Podaj imie:" << endl;
    cin >> i;
    cout << "Podaj nazwisko:" << endl;
    cin >> in;
    cout << "Podaj date urodzenia" << endl;
    cin >> du;
    cout << "Podaj miejscowosc:" << endl;
    cin >> m;
    cout << "Podaj ulice:" << endl;
    cin >> u;
    cout << "Podaj numer:" << endl;
    cin >> n;
    string iin;
    iin = i + " " + in;
    Pracownik* tmp = new Pracownik(iin, du, m, u, n);
    return tmp;
}
