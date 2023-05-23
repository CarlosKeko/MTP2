/************************************************************************
 * Exercici de la Sessi� 10
 *
 * Falta l'especificaci�
 ************************************************************************/
#include <iostream>
#include "Joc.h"

using namespace std;

void opcioJ(Joc& joc) {
    int posicioCarta, fila, columna;
    char pila;

    cout << "ENTRA LA POSICIO DE LA CARTA QUE VOLS COL.LOCAR:" << endl;
    cin >> posicioCarta;

    cout << "ENTRA LA POSICIO DEL TAULER ON VOLS COL.LOCAR LA CARTA:" << endl;
    cin >> fila >> columna;

    cout << "DE QUINA PILA VOLS ROBAR LA CARTA? (e/d)" << endl;
    cin >> pila;

    joc.jugarSenseInfluencia(posicioCarta, fila, columna, pila);

}

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

void mostrarMenu() {
    cout << "\nOPCIONS:" << endl;
    cout << "(I) FER JUGADA CEDINT INFLUENCIA" << endl;
    cout << "(J) FER JUGADA SENSE CEDIR INFLUENCIA" << endl;
    cout << "(P) MOSTRAR PILES" << endl;
    cout << "(F) ABANDONAR PARTIDA" << endl;
}

int main()
{
	unsigned llavor;
    char opcio;

    cout << "ENTRA LA LLAVOR:" << endl;
    cin >> llavor;

    Joc joc(llavor);

    entrada_jugadors(joc);
    joc.preparar();

    do {

        cout << "\nTORN DE " << joc.tornActual().getNom() << "\n=========================\n" << endl;

        joc.mostrarTauler();

        joc.tornActual().mostrar();

        joc.mostrarMansOponents();

        joc.mostrarSeguidors();

        mostrarMenu();

        cout << "\nENTRA UNA OPCIO:" << endl;
        cin >> opcio;

        switch (opcio) {
            case 'I':
                cout << "II" << endl;
                break;

            case 'J':
                opcioJ(joc);
                break;

            case 'P':
                cout << "PP" << endl;
                break;

            case 'F':
                cout << "FF" << endl;
                break;
        }

        joc.pasarTorn();

    }while (opcio != 'F');

}
