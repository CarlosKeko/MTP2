#include <iostream>
#include "Baralla.h"

using namespace std;

int main()
{
    int llavor;
    int n_valors;
    int rang;

    do {
        cout << "ENTRA LA LLAVOR (>0):" << endl;
        cin >> llavor;
    } while (llavor <= 0);

    do {
        cout << endl << "ENTRA EL NOMBRE DE VALORS ALEATORIS (>=0):" << endl;
        cin >> n_valors;
    } while (n_valors < 0);

    do {
        cout << endl << "ENTRA EL RANG DE VALORS (>0):" << endl;
        cin >> rang;
    } while (rang <= 0);

    Baralla baralla(llavor);

    cout << endl << "VALORS GENERATS ALEATORIAMENT:" << endl;
    for (int i = 0; i < n_valors; i++) {
        cout << baralla.aleatori(rang) << " ";
    }
    cout << endl;

    return 0;
}
