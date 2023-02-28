#include <iostream>
#include "Vector.h"

using namespace std;

void preparar_components(double &x, double &y, double &z) {
    cout << "ENTRAR COMPONENT X:" << endl;
    cin >> x;

    cout << "ENTRAR COMPONENT Y:" << endl;
    cin >> y;

    cout << "ENTRAR COMPONENT Z:" << endl;
    cin >> z;

}

void preparar_suma(Vector &vector1, int &operacions) {
    double xAux, yAux, Zaux;
    preparar_components(xAux, yAux, Zaux);
    Vector vectorAux(xAux, yAux, Zaux);

    vector1.fer_suma(vectorAux);
    vector1.mostrar();
    operacions++;
}

void preparar_resta(Vector &vector1, int &operacions) {
    double xAux, yAux, Zaux;
    preparar_components(xAux, yAux, Zaux);
    Vector vectorAux(xAux, yAux, Zaux);

    vector1.fer_resta(vectorAux);
    vector1.mostrar();
    operacions++;
}

void preparar_multiplicacio(Vector &vector1, int &operacions) {
    double valor;
    cout << "ENTRAR UN VALOR REAL:" << endl;
    cin >> valor;

    vector1.fer_mult(valor);
    vector1.mostrar();
    operacions++;
}

void preparar_vectorial(Vector &vector1, int &operacions) {
    double xAux, yAux, Zaux;
    preparar_components(xAux, yAux, Zaux);
    Vector vectorAux(xAux, yAux, Zaux);

    vector1.fer_producte(vectorAux);
    vector1.mostrar();
    operacions++;
}

int main()
{
    char opcio;
    double x, y, z;
    int i = 0;
    int operacions = 0;
    int hemisferiNord = 0;

    preparar_components(x, y, z);
    Vector vector1(x, y, z);

    while(i < 5 && opcio != 'f') {
        cout << "ENTRAR OPERACIO (s, r, m, v, f):" << endl;
        cin >> opcio;

        if (opcio == 's') {
            preparar_suma(vector1, operacions);

        }else if (opcio == 'r') {
            preparar_resta(vector1, operacions);

        }else if (opcio == 'm') {
            preparar_multiplicacio(vector1, operacions);

        }else if (opcio == 'v') {
            preparar_vectorial(vector1, operacions);

        }

        if (vector1.vectorZ_positiu() && opcio != 'f') {
            hemisferiNord++;
        }

        i++;
    }

    cout << "NOMBRE D'OPERACIONS:" << operacions << endl;
    cout << "RESULTATS A L'HEMISFERI NORD:" << hemisferiNord << endl;

    return 0;
}
