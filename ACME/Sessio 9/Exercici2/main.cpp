/************************************************************************
 * Exercici de la Sessió 9
 *
 * Falta l'especificació
 ************************************************************************/

#include <iostream>
#include "Baralla.h"
#include "PilaCartes.h"
#include "Carta.h"

using namespace std;

void omplir_piles(Baralla& baralla, PilaCartes& pila_esquerra, PilaCartes& pila_dreta)
{
    // Cal completar-ho
    baralla.afegirCartaPila(pila_esquerra, pila_dreta);

}

int main()
{
    int llavor;

    cout << "ENTRA LA LLAVOR:" << endl;
    cin >> llavor;

    Baralla baralla(llavor);
    cout << endl << "BARALLA INICIAL:" << endl;
    // Es mostra la baralla inicial
    baralla.mostrar();

    baralla.barrejar();
    cout << endl << "BARALLA INICIAL BARREJADA:" << endl;
    // Es mostra la baralla barrejada
    baralla.mostrar();

    Baralla baralla_copia(baralla);
    cout << endl << "BARALLA COPIA:" << endl;
    // Es mostra una còpia de la baralla inicial barrejada
    baralla_copia.mostrar();

    PilaCartes pila_esquerra;
    PilaCartes pila_dreta;
    // S'omplen les piles
    omplir_piles(baralla, pila_esquerra, pila_dreta);

    cout << endl << "PILA ESQUERRA:" << endl;
    pila_esquerra.mostrar();
    cout << endl << "PILA DRETA:" << endl;
    pila_dreta.mostrar();

    PilaCartes pila_esquerra_copia(pila_esquerra);
    cout << endl << "PILA ESQUERRA COPIA:" << endl;
    // Es mostra una còpia de la pila esquerra
    pila_esquerra_copia.mostrar();

    PilaCartes pila_dreta_copia = pila_dreta;
    cout << endl << "PILA DRETA COPIA:" << endl;
    // Es mostra una còpia de la pila dreta
    pila_dreta_copia.mostrar();

    cout << endl << "BARALLA INICIAL BARREJADA:" << endl;
    // Es mostra la baralla barrejada per veure que ara és buida
    baralla.mostrar();

    cout << endl << "BARALLA COPIA:" << endl;
    // Es mostra la còpia de la baralla barrejada per veure que segueix plena
    baralla_copia.mostrar();

    return 0;
}
