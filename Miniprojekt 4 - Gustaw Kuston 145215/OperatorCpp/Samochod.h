#include <iostream>
#include <string>
#include <stdio.h>
#ifndef SAMOCHOD_H
#define SAMOCHOD_H

using namespace std;

class Samochod {
private:
float pojemnosc_baku;
float poziom_paliwa;
unsigned int liczba_kilometrow;
string model;

public:
Samochod();
Samochod(float o_pojemnosc_baku, string o_model);
void przejechano_kilometry(int ile);
void zatankuj();
void ile_paliwa();
const odczytaj_pojemnosc_baku() const;

operator bool () const;
bool operator !() const;
friend ostream & operator << (ostream &os, const Samochod & samochod);
bool operator < (const Samochod &samochod) const;
void operator ++ (int);
float operator |= (Samochod const &por);
Samochod operator, (Samochod por);
} ;

#endif
