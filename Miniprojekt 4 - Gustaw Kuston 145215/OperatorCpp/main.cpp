#include <iostream>
#include <string>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <set>
#include "Samochod.h"

using namespace std;


struct cmp {
    bool operator () (const Samochod &a , const Samochod &b) const {
        return a.odczytaj_pojemnosc_baku() < b.odczytaj_pojemnosc_baku();
    }
};


int main() {

    Samochod s1(123, "audi");
    Samochod s2(0, "bmw");
    Samochod s3(200, "");

    // if (s1) {
    //     cout << "true1" << endl;
    // }
    // if (!s1) {
    //     cout << "true2" << endl;
    // }

    // Funkcja operator << uzywa slowa kluczowego friend,
    // poniewaz musi miec dostep do prywatnych parametrow klasy Samochod,
    // a jednoczesnie nie chcemy, by funkcja ta byla wewnatrz klasy Samochod
    // (nie chcemy, by byla metoda tej funkcji). 

    // cout << s2 << endl;

    // W funkcji operator < uzywamy slowa kluczowego const,
    // poniewaz chcemy powiedziec kompilatorowi, ze nie bedziemy modyfikowac parametru.
    // Dzieki tej informacji kompilator wie, ze nie musi robic kopi obiektu.

    // vector <Samochod> v;
    // v.push_back(s1);
    // v.push_back(s2);
    // v.push_back(s3);
    // sort(v.begin(), v.end());
    // for (auto it = v.begin(); it != v.end(); ++it) {
    //     cout << *it << endl;
    // }

    // set <Samochod, cmp> s;
    // s.insert(s1);
    // s.insert(s2);
    // s.insert(s3);
    // for (auto it = s.begin(); it != s.end(); ++it) {
    //     cout << *it << endl;
    // }

    // Operator ++ jest postfiksowy i zwieksza ilosc przejechanych kilometrow o 1.
    s1++;

    // Operator , jest dwuargumentowy i zwraca obiekt klasy Samochod z parametrem
    // liczba_kilometrow skopiowanym z prawego obiektu (argumentu) i parametrem
    // poziom_paliwa z lewego obiektu (reszta parametrow ma wartosci domyslne).
    s3 = (s1, s2);

    // Operator |= jest dwuargumentowy i zwraca wieksza pojemnosc baku z dwoch samochodow.
    float b = s1 |= s2;

}