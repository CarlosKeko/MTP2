#include "Carta.h"
#include <iostream>

using namespace std;

Carta::Carta()
{
    magia = 'd';
    germandat = 'd';
    influencia = 0;
}

Carta::Carta(char m, char g, int i) {
    magia = m;
    germandat = g;
    influencia = i;
}

//CONSULTORS

void Carta::mostrar() {
    cout << "[" << magia << influencia << germandat << "]" << endl;
}
