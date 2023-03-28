#include <iostream>

using namespace std;

void entrar_cadenes(string *t, int n) {
// Pre: n > 0 i la "taula" t té espai per n cadenes
// Post: s'han llegit n cadenes de teclat i s'han posat a la "taula" t
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }


}
void mostrar_cadenes_invers(string *t, int n) {
// Pre: n > 0 i mida(t) = n
// Post: s'han mostrat les n cadenes de la "taula" t, d'n-1 a 0
    cout << "ORDRE INVERS:" << endl;
    string *p = t;

    for (int i = 0; i < n; i++) {
        if (i < n - 1) {
            cout << *(p + n - (i + 1)) << ", ";

        }else {
            cout << *(p + n - (i + 1)) << endl;

        }
    }
}

int main()
{
    int numCadenes;
    cout << "QUANTES CADENES TENS (>0):" << endl;
    cin >> numCadenes;

    while (numCadenes <= 0) {
        cout << "QUANTES CADENES TENS (>0):" << endl;
        cin >> numCadenes;
    }

    string t[numCadenes];
    cout << "ENTRA LES CADENES:" << endl;
    entrar_cadenes(t, numCadenes);

    mostrar_cadenes_invers(t, numCadenes);

    return 0;
}
