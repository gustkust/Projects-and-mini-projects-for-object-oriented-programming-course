#include <iostream>
#include <string>
#include <stdio.h>
#include "Samochod.h"

using namespace std;

Samochod::Samochod() {
    pojemnosc_baku = 30;
    poziom_paliwa = 28;
    liczba_kilometrow = 1000;
    model = "Clio";
}

Samochod::Samochod(float o_pojemnosc_baku, string o_model) {
    pojemnosc_baku = o_pojemnosc_baku;
    poziom_paliwa = 28;
    liczba_kilometrow = 1000;
    model = o_model;
}

void Samochod::przejechano_kilometry(int ile = 1) {
    liczba_kilometrow += ile;
    poziom_paliwa -= ile/10;
}

void Samochod::zatankuj() {
    poziom_paliwa = pojemnosc_baku;
}

void Samochod::ile_paliwa() {
    cout << poziom_paliwa << endl;
}

const Samochod::odczytaj_pojemnosc_baku() const {
    return pojemnosc_baku;
}

Samochod::operator bool () const {
    if (poziom_paliwa > 0 && model != "") {
        return true;
    }
    return false;
}

bool Samochod::operator !() const {
    if (poziom_paliwa > 0 && model != "") {
        return true;
    }
    return false;
}

ostream & operator << (ostream &os, const Samochod & samochod) {
    os << samochod.model << " " << samochod.poziom_paliwa << "\n";
    return os;
}

bool Samochod::operator < (const Samochod &samochod) const {
    return this->model < samochod.model;
}

void Samochod::operator ++ (int) {
    liczba_kilometrow++;
}

float Samochod::operator |= (Samochod const &por) {
    if (pojemnosc_baku > por.pojemnosc_baku) {
        return pojemnosc_baku;
    }
    return por.pojemnosc_baku;
}

Samochod Samochod::operator, (Samochod por) {
    Samochod tmp;
    tmp.liczba_kilometrow = por.liczba_kilometrow;
    tmp.poziom_paliwa = poziom_paliwa;
    return tmp;
}
