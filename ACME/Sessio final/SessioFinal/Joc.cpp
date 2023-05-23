#include "Joc.h"
#include <iostream>
#include "Baralla.h"
#include "Jugador.h"
#include "Tauler.h"
#include "PilaCartes.h"

Joc::Joc()
{
    llavor = 0;
    a_nNumTorn = 0;
}

Joc::Joc(int ll)
{
    llavor = ll;
    a_nNumTorn = 0;
}

void Joc::afegirJugador(int nJugadors)
{
    string nomJugador;
    a_nJugadors = nJugadors;
    a_nNumTorn = 0;
    cin.ignore();
    for (int  i = 1; i <= nJugadors; i++ )
    {
        cout << "ENTRA EL NOM DEL JUGADOR " << i << ":" << endl;
        getline(cin, nomJugador);
        a_tJugadors[i - 1] = Jugador(nomJugador);
    }
}

void Joc::pasarTorn()
{
    a_nNumTorn++;

    if (a_nNumTorn >= a_nJugadors)
    {
        a_nNumTorn = 0;
    }
}

Jugador Joc::tornActual()
{
    return a_tJugadors[a_nNumTorn];
}

void Joc::mostrarTauler()
{
    a_tauler.mostrar(pilaEsquerra.cim(), pilaDreta.cim());
}

void Joc::mostrarMansOponents()
{
    cout << "\nMANS DELS OPONENTS:" << endl;
    for (int i = 0; i < a_nJugadors; i++)
    {
        if (i != a_nNumTorn)
        {
            a_tJugadors[i].mostrarEnFila();
            cout << " " << i + 1 << " " << a_tJugadors[i].getNom() << endl;
        }

    }
}

void Joc::mostrarSeguidors()
{
    cout << "\nRESUM DELS SEGUIDORS:" << endl;
    for (int i = 0; i < a_nJugadors; i++)
    {
        if (i != a_nNumTorn)
        {
            a_tJugadors[i].mostrarSeguidors(2);
            cout << " " << i + 1 << " " << a_tJugadors[i].getNom() << endl;
        }

    }

}

void Joc::preparar()
{
    pilaEsquerra = PilaCartes();
    pilaDreta = PilaCartes();
    a_tauler = Tauler();
    Baralla a_b = Baralla(llavor);
    a_b.barrejar();
    a_n = a_b.getNumMagies() * maximJugadors + a_b.getNumMagies() * (maximJugadors - a_nJugadors);

    for (int i = 0; i < a_n; i++)
    {
        a_b.robarCarta();
    }

    for (int i = 0; i < a_nJugadors; i++)
    {

        for (int j = 0; j < a_tJugadors[i].getNumMa(); j++)
        {
            a_tJugadors[i].afegir(a_b.robarCarta());
        }

    }

    for (int i = 0; i < cartesTauler; i++)
    {
        a_tauler.afegirCarta(a_b.robarCarta());
    }

    a_b.afegirCartaPila(pilaEsquerra, pilaDreta);

}

void Joc::ferJugada(Carta c, int fila, int columna)
{

    int comptadorInfluencia = c.getInfluencia();
    int i, finsEsquerra, finsDreta, finsAsota, finsDamunt;
    bool dentro = true;

    //COMPROBAMOS IZQUIERDA FILA
    i = columna - 1;
    finsEsquerra = columna;

    while (i >= 0 && dentro)
    {
        if (!a_tauler.posicioBuida(fila, i))
        {
            comptadorInfluencia = comptadorInfluencia + a_tauler.agafarCarta(fila, i).getInfluencia();
            finsEsquerra = i;
        }
        else
        {
            dentro = false;
        }

        i--;

    }


    //COMPROBAMOS DERECHA FILA
    dentro = true;
    i = columna + 1;
    finsDreta = columna;

    while (i < a_tauler.getColumnes() && dentro)
    {
        if (!a_tauler.posicioBuida(fila, i))
        {
            comptadorInfluencia = comptadorInfluencia + a_tauler.agafarCarta(fila, i).getInfluencia();
            finsDreta = i;

        }
        else
        {
            dentro = false;
        }

        i++;

    }

    //AGAFEM SEGUIDORS FILA
    if (comptadorInfluencia >= 10)
    {
        for (int i = finsEsquerra; i <= finsDreta; i++)
        {
            if (a_tauler.agafarCarta(fila, i).coincideixMagiaGermandat(c) && !a_tauler.agafarCarta(fila, i).esCopia(c))
            {
                a_tJugadors[a_nNumTorn].afegirSeguidor(a_tauler.agafarCarta(fila, i));
                a_tauler.afegirCartaPosicio(Carta(' ', ' ', 0), fila, i);

            }
        }
    }


    //COMPROBAMOS ARRIBA COLUMNA
    dentro = true;
    comptadorInfluencia = c.getInfluencia();
    i = fila - 1;
    finsDamunt = fila;

    while (i >= 0 && dentro)
    {
        if (!a_tauler.posicioBuida(i, columna))
        {
            comptadorInfluencia = comptadorInfluencia + a_tauler.agafarCarta(i, columna).getInfluencia();
            finsDamunt = i;
        }
        else
        {
            dentro = false;
        }

        i--;

    }

    //COMPROBAMOS ABAJO COLUMNA
    dentro = true;
    i = fila - 1;
    finsDamunt = fila;

    while (i < a_tauler.getFilas() && dentro)
    {
        if (!a_tauler.posicioBuida(i, columna))
        {
            comptadorInfluencia = comptadorInfluencia + a_tauler.agafarCarta(i, columna).getInfluencia();
            finsAsota = i;

        }
        else
        {
            dentro = false;
        }

        i++;

    }

    //AGAFEM SEGUIDORS COLUMNA
    if (comptadorInfluencia >= 10)
    {
        for (int i = finsEsquerra; i <= finsDreta; i++)
        {
            if (a_tauler.agafarCarta(fila, i).coincideixMagiaGermandat(c) && !a_tauler.agafarCarta(fila, i).esCopia(c))
            {
                a_tJugadors[a_nNumTorn].afegirSeguidor(a_tauler.agafarCarta(fila, i));
                a_tauler.afegirCartaPosicio(Carta(' ', ' ', 0), fila, i);

            }
        }
    }

}

void Joc::jugarSenseInfluencia(int posicio, int fila, int columna, char pila)
{
    if (tornActual().posicioCartaValid(posicio))
    {
        if (a_tauler.posicioValidaTauler(fila, columna))
        {
            if (pila == 'e' || pila == 'd')
            {
                Carta cartaAux = tornActual().agafarCarta(posicio);

                if (pila == 'e')
                {
                    a_tJugadors[posicio].afegirCartaPosicio(pilaEsquerra.cim(), posicio);
                    pilaEsquerra.desempila();


                }
                else
                {
                    a_tJugadors[posicio].afegirCartaPosicio(pilaDreta.cim(), posicio);
                    pilaDreta.desempila();
                }


                a_tauler.afegirCartaPosicio(cartaAux, fila, columna);

                ferJugada(cartaAux, fila, columna);


            }
            else
            {
                cout << "PILA NO VALIDA" << endl;
            }

        }
        else
        {
            cout << "LA POSICIO DEL TAULER NO ES VALIDA" << endl;

        }

    }
    else
    {
        cout << "NO HI HA CARTAS A AQUESTA POSICIO" << endl;

    }
}
