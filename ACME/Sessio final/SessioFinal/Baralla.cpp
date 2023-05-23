#include "Baralla.h"
#include "Carta.h"
#include <iostream>
using namespace std;


Baralla::Baralla()
{
//Pre: --; Post: taula buida amb mem�ria resevada per a_max=5 Carta
    a_n = 0;
    a_max = 5;
    reserva();
    llavor = 1;

}

Baralla::Baralla(int ll) {
    a_n = 0;
    a_max = 5;
    reserva();
    llavor = ll;
    a_taulaMagies = new char[magies];
    a_taulaInfluencia = new int[influencies];
    a_taulaGermandat = new char[germandat];
    crearCartes();

}

Baralla::Baralla(const Baralla &t)
{
//Pre: --; Post: aquesta taula �s c�pia de la taula t
    copia(t);
}

Baralla::~Baralla()
{
//Pre: --; Post: mem�ria alliberada
    allibera();
}

Baralla &Baralla::operator=(const Baralla &t)
{
//Pre: --; Post: aquesta taula �s c�pia de la taula t
    if (this != &t)
    {
        allibera();
        copia(t);
    }
    return *this;
}

Carta Baralla::robarCarta() {
    a_n--;
    return a_t[a_n];

}

void Baralla::afegirCartaPila(PilaCartes &pU, PilaCartes &pDos) {
    int aux = a_n / 2;
    Carta *auxCarta = a_t;

    for (int i = a_n; i > aux; i--) {
        pU.empila(robarCarta());
    }

    for (int i = aux; i > 0; i--) {
        pDos.empila(robarCarta());
    }

}

void Baralla::barrejar() {
    fisherYates();
}

void Baralla::afegir(const Carta &p)
{
//Pre: --; Post: p afegit a la taula
    if (a_n == a_max) expandeix();
    a_t[a_n] = p;
    a_n++;
}
void Baralla::allibera()
{
//Pre: --; Post: mem�ria alliberada
    delete [] a_t;
}

void Baralla::copia(const Baralla &t)
{
//Pre: mem�ria alliberada; Post: aquesta taula �s c�pia de la taula t
    a_n = t.a_n;
    a_max = t.a_max;
    reserva();
    for(int i=0; i<a_n; i++)
        a_t[i] = t.a_t[i];
}

void Baralla::reserva()
{
//Pre: --; Post: mem�ria reservada per a_max Punt2D
    a_t = new Carta[a_max];
}

void Baralla::mostrar() {

    if (a_n > 0) {
        for (int i = 0; i < a_n; i++) {
            a_t[i].mostrar(1);
        }

    }else {
        cout << "NO HI HA CAP CARTA";
    }
    cout << endl;
}

void Baralla::expandeix()
{
//Pre: --; Post: la mem�ria reservada es dobla
    Carta *aux = a_t; // taula a substituir
    a_max = 2*a_max; // s�amplia la capacitat
    reserva(); // es crea la nova taula
    for(int i=0; i<a_n; i++) // es copien les caselles
        a_t[i] = aux[i];
    delete[] aux; //s�allibera la vella
}

int Baralla::aleatori(int rang) {
    llavor = a * llavor + c;
    return (unsigned int) ((llavor / 32) % m) % rang;
}

void Baralla::intercanvi(Carta cartaU, Carta cartaDos, int pos, int i) {
    Carta aux = cartaU;
    a_t[pos] = cartaDos;
    a_t[i] = cartaU;

}

void Baralla::fisherYates() {
    for (int i = a_n - 1; i > 0; i--) {
        int pos = aleatori(i + 1);
        intercanvi(a_t[pos], a_t[i], pos, i);

    }
}

void Baralla::crearCartes() {
    a_taulaMagies[0] = 'b';
    a_taulaMagies[1] = 'o';
    a_taulaMagies[2] = 'p';
    a_taulaMagies[3] = 'r';
    a_taulaMagies[4] = 't';
    a_taulaMagies[5] = 'v';
    a_taulaInfluencia[0] = 1;
    a_taulaInfluencia[1] = 2;
    a_taulaInfluencia[2] = 3;
    a_taulaInfluencia[3] = 4;
    a_taulaInfluencia[4] = 5;
    a_taulaGermandat[0] = 'c';
    a_taulaGermandat[1] = 'g';
    a_taulaGermandat[2] = 's';

    for (int i = 0; i < magies; i++) {
        for (int j = 0; j < germandat; j++) {
            for (int o = 0; o < influencies; o++) {
                Carta aux(a_taulaMagies[i],a_taulaGermandat[j],a_taulaInfluencia[o]);
                afegir(aux);
            }
        }
    }
}

int Baralla::getNumMagies() {
    return magies;
}
