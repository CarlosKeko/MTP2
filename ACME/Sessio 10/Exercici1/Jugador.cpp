#include "Jugador.h"
#include "Carta.h";
#include <iostream>
#include "string"
using namespace std;

Jugador::Jugador()
{
    a_numElements = 0;
}

Jugador::Jugador(string n)
{
    a_numElements = 0;
    nom = n;
}

void Jugador::mostrar() {
    cout << endl;
    cout << "MA DE " << nom << ":" << endl;
    for (int i = 0; i < a_numElements; i++) {
        cout << i << ":";
        a_ma[i].mostrar(1);
    }
    cout << endl;

}

void Jugador::afegir(Carta c) {
    if (a_numElements < numMa) {
        a_ma[a_numElements] = c;
        a_numElements++;

    }else {
        cout << "MA PLENA" << endl;
    }

}

int Jugador::getNumMa() {
    return numMa;
}
