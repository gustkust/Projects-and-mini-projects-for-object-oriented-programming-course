#include <iostream>
#include <string>
#include <stdio.h>
#include "Osoba.h"
#include "Adres.h"

using namespace std;


void Osoba::set_iin(string x) {
    imie_i_nazwisko = new string(x);
}

void Osoba::get_iin() {
    cout << *imie_i_nazwisko << endl;
}

void Osoba::set_du(string x) {
    if (x[2] != '.' || x[5] != '.') {
        cout << "Zly format daty." << endl;
    }
    data_urodzenia = new string(x);
}

void Osoba::get_du() {
    cout << *data_urodzenia << endl;
}

void Osoba::set_mz(string m, string u, string n) {
    this->miejsce_zamieszkania.set_mun(m, u, n);
}

void Osoba::get_mz() {
    this->miejsce_zamieszkania.get_mun();
}

void Osoba::przedstaw() {
    cout << *imie_i_nazwisko << endl << *data_urodzenia << endl;
    this->miejsce_zamieszkania.get_mun();
}

Osoba::Osoba()
: imie_i_nazwisko(nullptr), data_urodzenia(nullptr)
{
}

Osoba::Osoba(const Osoba &n) {
    imie_i_nazwisko = new string(*n.imie_i_nazwisko);
    data_urodzenia = new string(*n.data_urodzenia);
}

Osoba::Osoba(Osoba&& n) {
    imie_i_nazwisko = n.imie_i_nazwisko;
    data_urodzenia = n.data_urodzenia;

    n.imie_i_nazwisko = nullptr;
    n.data_urodzenia = nullptr;
}

Osoba::Osoba(string iin, string du, string m, string u, string n) {
    set_iin(iin);
    set_du(du);
    set_mz(m, u, n);
}

Osoba::~Osoba() {
    if (imie_i_nazwisko != nullptr) delete imie_i_nazwisko;
    if (data_urodzenia != nullptr) delete data_urodzenia;
}