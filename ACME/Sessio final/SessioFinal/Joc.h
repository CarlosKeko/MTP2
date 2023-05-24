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

        void mostrarSeguidors(bool ultimo);

        void mostrarTotsSeguidors();

        bool numJugadorsValids(int n);

        bool comprobarMaximCartes(int maxim);

        bool comprobarPosicioTauler(int fila, int columna);

        bool comprobarPosicioTaulerBuit(int fila, int columna);

        void comprobarPiles();

        bool permetTorn();

        bool ultimaVoltaCompletada();

        char pilaBuida();

        //MODIFICADORS
        void afegirJugador(int nJugadors);

        void preparar();

        void pasarTorn();

        void jugarSenseInfluencia(int posicio, int fila, int columna, char pila);

        bool jugarAmbInfluencia(char magia, int jugadorEscollit);

        void ferJugada(Carta c, int fila, int columna);

        void omplirTaulerBruixots(PilaCartes& p, PilaCartes& pAux);

        void posarInfluencia();

        void calcularPuntuacio();


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
        bool ultimTorn;
        int voltesUltimTorn;

};

#endif // JOC_H
