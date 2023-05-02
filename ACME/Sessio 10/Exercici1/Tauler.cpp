#include "Tauler.h"
#include "Carta.h"
#include <iostream>
#include <iomanip>

using namespace std;

Tauler::Tauler()
{
    a_n=MIDA_TAULER;
    a_m=MIDA_TAULER;
    reserva();
    a_fila = 0;
    a_columna = 0;
}

Tauler::Tauler(int n_files, int n_columnes)
{
    a_n = n_files;
    a_m = n_columnes;
    a_fila = 0;
    a_columna = 0;
    reserva();
}

Tauler::Tauler(const Tauler &t)
{
//Pre:--; Post: informació de t copiada a l’actual
    copia(t);
}

Tauler::~Tauler()
{
//Pre:-;- Post: allibera la memòria reservada per l’objecte
    allibera();
}

Tauler & Tauler::operator=(const Tauler &t)
{
// Pre: --; Post: s’ha assignat sense aliasing la informació de t a l’objecte actual
    if(this!=&t)
    {
        allibera();
        copia(t);
    }
    return *this;
}

void Tauler::reserva()
{
// Pre: a_n>0 ^ a_m>0; Post: memòria reservada
    a_mp = new Carta*[a_n]; // creació d’un vector de punters
    for(int i=0; i<a_n; i++)
    {
        a_mp[i]= new Carta[a_m];


    } // creacó de cada fila

}

void Tauler::mostrar(Carta cartaEsquerra, Carta cartaDreta)
{
    bool primeraVez = true;
// Per mostrar el tauler:
    cout << string(5, ' ');
    for (int i = 0; i < a_n; i++)
    {
        for (int j = 0; j < a_m; j++)
        {
            if (primeraVez) {
                cout << setfill(' ') << setw(6) << i;
                primeraVez = false;
            }

        }
        primeraVez = true;
    }
    cout << endl;

    for (int i = 0; i < MIDA_TAULER; i++)
    {
        if (i == 1) cartaEsquerra.mostrarMagia(2);
        else cout << "   ";

        cout << setfill(' ') << setw(3) << i << " ";
        for (int j = 0; j < MIDA_TAULER; j++)
        {
            cout << " ";
            //[carta posició (i,j)]
            a_mp[i][j].mostrar(2);
        }

        if (i == 1)
        {
            cout << "  ";
            cartaDreta.mostrarMagia(2);
        }

        cout << endl;
    }
}

void Tauler::copia(const Tauler &t)
{
// Pre: --; Post: fa un duplicat de la matriu
    a_n = t.a_n;
    a_m = t.a_m;
    reserva();
    for (int i=0; i<a_n; i++)
    {
        for (int j=0; j<a_m; j++)
        {
            // còpia de les caselles de la matriu
            a_mp[i][j] = t.a_mp[i][j];
        }
    }
}

void Tauler::allibera()
{
// Pre: --; Post: memòria alliberada
    for(int i=0; i<a_n; i++) // alliberament de cadascuna de les files
        delete [] a_mp[i];
    delete [] a_mp; // alliberament del vector de punters
}

void Tauler::afegirCarta(Carta c)
{
    bool inserit = false;

    while (!inserit)
    {
        if (a_fila == 1 && a_columna == 1 || a_fila == 1 && a_columna == 2 || a_fila == 2 && a_columna == 1 || a_fila == 2 && a_columna == 2)
        {
            a_columna++;

        }
        else
        {
            if(a_fila < a_n && a_columna <= a_m)
            {
                if (a_columna >= a_m)
                {
                    a_fila++;
                    a_columna = 0;

                    if (a_fila < a_n)
                    {
                        a_mp[a_fila][a_columna] = c;
                        a_columna++;
                        inserit = true;

                    }
                }
                else
                {
                    a_mp[a_fila][a_columna] = c;
                    a_columna++;
                    inserit = true;

                }

            }

        }

    }


}


/*for (int i = 0; i < MIDA_TAULER; i++)
{
    if (i == 1) [revers carta cim pila esquerra];
    else cout << "   ";

    cout << setfill(' ') << setw(3) << i << " ";
    for (int j = 0; j < MIDA_TAULER; j++)
    {
        cout << " ";
        [carta posició (i,j)]
    }

    if (i == 1)
    {
        cout << "  ";
        [revers carta cim pila dreta]
    }

    cout << endl;
}*/
