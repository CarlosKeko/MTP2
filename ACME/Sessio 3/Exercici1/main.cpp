#include <iostream>
#include "Data.h"
#include "Llibre.h"

using namespace std;

bool llegir(int &c, string &t, string &a, string &e, Data &data1) {
    cout << "CODI: " << endl;
    cin >> c;

    if (c == 0) {
        return false;
    }

    cout << "TITOL: " << endl;
    cin >> t;
    cout << "AUTOR: " << endl;
    cin >> a;
    cout << "EDITORIAL:  " << endl;
    cin >> e;
    cout << "DATA DE PUBLICACIO (AAAAMMDD):" << endl;
    data1.llegir(1);

    if (c != 0) {
        return true;
    }

}

int main()
{

    int codi;
    int contador = 0;
    string titol, autor, editorial;
    Data data1;
    Llibre llibre1;
    cout << "ENTRA ELS LLIBRES (CODI:0 PER ACABAR)" << endl;
    llegir(codi, titol, autor, editorial, data1);
    llibre1 = Llibre(codi, titol, autor, editorial, data1);

    while (codi != 0) {
        llegir(codi, titol, autor, editorial, data1);
        if (llibre1.mes_recent(data1)) {
            llibre1 = Llibre(codi, titol, autor, editorial, data1);
        }
        contador++;

    }

    cout << "HI HA " << contador << " LLIBRES" << endl;
    cout << "EL MES RECENT ES:" << endl;
    llibre1.mostrar();

    return 0;
}
