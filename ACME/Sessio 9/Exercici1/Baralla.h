#ifndef BARALLA_H
#define BARALLA_H
#include "Carta.h"

using namespace std;

class Baralla
{
public:
    static const int a = 1103515245;
    static const int c = 12345;
    static const int m = 32768;

    //CONSTRUCTORS
    //Pre: --; Post: taula buida amb memòria resevada per a_max=5 Punt2D
    Baralla();

    Baralla(int llavor);

    //Pre: --; Post: aquesta taula és còpia de la taula t
    Baralla(const Baralla &t);
    //Pre: --; Post: memòria alliberada
    ~Baralla();
    //Pre: --; Post: aquesta taula és còpia de la taula t
    Baralla &operator=(const Baralla &t);
    //Pre: --; Post: p afegit a la taula

    //CONSULTORS
    Carta robarCarta();

    void mostrar();

    int aleatori(int rang);


    //MODIFICADORS


    void afegir(const Carta &c);

    void barrejar();



private:
    int a_n; // nombre de caselles ocupades
    int a_max; // nombre de posicions reservades (capacitat)
    unsigned int llavor;
    Carta *a_t;

    //Pre: --; Post: memòria alliberada
    void allibera();

    //Pre: memòria alliberada; Post: aquesta taula és còpia de la taula t
    void copia(const Baralla &b);

    //Pre: --; Post: memòria reservada per a_max Baralla
    void reserva();

    //Pre: --; Post: la memòria reservada es dobla
    void expandeix();

    void generadorAleatori();
};

#endif // BARALLA_H
