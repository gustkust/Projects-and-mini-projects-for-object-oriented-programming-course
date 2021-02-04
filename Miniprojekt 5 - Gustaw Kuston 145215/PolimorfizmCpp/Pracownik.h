#include <iostream>
#include <stdio.h>
#include <string>
#include "Adres.h"
#ifndef PRACOWNIK_H
#define PRACOWNIK_H

using namespace std;

class Pracownik : public Osoba {
    public:
    Pracownik();
    Pracownik(const Pracownik &n);
    Pracownik(Pracownik&& n);
    Pracownik(string iin, string du, string m, string u, string n);
    ~Pracownik();
    int *przedmioty[20];
    void add_p(int i_p);
    void del_p(int i_p);
    void che_p(int i_p);
    void przedstaw();
};

#endif
