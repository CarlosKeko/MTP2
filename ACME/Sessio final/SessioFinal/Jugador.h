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

        bool comprobarMaxim(int maxim);

        bool maPlena();

        int calcularMagiaMesAlta(char c);

        void controlaMagia(char c, int puntuacio);

        int obtenirDecepcio();

        //MODIFICADOR
        void afegir(Carta carta);

        void afegirCartaPosicio(Carta carta, int pos);

        void afegirSeguidor(Carta c);

        bool donarSeguidors(Jugador& j, char m);

        void pasarMaASeguidors();

    private:
        string nom;
        Carta a_ma[numMa];
        Seguidors a_seguidors;
        int a_numElements;
};

#endif // JUGADOR_H
