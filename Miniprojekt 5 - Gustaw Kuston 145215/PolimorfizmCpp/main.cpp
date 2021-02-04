#include <iostream>
#include <stdio.h>
#include <string>
#include <map>
#include <vector>
#include "Osoba.h"
#include "Student.h"
#include "Pracownik.h"
#include "FabrykaOsob.h"
#include "FabrykaStudentow.h"
#include "FabrykaPracownikow.h"

using namespace std;


// Mozna wywolac te funkcje z obietkami typu Pracownik i Student jako argumenty,
// ale wtedy wywoluje sie metoda przedstaw dla klasy Osoba.
// Dopiero po dodaniu virtual do metody przedstaw klasy Osoba, funckja wywoluje
// odpowiednie metody dla klas Pracownik i Student.
void foo(Osoba &os) {
    os.przedstaw();
}
void bar(Osoba *os) {
    os->przedstaw();
}


int main() {

    std::map<string, FabrykaOsob*> m;
    m["pracownik"] = new FabrykaPracownikow();
    m["student"] = new FabrykaStudentow();
    // Podanie pracownik lub student wywola odpowiednia fabryke.

    std::vector <Osoba*> tablicaOsob;
    FabrykaOsob *f;
    FabrykaStudentow fs;
    FabrykaPracownikow fp;

    string opcja;
    while (true) {
        cout << "Podaj komende - pracownik, student lub wyswietl:" << endl;
        cin >> opcja;
        if (opcja.compare("wyswietl") != 0) {
            tablicaOsob.push_back(m[opcja]->utworz());
        }
        else {
            for (int i = 0; i < tablicaOsob.size(); i++) {
                cout << endl;
                tablicaOsob[i]->przedstaw();
            }
        }
    }
    // Program dziala poprawnie, a mapa i wektor dobrze sie sprawuja.

    // f = &fs;
    // f->utworz();

    // f = &fp;
    // f->utworz();

    // Osoba* o1 = new Osoba;
    // o1 = f1->utworz();

    // FabrykaPracownikow *f2;
    // Pracownik* o2 = new Pracownik;
    // o2 = f2->utworz();

    // FabrykaStudentow *f3;
    // Student* o3 = new Student;
    // o3 = f3->utworz();

    // Pracownik *p1 = new Pracownik ;
    // Osoba *o1 = static_cast<Osoba *>(p1);
    // Osoba *o2 = static_cast<Pracownik *>(o1);

    // Osoba *o3 = new Osoba;
    // Pracownik *p2 = static_cast<Pracownik *>(o3);
    // // Rzutowania z osoby na osobe nie jest potrzebne,
    // // poniewaz sa to obiekty tego samego typu.

    // Pracownik *p3 = new Pracownik ;
    // Osoba *o4 = dynamic_cast<Osoba *>(p3 ) ;
    // Pracownik *p4 = dynamic_cast<Osoba *>(o4 ) ;
    // // Ostatnie rzutowanie nie jest poprawne, program nie kompiluje sie.

    // Osoba *o5 = new Osoba ;
    // Pracownik *p5 = dynamic_cast<Pracownik *>(o5 ) ;
    // if (p5 == nullptr) cout << "Blad rzutowania!" << endl;
    // else p5 -> przedmioty;
    // Po dobrym rzutowaniu dynamic_cast zwraca odpowiedni wkaznik,
    // a przy zlym nullptr.

    // Po dodaniu virtual void przedstaw() = 0, klasa stala sie abstrakcyjna
    // i jej instancja nie moze byc utworzona bezposrednio.

    // Zmiana programu w taki sposob, by obslugiwal lazy loading wymagala paru kombinacji,
    // ale ostatecznie program zdaje sie byc funkcjonalny.
    // Po usunieciu = 0 z virutal, program kompiluje sie.

    // Virtual w destruktorze powoduje, ze zawsze uruchamia sie odpowiedni destruktor dla danej klasy dziedziczacej.

    // Osoba Adam;
    // Adam.set_iin("Adam Adamowski");
    // Adam.set_du("20.12.2002");
    // Adam.set_mz("Poznan", "Rolna", "23");
    // foo(Adam);
    // bar(&Adam);

    // Student Krzysztof;
    // Krzysztof.set_iin("Krzysztof Krzysztofski");
    // Krzysztof.set_du("12.03.2001");
    // Krzysztof.set_mz("Poznan", "Spadzista", "43");
    // Krzysztof.set_o(1, 5);
    // Krzysztof.set_o(2, 3);
    // Krzysztof.set_o(5, 1);
    // foo(Krzysztof);
    // bar(&Krzysztof);

    // Pracownik Lukasz;
    // Lukasz.set_iin("Lukasz Lukaszkiewicz");
    // Lukasz.set_du("03.06.2002");
    // Lukasz.set_mz("Poznan", "Czajcza", "13");
    // Lukasz.add_p(2);
    // Lukasz.add_p(5);
    // Lukasz.add_p(6);
    // foo(Lukasz);
    // bar(&Lukasz);

}
