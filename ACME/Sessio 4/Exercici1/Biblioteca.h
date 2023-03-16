#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H
#include "Llibre.h"

class Biblioteca
{
    public:
        //CONSTRUCTORS
        Biblioteca();
        //Pre: --;
        //Post: Vector buit de llibres;


        //CONSULTORS
        void mostrar() const;
        // Pre: --; Post: mostra tots els llibres del vector numerats de 0 al nombre depunts-1

        void mostrar_per_autor(string autor) const;
        // Pre: --; Post: mostra tots els llibres del vector per autor


        //MODIFICADORS
        bool afegir(Llibre& llibre);
        // Pre: nombre_llibres()<MAX; Post: s'ha inserit ordenadament un llibre en el vector de llibres;

        bool eliminar(int codi);
        // Pre: nombre_llibres()>0 i 0<=pos<nombre_llibres(); Post: s'esborra el llibre que ocupa la posició pos


    private:
        //CONSTANTS
        static const int MAX_LLIBRES= 100;
        static const int NO_TROBAT = -1;

        //ATRIBUTS
        Llibre a_dades[MAX_LLIBRES]; // vector de llibres
        int a_nDades; // nombre de llibres


        //FUNCIONS

        int cercar(const Llibre& llibre);
        //Pre: codi del llibre;
        //Post: retorna bool si el troba altrament false;


        void inser_llibre_privat(Llibre llibre);
        // Pre: nombre_llibres()<MAX; Post: s'ha inserit ordenadament un llibre en el vector de llibres;

};

#endif // BIBLIOTECA_H
