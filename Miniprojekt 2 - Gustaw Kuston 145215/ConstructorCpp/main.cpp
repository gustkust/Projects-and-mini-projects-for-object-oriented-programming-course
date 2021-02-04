#include <iostream>
#include <ctime>
#include "JednorekiBandyta.h"
#include "Stopper.h"


// przykladowa funkcja, ktora przyjmuje obiekt typu gambling_machine przez wartosc (pkt. 14)
// - po podaniu obiektu typu gambling_machine wywoluje sie copy constructor
// - przy uzyciu semantyki move wywoluje sie move constructor
// - po podaniu samej wartosci mogacej zostac obiektem wywoluje sie conversion constructor
void object_function(gambling_machine machine) {
    std::cout << "Function with machine parameter." << std::endl;
}


// przykladowa funkcja, ktora przyjmuje obiekt typu gambling_machine przez stala referencje R-value (pkt. 18)
// - po podaniu obiektu typu gambling_machine nie wywoluje sie constructor
// - przy uzyciu semantyki move nie wywoluje sie constructor
// - po podaniu samej wartosci mogacej zostac obiektem wywoluje sie conversion constructor
void const_ref_function(const gambling_machine &machine) {
    std::cout << "Constant reference function." << std::endl;
}


// przykladowa funkcja, ktora przyjmuje obiekt typu gambling_machine przez zwykla referencje R-value (pkt. 20)
// - po podaniu obiektu typu gambling_machine nie wywoluje sie constructor
// - przy uzyciu semantyki move wystepuje blad (nie moze byc R-value jako non const L-value)
// - po podaniu samej wartosci mogacej zostac obiektem wystepuje blad (nie moze byc R-value jako non const L-value)
void nor_ref_function(gambling_machine &machine) {
    std::cout << "Normal R-value reference function." << std::endl;
}


// przykladowa funkcja, ktora przyjmuje obiekt typu gambling_machine przez referencje L-value (pkt. 22)
// - po podaniu obiektu typu gambling_machine wystepuje blad (nie moze byc L-value jako R-value)
// - przy uzyciu semantyki move nie wywoluje sie constructor (ale nie ma bledu)
// - po podaniu samej wartosci mogacej zostac obiektem wywoluje sie conversion constructor
void L_val_ref_function(gambling_machine &&machine) {
    std::cout << "L-value reference function." << std::endl;
}


int main() {
    std::cout << "Start." << std::endl;

    // Aby wywolac funkcje log przez obiekt typu gambling_machine (z poziomu funkcji main) musialem zamienic:
    // class gambling_machine: Logger
    // na: class gambling_machine: public Logger
    // Bez oznaczenia dziedziczonej klasy jako public, nie bylo do niej dostepu.
    // Warto tez zaznaczyc, ze plik main nie zawiera #include "Logger.h",
    // poniewaz korzystamy z Logger za posrednictwem JednorekiBandyta.

    gambling_machine machine;
    machine.log("Text.");

    // Po dodaniu do klasy Logger parametru debug program nie dzialal,
    // poniewaz nie bylo mozliwosci dania parametru do konstruktora Logger przez klase gambling_machine.
    // Naprawa polegala na ustawieniu domyslnej wartosci debug na true w pliku Logger.h.

    
    machine.set_sgc(10);
    machine.set_poctp(50);
    machine.set_cow(0.15);
    machine.set_pp(500);
    machine.set_nogp(0);
    machine.set_mc(2000);
    machine.set_hmmititm(500);

    // Przy dziedziczeniu z wiekszej ilosc klas istnieje ryzyko, ze jakies dwie lub wiecej klas dziedzicza z jednej wspolnej.
    // Nastepuje wtedy powielenie danych, co generuje wiele problemow.

    // Java nie wspiera wielokrotnego dziedziczenia. Ta funkcjonalnosc moga zastapic interfejsy.
    
    std::cout << "End." << std::endl;
    return 0;
}