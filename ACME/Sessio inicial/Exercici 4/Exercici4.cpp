//**********************************************************//
//    Exercici.    Triangle de Pascal (o de Tartaglia)     //
//**********************************************************//

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;

const int MAX = 100;
typedef int Matriu_enter[MAX][MAX]; // defininció del tipus Matriu_enter, matrius de MAX x MAX enters

// Implementació de subprogrames (aquí)

void crear_triangle(Matriu_enter triang, int n)
{
    for (int linea = 0; linea < n; linea++) {
        int numero = 1;

        for (int j = 0; j <= linea; j++) {
            if (j == 0 || j == linea) {
                triang[linea][j] = 1;

            } else {
                if (linea - 1 > 0) {
                    triang[linea][j] = triang[linea - 1][j] + triang[linea - 1][j - 1];

                }else {
                    triang[linea][j] = 1;
                    
                }
            }
        }
    }
}

void mostrar_triangle(Matriu_enter triang, int n)
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (triang[i][j] != 0) {
                cout << triang[i][j] << "   ";

            }

        }
        cout << "" << endl;
    }
}

int main()
{
    Matriu_enter triangle;
    int n;

    cout << "Nombre de files del triangle de Pascal: " << endl;
    cin >> n;

    crear_triangle(triangle, n);
    cout << "Triangle de Pascal: " << endl;
    mostrar_triangle(triangle, n);

    return 0;
}