#ifndef TAULACIMS_H
#define TAULACIMS_H
#include "Cim.h"

class TaulaCims
{
    public:
        TaulaCims();

        //CONSULTORS
        void mostrar_proposta(int altitud_min, int altitud_max, double latitud, double longitud, double radi);

        //MODIFICADORS
        bool afegir(Cim& cim);
        // Pre: nombre_cims()<MAX; Post: s'ha inserit ordenadament un cim en el vector de cims;

        bool eliminar(string nom);
        // Pre: nombre_cim()>0 i 0<=pos<nombre_cim(); Post: s'esborra el cim que ocupa la posició pos

    private:
        //CONSTANTS
        static const int MAX_CIMS= 500;
        static const int NO_TROBAT = -1;


        //ATRIBUTS
        Cim a_dades[MAX_CIMS]; // vector de cims
        int a_nDades; // nombre de cims


        //FUNCIONS

        int cercar(const Cim& cim);
        //Pre: codi del cim;
        //Post: retorna bool si el troba altrament false;

        void inser_cim_privat(Cim cim);
        // Pre: nombre_cims()<MAX; Post: s'ha inserit ordenadament un cim en el vector de cims;
};

#endif // TAULACIMS_H
