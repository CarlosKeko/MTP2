#include "Circumferencia.h"
#include <iostream>
#include <cmath>

using namespace std;

    //CONSTRUCTORS
    Circumferencia::Circumferencia() {
        x = 1;
        y = 1;
        radi = 1;
    }
    //Pre: Cert;
    //Post: Posa el atributs per defecte x=1, y=1, radi=1;

    Circumferencia::Circumferencia(double a_x, double a_y, double a_r) {
        x = a_x;
        y = a_y;
        radi = a_r;
    }
    //Pre: Cert;
    //Post: Posa el atributs igual al valors pasats per parametre;

    //CONSULTORS
    bool Circumferencia::es_interior(Circumferencia c) {
        if (calcular_distancia(c.x, c.y) < radi - c.radi || calcular_distancia(c.x, c.y) < c.radi - radi) {
            return true;

        }else {
            return false;
        }
    }
    //Pre: Pasa un objecte Circumferencia per parametre;
    //Post: Dues circumferències són interiors si no tenen cap punt en comú i una d'elles es troba totalment continguda per l'altra, True si es interior, false altrament;

    bool Circumferencia::es_exterior(Circumferencia c) {
        if (calcular_distancia(c.x, c.y) > radi + c.radi) {
            return true;

        }else {
            return false;
        }
    }
    //Pre: Pasa un objecte Circumferencia per parametre;
    //Post: Dues circumferències són exteriors si no tenen cap punt en comú i no són interiors. True si es exterior, false altrament;

    bool Circumferencia::es_secant(Circumferencia c) {
        if (calcular_distancia(c.x, c.y) < radi + c.radi) {
            return true;

        }else {
            return false;
        }
    }
    //Pre: Pasa un objecte Circumferencia per parametre;
    //Post: Dues circumferències són secants si es tallen entre elles per dos punts. True si es secant, false altrament;

    double Circumferencia::calcular_distancia(double c_x, double c_y) {
        double c1 = c_x - x;
        double c2 = c_y - y;
        return sqrt(pow(c1, 2) + pow(c2, 2));

    }
    //Pre: Pasa un objecte Circumferencia per parametre;
    //Post: Calcula la distancia entre el dos punts a una grafica i retorna el resultat;

    //MODIFICADORS
