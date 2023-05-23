#include "Jugador.h"
#include "Carta.h";
#include <iostream>
#include "string"
#include "Seguidors.h"
using namespace std;

Jugador::Jugador()
{
    a_numElements = 0;
    a_seguidors = Seguidors();
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

bool Jugador::posicioCartaValid(int posicio) {
    if (posicio >= 0 && posicio < a_numElements) {
        return true;

    }else {
        return false;

    }

}

void Jugador::mostrarSeguidors(int opcio) {
    a_seguidors.mostrarSeguidors(2);
}

void Jugador::mostrarEnFila() {
    for (int i = 0; i < a_numElements; i++) {
        a_ma[i].mostrar(3);
    }
}

void Jugador::afegir(Carta c) {
    if (a_numElements < numMa) {
        a_ma[a_numElements] = c;
        a_numElements++;

    }else {
        cout << "MA PLENA" << endl;
    }

}

Carta Jugador::agafarCarta(int pos) {
    return a_ma[pos];
}

void Jugador::afegirCartaPosicio(Carta car, int pos) {
    a_ma[pos] = car;

}

int Jugador::getNumMa() {
    return numMa;
}

string Jugador::getNom() {
    return nom;
}

void Jugador::afegirSeguidor(Carta c) {
    a_seguidors.inserir(c);
}
