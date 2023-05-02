#include "Joc.h"
#include <iostream>
#include "Baralla.h"
#include "Jugador.h"
#include "Tauler.h"
#include "PilaCartes.h"

Joc::Joc()
{
    llavor = 0;
}

Joc::Joc(int ll)
{
    llavor = ll;
}

void Joc::afegirJugador(int nJugadors)
{
    string nomJugador;
    a_nJugadors = nJugadors;
    cin.ignore();
    for (int  i = 1; i <= nJugadors; i++ )
    {
        cout << "ENTRA EL NOM DEL JUGADOR " << i << ":" << endl;
        getline(cin, nomJugador);
        a_tJugadors[i - 1] = Jugador(nomJugador);
    }
}

void Joc::preparar()
{
    PilaCartes pilaEsquerra = PilaCartes();
    PilaCartes pilaDreta = PilaCartes();
    Tauler tauler = Tauler();
    Baralla a_b = Baralla(llavor);
    a_b.barrejar();
    cout << "\nBARALLA INICIAL:" << endl;
    a_b.mostrar();
    a_n = a_b.getNumMagies() * maximJugadors + a_b.getNumMagies() * (maximJugadors - a_nJugadors);
    for (int i = 0; i < a_n; i++)
    {
        a_b.robarCarta();
    }
    cout << "\nBARALLA DESPRES DE RETIRAR CARTES:" << endl;
    a_b.mostrar();

    for (int i = 0; i < a_nJugadors; i++)
    {

        for (int j = 0; j < a_tJugadors[i].getNumMa(); j++)
        {
            a_tJugadors[i].afegir(a_b.robarCarta());
        }
        a_tJugadors[i].mostrar();

    }

    cout << "\nBARALLA DESPRES DE REPARTIR A JUGADORS:" << endl;

    a_b.mostrar();

    for (int i = 0; i < cartesTauler; i++) {
        tauler.afegirCarta(a_b.robarCarta());
    }

    cout << "\nBARALLA DESPRES D'OMPLIR TAULER:" << endl;

    a_b.mostrar();

    a_b.afegirCartaPila(pilaEsquerra, pilaDreta);



    cout << "\nTAULER:" << endl;
    tauler.mostrar(pilaEsquerra.cim(), pilaDreta.cim());

    cout << "\nPILA ESQUERRA:" << endl;
    pilaEsquerra.mostrar(2);

    cout << "\nPILA DRETA:" << endl;
    pilaDreta.mostrar(2);

}
