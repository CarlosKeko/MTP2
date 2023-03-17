#include "Cim.h"
#include <cmath>
#include <iostream>

using namespace std;


//CONSTRUCTORS
Cim::Cim()
{
    nom = "Default";
    longitud = 0;
    latitud = 0;
    altitud = 0;
}
//Pre: cert;
//Post: crea el objeto cim con parametros por defecto;

Cim::Cim(string v_n, int v_a, double v_lat, double v_lon)
{
    nom = v_n;
    longitud = v_lon;
    latitud = v_lat;
    altitud = v_a;
}
//Pre: cert;
//Post: Fa un objeto cim con los parametros pasados;

Cim::Cim(string v_n)
{
    nom = v_n;
    longitud = 0;
    latitud = 0;
    altitud = 0;
}
//Pre: cert;
//Post: Fa un objeto cim con los parametros pasados y por defecto;


//CONSULTORS

bool Cim::comparar_nom(string no) const
{
    if (nom == no)
    {
        return true;

    }
    else
    {
        return false;
    }
}
//Pre: Entra un string per parametre;
//Post: compara si es el mateix codi, return true si es cert, altrament false;


void Cim::mostrar() {
    cout << "+ " << nom << " (" << altitud << " m)" << endl;
}

double Cim::calcular_distancia(double lat2, double lon2) const
{
    double PI = acos(-1.0); // constant de classe
// 111319.9 són els metres que mesura un grau sobre un meridià
    return sqrt(pow(latitud - lat2, 2) + pow(longitud * cos(latitud / 180 * PI) - lon2 * cos(lat2 / 180 * PI), 2)) * 111319.9;
}

bool Cim::altitud_requisit(int altitud_min, int altitud_max) {
    if (altitud >= altitud_min && altitud <= altitud_max) {
        return true;

    }else {
        return false;
    }
}

bool Cim::operator == (const Cim &cim) const
{
    if (nom == cim.nom)
    {
        return true;

    }
    else
    {
        return false;
    }
}
//Pre: Pasa un llibre;
//Post: Cert si es igual, altrament false;

bool Cim::operator < (const Cim &cim) const
{
    if (nom < cim.nom)
    {
        return true;

    }
    else
    {
        return false;
    }
}
//Pre: Pasa un llibre per parametre;
//Post: Cert si es mes petit que el llibre pasat per paramentre, altrament false;

bool Cim::operator > (const Cim &cim) const
{
    if (nom > cim.nom)
    {
        return true;

    }
    else
    {
        return false;
    }
}
//Pre: Pasa un llibre per parametre;
//Post: Cert si es mes gran que el llibre pasat per paramentre, altrament false;

//MODIFICADORS

void Cim::llegir(string v_n, int v_a, double v_lat, double v_lon) {
    nom = v_n;
    longitud = v_lon;
    latitud = v_lat;
    altitud = v_a;

}
