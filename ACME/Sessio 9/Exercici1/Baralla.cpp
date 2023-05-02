#include "Baralla.h"
#include "Carta.h"
using namespace std;


Baralla::Baralla()
{
//Pre: --; Post: taula buida amb memòria resevada per a_max=5 Carta
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
}

Baralla::Baralla(const Baralla &t)
{
//Pre: --; Post: aquesta taula és còpia de la taula t
    copia(t);
}

Baralla::~Baralla()
{
//Pre: --; Post: memòria alliberada
    allibera();
}

Baralla &Baralla::operator=(const Baralla &t)
{
//Pre: --; Post: aquesta taula és còpia de la taula t
    if (this != &t)
    {
        allibera();
        copia(t);
    }
    return *this;
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
//Pre: --; Post: memòria alliberada
    delete [] a_t;
}

void Baralla::copia(const Baralla &t)
{
//Pre: memòria alliberada; Post: aquesta taula és còpia de la taula t
    a_n = t.a_n;
    a_max = t.a_max;
    reserva();
    for(int i=0; i<a_n; i++)
        a_t[i] = t.a_t[i];
}

void Baralla::reserva()
{
//Pre: --; Post: memòria reservada per a_max Punt2D
    a_t = new Carta[a_max];
}

void Baralla::expandeix()
{
//Pre: --; Post: la memòria reservada es dobla
    Carta *aux = a_t; // taula a substituir
    a_max = 2*a_max; // s’amplia la capacitat
    reserva(); // es crea la nova taula
    for(int i=0; i<a_n; i++) // es copien les caselles
        a_t[i] = aux[i];
    delete[] aux; //s’allibera la vella
}

int Baralla::aleatori(int rang) {
    llavor = a * llavor + c;
    return (unsigned int) ((llavor / 32) % m) % rang;
}

void Baralla::generadorAleatori() {
    llavor = a * llavor + c;

}
