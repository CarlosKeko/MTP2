#include "Biblioteca.h"
#include "Llibre.h"

using namespace std;

//CONSTRUCTOR

Biblioteca::Biblioteca()
{
    a_nDades = 0;
}


//CONSULTORS

void Biblioteca::mostrar() const
{
    if (a_nDades != 0)
    {
        for (int i = 0; i < a_nDades; i++)
        {
            a_dades[i].mostrar(1);
        }
    }


}
// Pre: --; Post: mostra tots els llibres del vector numerats de 0 al nombre depunts-1

void Biblioteca::mostrar_per_autor(string autor) const
{
    if (a_nDades != 0)
    {
        for (int i = 0; i < a_nDades; i++)
        {
            if (a_dades[i].comparar_autor(autor))
                a_dades[i].mostrar(1);
        }


    }


}
// Pre: --; Post: mostra tots els llibres del vector per autor

//MODIFICADORS
bool Biblioteca::afegir(Llibre& llibre)
{
    int pos = cercar(llibre);

    if (pos == NO_TROBAT)
    {
        if (a_nDades < MAX_LLIBRES)
        {
            inser_llibre_privat(llibre);
            return true;
        }
        else
            cout << "NO HI HA CABUDA PER A MES LLIBRES" << endl;
    }

    return false;
}
// Pre: nombre_llibres()<MAX; Post: s'ha inserit ordenadament un llibre en el vector de llibr

bool Biblioteca::eliminar(int codi)
{
    bool eliminat = false;

    for (int i = 0; i < a_nDades; i++)
    {
        if (a_dades[i].comparar_codi(codi))
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
// Pre: nombre_llibres()>0 i 0<=pos<nombre_llibres(); Post: s'esborra el llibre que ocupa la posició pos



//METODES PRIVATS
int Biblioteca::cercar(const Llibre& llibre)
{
    int mig, esq = 0, dret = a_nDades-1;
    bool trobat = false;
    while (not trobat && esq <= dret)
    {
        mig = (esq + dret)/2;
        if (a_dades[mig] == llibre)
        {
            trobat = true;

        }
        else if (a_dades[mig] < llibre)
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
//Pre: codi del llibre;
//Post: retorna bool si el troba altrament false;

void Biblioteca::inser_llibre_privat(Llibre llibre)
{
    int i = a_nDades - 1;

    while (i >= 0 && a_dades[i] > llibre)
    {
        a_dades[i + 1] = a_dades[i];
        i--;

    }
    a_dades[i + 1] = llibre;
    a_nDades++;

}
// Pre: nombre_llibres()<MAX; Post: s'ha inserit ordenadament un llibre en el ve

