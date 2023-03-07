#include <iostream>
#include "Circumferencia.h"
using namespace std;

void demanar_dades(double &x, double &y, double &radi) {
    cout << "Entra el centre de la circumferencia, x y:" << endl;
    cin >> x >> y;
    cout << "Entra el radi [r>0]:" << endl;
    cin >> radi;
}

int main()
{
    double x, y, radi;
    Circumferencia circumAnterior, nouCircum;
    bool dentro = true;
    demanar_dades(x, y, radi);
    circumAnterior = Circumferencia(x, y, radi);
    int numCircum = 1;
    int parellesInteriors = 0;
    int parellesSecants = 0;

    while (dentro) {
        numCircum++;
        demanar_dades(x, y, radi);
        nouCircum = Circumferencia(x, y, radi);

        if (circumAnterior.es_interior(nouCircum)) {
            cout << "Interior" << endl;
            parellesInteriors++;

        }else if (circumAnterior.es_secant(nouCircum)){
            cout << "Secant" << endl;
            parellesSecants++;


        }else if (circumAnterior.es_exterior(nouCircum)) {
            cout << "Exterior" << endl;
            dentro = false;
        }
        circumAnterior = nouCircum;

    }

    cout << "Nombre total de circumferencies: " << numCircum << endl;
    cout << "Parelles de circumferencies interiors: " << parellesInteriors << endl;
    cout << "Parelles de circumferencies secants: " << parellesSecants << endl;

    return 0;
}
