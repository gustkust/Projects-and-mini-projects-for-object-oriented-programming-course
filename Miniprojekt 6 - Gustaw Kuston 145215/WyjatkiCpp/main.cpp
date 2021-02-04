#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include "Stack.h"
#include "StackException.h"
#include "StackFullException.h"
#include "StackEmptyException.h"

using namespace std;


void foo (Stack &s) {
    try {
        int i = 0;
        while (true) {
            s.push(i);
            i++;
        }
    } 
    catch (StackException e) {
        cout << e.what() << endl;
    }
}


void bar (Stack &s) {
    try {
        int i = 0;
        while (true) {
            s.push(i);
            i++;
        }
    }
    catch (StackException &e) {
        cout << e.what() << endl;
    }
}


int main(){
    Stack stos;
    string opcja;
    while (true) {
        try {
            cout << "Podaj komende - dodaj lub usun lub stop:" << endl;
            cin >> opcja;
            if (opcja.compare("dodaj") == 0) {
                int x;
                cout << "Podaj wartosc:" << endl;
                cin >> x;
                stos.push(x);
            }
            else if (opcja.compare("usun") == 0) {
                stos.pop();
            }
            else if (opcja.compare("stop") == 0) {
                break;
            }
            else {
                throw 0;
            }
        }
        catch (StackException &e) {
            cout << e.what() << endl;
        }
        catch (exception &e) {
            cout << e.what() << endl;
        }
        catch(int e) {
            if (e == 0) {
                break;
            }
        }
    }
}
