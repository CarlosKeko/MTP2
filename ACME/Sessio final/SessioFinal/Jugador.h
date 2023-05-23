#ifndef JUGADOR_H
#define JUGADOR_H
#include "Carta.h"
#include "string"
#include "Seguidors.h"

using namespace std;

class Jugador
{
    public:
        static const int numMa = 4;

        //CONSTRUCTOR
        Jugador();

        Jugador(string nom);

        //CONSULTORS
        void mostrar();

        void mostrarEnFila();

        void mostrarSeguidors(int opcio);

        int getNumMa();

        Carta agafarCarta(int posicio);

        string getNom();

        bool posicioCartaValid(int posicio);

        //MODIFICADOR
        void afegir(Carta carta);

        void afegirCartaPosicio(Carta carta, int pos);

        void afegirSeguidor(Carta c);

    private:
        string nom;
        Carta a_ma[numMa];
        Seguidors a_seguidors;
        int a_numElements;
};

#endif // JUGADOR_H
