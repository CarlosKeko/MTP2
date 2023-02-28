#include <iostream>
#include "Data.h"
using namespace std;
// CONSTANTS DE CLASSE
const int Data::DIES_MES[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const string Data::NOM_MES[] = {"CAP", "GENER", "FEBRER", "MARC", "ABRIL",
                                "MAIG", "JUNY", "JULIOL", "AGOST", "SETEMBRE", "OCTUBRE", "NOVEMBRE",
                                "DESEMBRE"
                               };

// CONSTRUCTORS
// CONSTRUCTOR PER DEFECTE
Data::Data()
{
// Pre: cert; Post: és la data 1/1/2001
    a_dia = 1;
    a_mes = 1;
    a_any = 2001;
}
// CONSTRUCTOR AMB PARÀMETRES
Data::Data(int d, int m, int a)
{
// Pre: cert; Post: és la data d/m/a si és correcta o 1/1/2001 en cas contrari
    if (es_data_valida(d, m, a))
    {
        a_dia = d;
        a_mes = m;
        a_any = a;
    }
    else
    {
        a_dia = 1;
        a_mes = 1;
        a_any = 2001;
    }
}

// CONSULTORS
void Data::mostrar(int format) const
{
// Pre: format 1 o 2; // Post: mostra la data actual en format d/m/a o d–mes–a
    if (format == 1) cout << a_dia << '/' << a_mes << '/' << a_any;
    else cout << a_dia << '-' << NOM_MES[a_mes] << '-' << a_any;
}
bool Data::es_menor(const Data& d) const
{
// Pre: cert; // Post: cert si d és una data posterior a l'actual, fals altrament
    return (a_any < d.a_any) or
           (a_any == d.a_any and a_mes < d.a_mes) or
           (a_any == d.a_any and a_mes == d.a_mes and a_dia < d.a_dia);
}

bool Data::es_cumple(const Data& d) const  {
// Pre: cert;
// Post: cert si es el seu cumple, fals altrament
    if (d.a_mes == a_mes && d.a_dia == a_dia) {
        return true;

    }else {
        return false;

    }
}

int Data::comptar_anys(const Data& d) const {
// Pre: cert;
// Post: retorna el total de anys que tenen les dates
    int anys = d.a_any - a_any;

    if (d.a_mes < a_mes || d.a_mes == a_mes && d.a_dia < a_dia) {
        anys--;

    }

    return anys;

}

// MODIFICADORS
void Data::llegir(int format)
{
// Pre: format 1 o 2;
// Post: llegeix dates en format AAAAMMDD o d m a, fins a llegir-ne una de correcta
    int any, mes, dia;
    do   // cal declarar les variables que es facin servir
    {
        if (format == 1) // llegir AAAAMMDD i separar-ho en any, mes i dia
        {
            cin >> any;
            dia = any % 100;
            any = any / 100;
            mes = any % 100;
            any = any / 100;
        }
        else cin >> dia >> mes >> any;
    }
    while (not es_data_valida(dia, mes, any));
// es guarda dia, mes i any en els atributs
    a_any = any;
    a_mes = mes;
    a_dia = dia;
}

// FUNCIONS DE CLASSE
bool Data::es_data_valida(int dia, int mes, int any)
{
// Pre: cert; // Post: cert si dia/mes/any seria una data vàlida en el calendari
//gregorià (entre anys 1600 i 4000), fals altrament
    bool correcte = true;
    bool es_de_traspas = (any % 4 == 0) and (any % 100 != 0 or any % 400 == 0);
    if (any > 3999 or any < 1600 or mes > MESOS_ANY or mes < 1 or dia < 1)
        correcte = false;
    else
    {
        int dies_mes;
        if (es_de_traspas and mes == 2) dies_mes = 29;
        else dies_mes = DIES_MES[mes];
        if (dia > dies_mes) correcte = false;
    }
    return correcte;
}


