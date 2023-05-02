#ifndef TAULER_H
#define TAULER_H
#include "Carta.h"
#include "Baralla.h"

class Tauler
{
public:

    static const int MIDA_TAULER = 4;

    //CONSTRUCTORS
    Tauler();

    Tauler(int n_files, int n_columnes);

    Tauler(const Tauler &copiaTauler);

    ~Tauler();

    Tauler &operator=(const Tauler &t);


    //CONSULTORS

    void mostrar(Carta cartaEsquerra, Carta cartaDreta);


    //MODIFICADORS

    void afegirCarta(Carta c);


private:

    int a_n;
    int a_m;
    int a_fila;
    int a_columna;
    Carta** a_mp;


    //Pre: --; Post: mem�ria alliberada
    void allibera();

    //Pre: mem�ria alliberada; Post: aquesta taula �s c�pia de la taula t
    void copia(const Tauler &b);

    //Pre: --; Post: mem�ria reservada per a_max Baralla
    void reserva();

};

#endif // TAULER_H
