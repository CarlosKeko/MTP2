#include <iostream>
#include <iomanip>

using namespace std;

void entrar_valors(int *t, int n)
{
// Pre: n > 0 i la "taula" t té espai per n valors; Post: ...
// es pot usar el codi d’aquesta sessió com a base
    cout << "ENTRA LES PUNTUACIONS:" << endl;
    int *p = t;
    for (int i = 0; i < n; i++)
    {
        cin >> *(p);
        p++;
    }

}
void mostrar_memorables(int *t, int n, int l)
{
// Pre: n > 0 i mida(t)=n; Post: ...
// es pot usar el codi d’aquesta sessió com a base

    int *p = t;
    cout << "PARTITS MEMORABLES:" << endl;
    double memorables = 0;

    for (int i = 0; i < n; i++) {
        if (*(p + i) >= l) {
            cout << "PARTIT " << i + 1 << ": " << *(p + i) << endl;
            memorables++;
        }

    }
    double percen = (memorables * 100) / n;

    cout << std::fixed << std::setprecision(1) << "EL " << percen << "% DELS PARTITS HAN SIGUT MEMORABLES" << endl;

}

int main()
{
    int numCadenes, l;
    cout << "QUANTES DADES TENS:" << endl;
    cin >> numCadenes;

    while (numCadenes <= 0 && numCadenes > 100)
    {
        cout << "QUANTES DADES TENS:" << endl;
        cin >> numCadenes;
    }

    int t[numCadenes];

    entrar_valors(t, numCadenes);
    cout << "LLINDAR:" << endl;
    cin >> l;
    mostrar_memorables(t, numCadenes, l);

    return 0;
}
