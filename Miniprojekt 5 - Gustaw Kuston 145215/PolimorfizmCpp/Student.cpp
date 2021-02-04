#include <iostream>
#include <string>
#include <stdio.h>
#include "Osoba.h"
#include "Student.h"

using namespace std;


void Student::set_o(int i_przedmiotu, int ocena) {
    if (ocena < 1 || ocena > 5) {
        cout << "Zla ocena." << endl;
    }
    else {
        *oceny[i_przedmiotu] = ocena;
    }
}

void Student::get_o(int i_przedmiotu) {
    if (*oceny[i_przedmiotu] > 0 && *oceny[i_przedmiotu] < 6) {
        cout << *oceny[i_przedmiotu] << endl;
    }
    else {
        cout << "Nie ma oceny z tego przedmiotu." << endl;
    }
}

void Student::get_wo() {
    for (int i = 0; i < 20; i++) {
        if (*oceny[i] < 0 && *oceny[i] > 5) {
            cout << "Ocena z przedmiotu o indeksie " << i << ": " << *oceny[i] << endl;
        }
    }
}

void Student::przedstaw() {
    this->get_iin();
    this->get_du();
    this->get_mz();
    this->get_wo();
}

Student::Student() {
    int tmp[20] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    for (int i = 0; i < 20; i++) {
        oceny[i] = &tmp[i];
    }
}

Student::Student(const Student &n) {
    for (int i = 0; i < 20; i++){
        oceny[i] = new int(*n.oceny[i]);
    }
}

Student::Student(Student&& n) {
    for (int i = 0; i < 20; i++){
        oceny[i] = n.oceny[i];
    }
    for (int i = 0; i < 20; i++){
        n.oceny[i] = nullptr;
    }
}

Student::Student(string iin, string du, string m, string u, string n) {
    set_iin(iin);
    set_du(du);
    set_mz(m, u, n);
    int tmp[20] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    for (int i = 0; i < 20; i++) {
        oceny[i] = &tmp[i];
    }
}

Student::~Student() {
}
