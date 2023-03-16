#ifndef LLIBRE_H
#define LLIBRE_H
#include <iostream>
#include "Data.h"

using namespace std;

class Llibre
{
    public:
        static const int CODI_FI = 0;

        //CONSTRUCTORS
        Llibre();
        //Pre: cert;
        //Post: crea el objeto libro con parametros por defecto;

        Llibre(int c, string t, string a, string e, Data d);
        //Pre: cert;
        //Post: Fa un objeto libro con los parametros pasados;

        Llibre(int c);
        //Pre: cert;
        //Post: Fa un objeto libro con los parametros pasados y por defecto;

        //CONSULTORS

        void mostrar(int valor) const;
        //Pre: Cert;
        //Post: Mostra per finestra les dades del llibre;

        bool mes_recent(Data d);
        //Pre: Obtiene una fecha por ventana
        //Post: Devuelve true si la fecha entrada por parametro es mas reciente y falso si es al contrario;

        bool comparar_autor(string autor) const;
        //Pre: Entra un string per parametre;
        //Post: compara si es el mateix autor, return true si es cert, altrament false;

        bool comparar_codi(int codi) const;
        //Pre: Entra un string per parametre;
        //Post: compara si es el mateix codi, return true si es cert, altrament false;

        /*bool codi_mes_petit(string codi) const;
        //Pre: Entra un string per parametre;
        //Post: compara si es el codi es mes petit, return true si es cert, altrament false;*/

        bool operator == (const Llibre &llibre) const;
        //Pre: Pasa un llibre;
        //Post: Cert si es igual, altrament false;

        bool operator < (const Llibre &llibre) const;
        //Pre: Pasa un llibre per parametre;
        //Post: Cert si es mes petit que el llibre pasat per paramentre, altrament false;

        bool operator > (const Llibre &llibre) const;
        //Pre: Pasa un llibre per parametre;
        //Post: Cert si es mes gran que el llibre pasat per paramentre, altrament false;


        //MODIFICADORS
        bool llegir(); //Pre: -; Post: llegeix un llibre, retorna fals si el codi és 0


    private:
        //CONSTANTS

        //VARIABLES
        int codi;
        string titol, autor, editorial;
        Data data;
};

#endif // LLIBRE_H
