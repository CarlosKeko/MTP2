#include "TaulaCims.h"
#include "Cim.h"

using namespace std;


//CONSTRUCTOR
TaulaCims::TaulaCims()
{
    a_nDades = 0;
}


//MODIFICADORS
void TaulaCims::mostrar_proposta(int altitud_min,
                                 int altitud_max, double latitud, double longitud, double radi)
{
// Cal fer ús d'una estructura algorísmica semblant a la fusió de dues taules
// (i operadors de Cim: <)
    int comptador = 0;
    cout << endl << "Proposta de cims:" << endl;

    for (int i = 0; i < a_nDades; i++) {
        if (a_dades[i].altitud_requisit(altitud_min, altitud_max) && a_dades[i].calcular_distancia(latitud, longitud) / 1000 <= radi) {
            a_dades[i].mostrar();
            comptador++;
            //cout << a_dades[i].calcular_distancia(latitud, longitud) / 1000 << "  AAAA" << endl;
        }
    }
    //&& a_dades[i].calcular_distancia(latitud, longitud) <= radi
    cout << "\nTOTAL: " << comptador << " cims" << endl;


}


bool TaulaCims::afegir(Cim& cim)
{
    int pos = cercar(cim);

    if (pos == NO_TROBAT)
    {
        if (a_nDades < MAX_CIMS)
        {
            inser_cim_privat(cim);
            return true;
        }
    }

    return false;
}
// Pre: nombre_cims()<MAX; Post: s'ha inserit ordenadament un cim en el vector de cims;

bool TaulaCims::eliminar(string nom)
{
    bool eliminat = false;

    for (int i = 0; i < a_nDades; i++)
    {
        if (a_dades[i].comparar_nom(nom))
        {
            eliminat = true;

        }
        if (eliminat)
        {
            a_dades[i] = a_dades[i + 1];
        }

    }

    if (eliminat)
    {
        a_nDades--;

        return true;

    }
    else
    {
        return false;

    }

}
// Pre: nombre_cim()>0 i 0<=pos<nombre_cim(); Post: s'esborra el cim que ocupa la posició pos


//FUNCIONS PRIVADES

int TaulaCims::cercar(const Cim& cim)
{
    int mig, esq = 0, dret = a_nDades-1;
    bool trobat = false;
    while (not trobat && esq <= dret)
    {
        mig = (esq + dret)/2;
        if (a_dades[mig] == cim)
        {
            trobat = true;

        }
        else if (a_dades[mig] < cim)
        {
            esq = mig + 1;

        }
        else
        {
            dret = mig - 1;

        }
    }

    if (trobat) return mig;
    else return NO_TROBAT;
}
//Pre: codi del cim;
//Post: retorna bool si el troba altrament false;

void TaulaCims::inser_cim_privat(Cim cim)
{
    int i = a_nDades - 1;

    while (i >= 0 && a_dades[i] > cim)
    {
        a_dades[i + 1] = a_dades[i];
        i--;

    }
    a_dades[i + 1] = cim;
    a_nDades++;
}
// Pre: nombre_cims()<MAX; Post: s'ha inserit ordenadament un cim en el vector de cims;

