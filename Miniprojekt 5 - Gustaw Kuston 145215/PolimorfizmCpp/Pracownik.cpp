#include <iostream>
#include <string>
#include <stdio.h>
#include "Osoba.h"
#include "Pracownik.h"

using namespace std;


void Pracownik::add_p(int i_p) {
    przedmioty[i_p] = new int(1);
}

void Pracownik::del_p(int i_p) {
    if (*przedmioty[i_p] == 1) {
        *przedmioty[i_p] = 0;
    }
    else {
        cout << "Pracownik nie prowadzi tego przedmiotu." << endl;
    }
}

void Pracownik::che_p(int i_p) {
    if (*przedmioty[i_p] == 1) {
        cout << "Tak." << endl;
    }
    else {
        cout << "Nie." << endl;
    }
}

void Pracownik::przedstaw() {
    this->get_iin();
    this->get_du();
    this->get_mz();
    cout << "Pracownik prowadzi przedmioty o indeksach: ";
    for (int i = 0; i < 20; i ++) {
        //cout << przedmioty[i] << ", " << *przedmioty[i] << endl;
        if (*przedmioty[i] == 1) {
        cout << i << " ";
        }
    }
    cout << endl;
}

Pracownik::Pracownik() {
    int tmp[20] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    for (int i = 0; i < 20; i++) {
        przedmioty[i] = &tmp[i];
    }
}

Pracownik::Pracownik(const Pracownik &n) {
    for (int i = 0; i < 20; i++){
        przedmioty[i] = new int(*n.przedmioty[i]);
    }
}

Pracownik::Pracownik(Pracownik&& n) {
    for (int i = 0; i < 20; i++){
        przedmioty[i] = n.przedmioty[i];
    }
    for (int i = 0; i < 20; i++){
        n.przedmioty[i] = nullptr;
    }
}

Pracownik::Pracownik(string iin, string du, string m, string u, string n) {
    set_iin(iin);
    set_du(du);
    set_mz(m, u, n);
    int tmp[20] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    for (int i = 0; i < 20; i++) {
        przedmioty[i] = &tmp[i];
    }
}

Pracownik::~Pracownik() {
}
