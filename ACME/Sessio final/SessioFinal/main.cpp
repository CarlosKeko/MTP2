/************************************************************************
 * Exercici de la Sessi� 10
 *
 * Falta l'especificaci�
 ************************************************************************/
#include <iostream>
#include "Joc.h"

using namespace std;

bool opcioJ(Joc& joc)
{
    int posicioCarta, fila, columna;
    char pila;
    bool dentro = true;

    while (dentro)
    {
        cout << "ENTRA LA POSICIO DE LA CARTA QUE VOLS COL.LOCAR:" << endl;
        cin >> posicioCarta;

        if (joc.comprobarMaximCartes(posicioCarta))
        {
            dentro = false;

        }
        else
        {
            cout << "POSICIO NO VALIDA" << endl;
        }

    }
    dentro = true;


    while (dentro)
    {
        cout << "ENTRA LA POSICIO DEL TAULER ON VOLS COL.LOCAR LA CARTA:" << endl;
        cin >> fila >> columna;

        if (joc.comprobarPosicioTauler(fila, columna))
        {

            if (!joc.comprobarPosicioTaulerBuit(fila, columna))
            {
                cout << "JUGADA NO PERMESA" << endl;
                cout << "TORNA A INDICAR LA JUGADA" << endl;
                return false;

            }
            else
            {
                dentro = false;

            }

        }
        else
        {
            cout << "POSICIO NO VALIDA" << endl;
        }

    }
    dentro = true;

    while (dentro)
    {
        cout << "DE QUINA PILA VOLS ROBAR LA CARTA? (e/d)" << endl;
        cin >> pila;

        if (pila != 'e' && pila != 'd')
        {
            cout << "AQUESTA PILA NO EXISTEIX" << endl;

        }
        else
        {
            dentro = false;
        }

    }

    joc.jugarSenseInfluencia(posicioCarta, fila, columna, pila);
    return true;

}

void opcioI(Joc &joc)
{
    int posicioCarta, fila, columna, jugadorEscollit;
    char pila, magia, resposta;
    bool dentro = true;

    while (dentro)
    {
        cout << "ENTRA LA MAGIA QUE VOLS CEDIR:" << endl;
        cin >> magia;

        cout << "ENTRA EL JUGADOR A QUI LA VOLS CEDIR:" << endl;
        cin >> jugadorEscollit;

        if (!joc.jugarAmbInfluencia(magia, jugadorEscollit - 1))
        {
            cout << "MOVIMENT NO VALID" << endl;
            cout << "ENCARA T'INTERESSA CEDIR INFLUENCIA? (s/n)" << endl;
            cin >> resposta;

            if (resposta == 'n')
            {
                dentro = false;

            }

        }
        else
        {
            dentro = false;

        }
    }
    dentro = true;

    while (dentro)
    {
        if (opcioJ(joc))
        {
            dentro = false;
        }

    }

    //joc.jugarSenseInfluencia(posicioCarta, fila, columna, pila);
}

void opcioP(Joc &joc)
{
    joc.comprobarPiles();
}

void entrada_jugadors(Joc& joc)
{
    int jugadors;

    cout << "ENTRA EL NUMERO DE JUGADORS (2-4):" << endl;
    cin >> jugadors;

    while (jugadors < 2 || jugadors > 4)
    {
        if (jugadors < 2 || jugadors > 4)
        {
            cout << "NUMERO DE JUGADORS INCORRECTE" << endl;
        }

        cout << "ENTRA EL NUMERO DE JUGADORS (2-4):" << endl;
        cin >> jugadors;
    }

    joc.afegirJugador(jugadors);
}

void mostrarMenu()
{
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

    do
    {

        if (joc.permetTorn() || joc.ultimaVoltaCompletada())
        {

            if (!joc.ultimaVoltaCompletada())
            {
                cout << "\nTORN DE " << joc.tornActual().getNom() << "\n=========================\n" << endl;

                joc.mostrarTauler();

                joc.tornActual().mostrar();

                joc.mostrarMansOponents();

                joc.mostrarSeguidors();

                mostrarMenu();

                cout << "\nENTRA UNA OPCIO:" << endl;
                cin >> opcio;

                switch (opcio)
                {
                case 'I':
                    opcioI(joc);
                    joc.pasarTorn();
                    break;

                case 'J':
                    opcioJ(joc);
                    joc.pasarTorn();
                    break;

                case 'P':
                    opcioP(joc);
                    break;

                case 'F':
                    cout << "PARTIDA ABANDONADA" << endl;
                    break;

                default:
                    cout << "OPCIO NO DEFINIDA" << endl;
                    break;
                }

            }else {
                joc.posarInfluencia();


            }

        }
        else
        {
            joc.pasarTorn();
        }




    }
    while (opcio != 'F');

}
