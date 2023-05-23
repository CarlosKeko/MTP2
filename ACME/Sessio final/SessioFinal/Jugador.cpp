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
    a_seguidors.mostrarSeguidors(opcio);
}

bool Jugador::maPlena() {
    int comptador = 0;
    for (int i = 0; i < numMa; i++) {
        if (a_ma[i].cartaValida()) {
            comptador++;
        }

    }

    if (comptador == numMa) {
        return true;

    }else {
        return false;
    }

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

bool Jugador::donarSeguidors(Jugador& j, char m) {
    if (a_seguidors.donarSeguidors(j.a_seguidors, m)) {
        return true;

    }else {
        return false;
    }
}

void Jugador::pasarMaASeguidors() {
    for (int i = 0; i < numMa; i++) {
        if (a_ma[i].cartaValida()) {
            a_seguidors.inserir(a_ma[i]);

        }
    }
}

bool Jugador::comprobarMaxim(int maxim) {
    if (maxim >= 0 && maxim < numMa && a_ma[maxim].cartaValida()) {
        return true;

    }else {
        return false;
    }
}
