#ifndef CUACOMPRAVENDA_H
#define CUACOMPRAVENDA_H
#include <iostream>
#include "Compravenda.h"

using namespace std;

class Cuacompravenda
{
    public:
        // CONSTRUCTORS I DESTRUCTOR ----------------------------------
        Cuacompravenda();
        // Pre: --; Post: cua buida

        Cuacompravenda(const Cuacompravenda& o); // const. de c�pia
        // Pre: --; Post: aquesta cua �s c�pia de la Cua o

        ~Cuacompravenda();
        // Pre: --; Post: mem�ria alliberada



        // CONSULTORS -------------------------------------------------
        bool buida() const;
        // Pre: -- ; Post: retorna cert si la cua �s buida; fals en c.c.

        Compravenda primer() const;
        // Pre: cua no buida; Post: retorna c�pia del primer string de la cua
        // MODIFICADORS -----------------------------------------------

        void encua(Compravenda s);
        // Pre: --; Post: ha afegit s al final de la cua

        void desencua();
        // Pre: cua no buida; Post: ha eliminat el primer element de la cua


        // OPERADORS REDEFINITS --------------------------------------
        Cuacompravenda& operator=(const Cuacompravenda& o);
        // Pre: -- ; Post: aquesta cua �s c�pia de o


    private:
        struct Node {
            Compravenda valor;
            Node* seg;
        };

        // ATRIBUTS
        Node* a_primer; // punter al primer de la cua
        Node* a_darrer; // punter al darrer de la cua

        void copia(const Cuacompravenda& o);
        // Pre: Cua buida; Post: aquesta cua es copia de o

        void allibera();
        // Pre: --; Post: cua buida

};

#endif // CUACOMPRAVENDA_H
