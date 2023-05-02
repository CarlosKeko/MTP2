#ifndef PILACARTES_H
#define PILACARTES_H
#include "Carta.h"
#include <iostream>

class PilaCartes
{
public:
    // CONSTRUCTORS I DESTRUCTOR ----------------------------------
    PilaCartes();
    // Pre: --; Post: pila buida

    PilaCartes(const PilaCartes& o);  // const. de copia
    // Pre: --; Post: aquesta pila es copia de la pila o

    ~PilaCartes();
    // Pre: --; Post: memoria alliberada (inclosa la din�mica)

    // CONSULTORS -------------------------------------------------
    bool buida() const;
    // Pre: -- ; Post: retorna cert si la pila es buida; fals en c.c.

    Carta cim() const;
    // Pre: pila no buida; Post: retorna el valor del cim de la pila

    int mida() const;

    void mostrar(int tipus) const;

    // MODIFICADORS -----------------------------------------------
    void empila(Carta s);
    // Pre: --; Post: ha afegit s a dalt de la pila

    void desempila();
    // Pre: pila no buida; Post: ha eliminat element de dalt de la pila

    // OPERADORS REDEFINITS ---------------------------------------
    PilaCartes& operator=(const PilaCartes& o);
    // Pre: -- ; Post: aquesta pila es copia de la pila o i la seva mem�ria din�mica ha estat pr�viament alliberada

private:
    struct Node
    {
        Carta valor;
        Node* seg;
    };

    // ATRIBUTS
    Node* a_cim; // punter al cim de la pila

    // METODES PRIVATS
    void copia(const PilaCartes& o);
    // Pre: pila buida; Post: aquesta pila es copia de la pila o

    void allibera();
    // Pre: --; Post: memoria dinmica alliberada
};

#endif // PILACARTES_H
