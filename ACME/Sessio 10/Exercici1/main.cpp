/************************************************************************
 * Exercici de la Sessió 10
 *
 * Falta l'especificació
 ************************************************************************/
#include <iostream>
#include "Joc.h"

using namespace std;

void entrada_jugadors(Joc& joc)
{
    int jugadors;

    cout << "ENTRA EL NUMERO DE JUGADORS (2-4):" << endl;
    cin >> jugadors;

    while (jugadors < 2 || jugadors > 4) {
        if (jugadors < 2 || jugadors > 4) {
            cout << "NUMERO DE JUGADORS INCORRECTE" << endl;
        }

        cout << "ENTRA EL NUMERO DE JUGADORS (2-4):" << endl;
        cin >> jugadors;
    }

    joc.afegirJugador(jugadors);
}

int main()
{
	unsigned llavor;

    cout << "ENTRA LA LLAVOR:" << endl;
    cin >> llavor;

    Joc joc(llavor);

    entrada_jugadors(joc);
    joc.preparar();
}
