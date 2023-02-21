#ifndef DATA_H
#define DATA_H

using namespace std;

class Data
{
    public:
        //CONSTRUCTORS
        Data();
        //Pre: cert;
        //Post: És la data 1/1/2001

        Data(int d, int m, int a);
        //Pre: cert;
        //Post es la data d/m/a en caso que sea correcta, en el caso contrario es 1/1/2001

        //CONSULTORS
        void mostrar(int format) const;
        //Pre: format 1 o 2;
        //Post: mostra la data actual en format d/m/a o d-m-ma

        bool es_menor(const Data& d) const;
        // Pre: cert;
        // Post: cert si d és una data posterior a l'actual, fals altrament

        //MODIFICADORS
        void llegir(int format);
        // Pre: format 1 o 2;
        // Post: llegeix dates en format AAAAMMDD o d m a,
        // fins a llegir-ne una de correcta

    private:
        // ATRIBUTS
        int a_dia;
        int a_mes;
        int a_any;

        // CONSTANTS DE CLASSE
        static const int MESOS_ANY = 12;
        static const int DIES_MES[];
        static const string NOM_MES[];

        // FUNCIONS DE CLASSE
        static bool es_data_valida(int dia, int mes, int any);
        // Pre: cert;
        // Post: retorna cert si dia/mes/any formen una data vàlida
        // en el calendari gregorià (entre els anys 1600 i 4000)

};

#endif // DATA_H
