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
//Pre:--; Post: informaci� de t copiada a l�actual
    copia(t);
}

Tauler::~Tauler()
{
//Pre:-;- Post: allibera la mem�ria reservada per l�objecte
    allibera();
}

Tauler & Tauler::operator=(const Tauler &t)
{
// Pre: --; Post: s�ha assignat sense aliasing la informaci� de t a l�objecte actual
    if(this!=&t)
    {
        allibera();
        copia(t);
    }
    return *this;
}

void Tauler::reserva()
{
// Pre: a_n>0 ^ a_m>0; Post: mem�ria reservada
    a_mp = new Carta*[a_n]; // creaci� d�un vector de punters
    for(int i=0; i<a_n; i++)
    {
        a_mp[i]= new Carta[a_m];


    } // creac� de cada fila

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
            if (primeraVez)
            {
                cout << setfill(' ') << setw(6) << i;
                primeraVez = false;
            }

        }
        primeraVez = true;
    }
    cout << endl;

    for (int i = 0; i < a_n; i++)
    {
        if (i == 1) cartaEsquerra.mostrarMagia(2);
        else cout << "   ";

        cout << setfill(' ') << setw(3) << i << " ";
        for (int j = 0; j < a_m; j++)
        {
            cout << " ";
            //[carta posici� (i,j)]
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
            // c�pia de les caselles de la matriu
            a_mp[i][j] = t.a_mp[i][j];
        }
    }
}

void Tauler::allibera()
{
// Pre: --; Post: mem�ria alliberada
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
            a_mp[a_fila][a_columna] = Carta(' ', ' ', 0);
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

bool Tauler::posicioValidaTauler(int fila, int columna)
{
    if (fila >= 0 && fila < a_n && columna >= 0 && columna < a_m)
    {
        return true;

    }
    else
    {
        return false;

    }

}

bool Tauler::posicioBuida(int fila, int columna)
{

    if (a_mp[fila][columna].cartaValida())
    {
        return false;

    }
    else
    {
        return true;
    }

}

void Tauler::afegirCartaPosicio(Carta c, int f, int co, bool vaciar)
{
    //cout << "\nENTRA A LA FUNCIO " << endl;

    if (!vaciar)
    {
        if (c.cartaValida() && !a_mp[f][co].cartaValida())
        {
            cout << "\n EL POOSAAAA AL TAULER" << endl;
            a_mp[f][co] = c;
            //mostrar(c, c);
        }
    }
    else
    {

        cout << "\n EL POOSAAAA AL TAULER" << endl;
        a_mp[f][co] = c;
        //mostrar(c, c);

    }



}

Carta Tauler::agafarCarta(int fila, int columna)
{
    return a_mp[fila][columna];

}

int Tauler::getColumnes()
{
    return a_m;
}

int Tauler::getFilas()
{
    return a_n;
}

int Tauler::comptarBuides()
{
    int comptador = 0;

    for (int i = 0; i < a_n; i++)
    {
        for (int j = 0; j < a_m; j++)
        {
            if (!a_mp[i][j].cartaValida())
            {
                comptador++;
            }

        }
    }

    return comptador;
}

void Tauler::omplirEspaisBuits(Carta c)
{

    bool afegit = false;

    for (int i = 0; i < a_n; i++)
    {
        for (int j = 0; j < a_m; j++)
        {
            if (!afegit && !a_mp[i][j].cartaValida())
            {
                a_mp[i][j] = c;
                afegit = true;
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
        [carta posici� (i,j)]
    }

    if (i == 1)
    {
        cout << "  ";
        [revers carta cim pila dreta]
    }

    cout << endl;
}*/
