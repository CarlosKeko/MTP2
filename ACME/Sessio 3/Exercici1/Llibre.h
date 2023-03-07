#ifndef LLIBRE_H
#define LLIBRE_H
#include <iostream>
#include "Data.h"

using namespace std;

class Llibre
{
    public:

        //CONSTRUCTORS
        Llibre();
        //Pre: cert;
        //Post: crea el objeto libro con parametros por defecto;

        Llibre(int c, string t, string a, string e, Data d);
        //Pre: cert;
        //Post: Fa un objeto libro con los parametros pasados;

        //CONSULTORS

        void mostrar();
        //Pre: Cert;
        //Post: Mostra per finestra les dades del llibre;

        bool mes_recent(Data d);
        //Pre: Obtiene una fecha por ventana
        //Post: Devuelve true si la fecha entrada por parametro es mas reciente y falso si es al contrario;

        //MODIFICADORS


    private:
        int codi;
        string titol, autor, editorial;
        Data data;
};

#endif // LLIBRE_H
