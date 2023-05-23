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

        Jugador tornActual();

        void mostrarTauler();

        void mostrarMansOponents();

        void mostrarSeguidors();


        //MODIFICADORS
        void afegirJugador(int nJugadors);

        void preparar();

        void pasarTorn();

        void jugarSenseInfluencia(int posicio, int fila, int columna, char pila);

        void ferJugada(Carta c, int fila, int columna);


    private:
        int llavor;
        int a_nNumTorn;
        Baralla a_b;
        Jugador a_tJugadors[maximJugadors];
        Tauler a_tauler;
        PilaCartes pilaEsquerra;
        PilaCartes pilaDreta;
        int a_nJugadors;
        int a_n;

};

#endif // JOC_H
