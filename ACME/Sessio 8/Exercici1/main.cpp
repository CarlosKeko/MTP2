/****************************************************************************
   Codi de l'exercici de la llista ordenada de videjocs

   Falta posar l'especificacio del programa
 ****************************************************************************/
#include <iostream>
#include "Data.h"
#include "Llista_ord_videojocs.h"
#include <fstream>
#include "Videojoc.h"
#include <string>
// es poden afegir includes, si cal

using namespace std;

void llegir_videojoc(ifstream &f_in, Llista_ord_videojocs &ll)
{
    Videojoc videoJocAux;
    string nom, uVenudes, data, aux, d, m, a;
    getline(f_in, nom);

    if (nom != "")
    {
        getline(f_in, uVenudes);
        int n = stoi(uVenudes);
        f_in >> d >> m >> a;
        videoJocAux = Videojoc(nom, n, Data(stoi(d), stoi(m), stoi(a)));
        ll.inserir(videoJocAux);

    }

}

void llegir_fitxer(Llista_ord_videojocs &ll)
{
// pre:
// pos:
    string nomFitxer;
    Videojoc videojoc;

    cout << "NOM DEL FITXER:" << endl;
    cin >> nomFitxer;

    ifstream f_in(nomFitxer.c_str());

    if (f_in.is_open())
    {

        while (not f_in.eof())
        {
            llegir_videojoc(f_in, ll);
        }
    }
    else
    {
        cout << "FITXER NO TROBAT" << endl;

    }

}

void consulta_existencia_videjoc(const Llista_ord_videojocs &ll)
{
// pre:
// pos:
    string opcio;
    cin.ignore();
    cout << "INTRODUEIX NOM VIDEOJOC A CONSULTAR (# per finalitzar):" << endl;
    getline(cin, opcio);
    while (opcio != "#")
    {


        if (!ll.existeix(Videojoc(opcio, 0, Data())))
        {
            cout << "Aquest videojoc no ha estat venut" << endl;

        }
        else
        {
            cout << "Aquest videojoc ha estat venut" << endl;
        }

        cout << "INTRODUEIX NOM VIDEOJOC A CONSULTAR (# per finalitzar):" << endl;
        getline(cin, opcio);

    }
}

int main()
{
    Llista_ord_videojocs ll;
    llegir_fitxer(ll); // A implementar

    if (not ll.buida())
    {
        ll.mostrar();

        int dia, mes, any;
        cout << "INTRODUEIX DATA:" << endl;
        cin >> dia >> mes >> any;
        Data data(dia, mes, any);
        ll.esborra_videojocs_previs_a(data);
        ll.mostrar();

        consulta_existencia_videjoc(ll); // A implementar
    }

    return 0;
}
