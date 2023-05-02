#include "Carta.h"
#include <iostream>

using namespace std;

Carta::Carta()
{
    magia = ' ';
    germandat = ' ';
    influencia = 0;

}

Carta::Carta(char m, char g, int i) {
    magia = m;
    germandat = g;
    influencia = i;
}

//CONSULTORS

void Carta::mostrar(int format) {
    if (format == 1) {
        if (magia == ' ' || germandat == ' ' || influencia == 0) {
            cout << "[   ] ";

        }else {
            cout << "[" << magia << influencia << germandat << "] ";

        }


    }else {
        if (magia == ' ' || germandat == ' ' || influencia == 0) {
            cout << "[   ]";

        }else {
            cout << "[" << magia << influencia << germandat << "]";

        }
    }
}

void Carta::mostrarMagia(int format) {
    if (format == 1) {
        cout << "[" << magia << "] ";

    }else {
        cout << "[" << magia << "]";
    }

}
