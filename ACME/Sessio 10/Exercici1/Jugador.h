#ifndef JUGADOR_H
#define JUGADOR_H
#include "Carta.h"
#include "string"

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

        int getNumMa();

        //MODIFICADOR
        void afegir(Carta carta);

    private:
        string nom;
        Carta a_ma[numMa];
        int a_numElements;
};

#endif // JUGADOR_H
