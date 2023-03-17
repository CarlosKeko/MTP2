#ifndef CIM_H
#define CIM_H
#include <iostream>
#include <cmath>

using namespace std;

class Cim
{
    public:



        //CONSTRUCTORS
        Cim();
        //Pre: cert;
        //Post: crea el objeto cim con parametros por defecto;

        Cim(string v_n, int v_a, double v_lat, double v_lon);
        //Pre: cert;
        //Post: Fa un objeto cim con los parametros pasados;

        Cim(string nom);
        //Pre: cert;
        //Post: Fa un objeto cim con los parametros pasados y por defecto;


        //CONSULTORS
        bool comparar_nom(string no) const;

        double calcular_distancia(double latitud, double longitud) const;

        void mostrar();

        bool altitud_requisit(int altitud_min, int altitud_max);

        bool operator == (const Cim &cim) const;
        //Pre: Pasa un llibre;
        //Post: Cert si es igual, altrament false;

        bool operator < (const Cim &cim) const;
        //Pre: Pasa un llibre per parametre;
        //Post: Cert si es mes petit que el llibre pasat per paramentre, altrament false;

        bool operator > (const Cim &cim) const;
        //Pre: Pasa un llibre per parametre;
        //Post: Cert si es mes gran que el llibre pasat per paramentre, altrament false;

        //MODIFICADORS
        void llegir(string v_n, int v_a, double v_lat, double v_lon); //Pre: -; Post: llegeix un cim, retorna fals si el codi és 0

    private:

        //CONSTANT
        //const double PI = acos(-1.0); // constant de classe

        //VARIABLES
        string nom;
        int altitud;
        double latitud, longitud;
};

#endif // CIM_H
