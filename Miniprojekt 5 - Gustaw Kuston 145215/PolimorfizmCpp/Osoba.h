#include <iostream>
#include <stdio.h>
#include <string>
#include "Adres.h"
#ifndef OSOBA_H
#define OSOBA_H

using namespace std;

class Osoba {
    private:
    string* imie_i_nazwisko;
    string* data_urodzenia; // data ma format DD.MM.YYYY
    Adres miejsce_zamieszkania;
    public:
    Osoba();
    Osoba(const Osoba &n);
    Osoba(Osoba&& n);
    Osoba(string iin, string du, string m, string u, string n);
    virtual ~Osoba();
    void set_iin(string x);
    void get_iin();
    void set_du(string x);
    void get_du();
    void set_mz(string m, string u, string n);
    void get_mz();
    virtual void przedstaw();
};

#endif
