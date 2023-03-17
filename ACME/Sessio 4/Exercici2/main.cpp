#include <iostream>
#include <string>
#include <fstream>
#include "TaulaCims.h"
#include "Cim.h"
using namespace std;

bool omplir_fitxer(TaulaCims &cims)
{
    string nomArxiu;
    string nom;
    int altitud;
    double latitud, longitud;
    cout << "Entra el nom del fitxer amb els cims del repte:" << endl;
    cin >> nomArxiu;

    ifstream f_in(nomArxiu.c_str());

    Cim nouCim;

    if (f_in.is_open())
    {
        f_in >> nom;
        f_in >> altitud;
        f_in >> latitud;
        f_in >> longitud;
        nouCim.llegir(nom, altitud, latitud, longitud);

        while (not f_in.eof())
        {
            cims.afegir(nouCim);
            f_in >> nom;
            f_in >> altitud;
            f_in >> latitud;
            f_in >> longitud;
            nouCim.llegir(nom, altitud, latitud, longitud);
        }
        return true;
    }
    else
    {
        cout << "FITXER NO TROBAT" << endl;
        return false;

    }
};

int main()
{
    TaulaCims vector_cims = TaulaCims();
    omplir_fitxer(vector_cims);
    string nomFet;
    cout << "Entra el nom dels cims que ja s'han fet (# per acabar):" << endl;
    cin >> nomFet;
    int altMin, altMax;
    double latitud, longitud;
    double radi;

    while (nomFet != "#") {
        vector_cims.eliminar(nomFet);
        cin >> nomFet;

    }


    cout << "Entra el rang d'altitud acceptat (en metres):" << endl;
    cin >> altMin >> altMax;

    cout << "Entra la latitud i longitud actuals (en graus):" << endl;
    cin >> latitud >> longitud;

    cout << "Entra el radi maxim a considerar (en km):" << endl;
    cin >> radi;

    vector_cims.mostrar_proposta(altMin, altMax, latitud, longitud, radi);

    return 0;
}
