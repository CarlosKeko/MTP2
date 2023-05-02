#ifndef JOC_H
#define JOC_H
#include "Baralla.h"
#include "PilaCartes.h"
#include "Tauler.h"
#include "Jugador.h"
#include "Carta.h"

class Joc
{
    public:

        static const int maximJugadors = 4;
        static const int cartesTauler = 12;

        //CONSTRUCTORS
        Joc();

        Joc (int llavor);


        //CONSULTORS
        void mostrarPiles();


        //MODIFICADORS
        void afegirJugador(int nJugadors);

        void preparar();


    private:
        int llavor;
        Baralla a_b;
        Jugador a_tJugadors[maximJugadors];
        int a_nJugadors;
        int a_n;

};

#endif // JOC_H
