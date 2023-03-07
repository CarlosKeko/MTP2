#ifndef CIRCUMFERENCIA_H
#define CIRCUMFERENCIA_H
#include <iostream>

class Circumferencia
{
    public:
    //CONSTRUCTORS
        Circumferencia();
        //Pre: Cert;
        //Post: Posa el atributs per defecte x=1, y=1, radi=1;

        Circumferencia(double a_x, double a_y, double a_r);
        //Pre: Cert;
        //Post: Posa el atributs igual al valors pasats per parametre;

    //CONSULTORS
    bool es_interior(Circumferencia c);
    //Pre: Pasa un objecte Circumferencia per parametre;
    //Post: Dues circumferències són interiors si no tenen cap punt en comú i una d'elles es troba totalment continguda per l'altra, True si es interior, false altrament;

    bool es_exterior(Circumferencia c);
    //Pre: Pasa un objecte Circumferencia per parametre;
    //Post: Dues circumferències són exteriors si no tenen cap punt en comú i no són interiors. True si es exterior, false altrament;

    bool es_secant(Circumferencia c);
    //Pre: Pasa un objecte Circumferencia per parametre;
    //Post: Dues circumferències són secants si es tallen entre elles per dos punts. True si es secant, false altrament;

    //MODIFICADORS

    private:
    //ATRIBUTS
        double x, y;
        double radi;

    double calcular_distancia(double c_x, double c_y);
    //Pre: Pasa un objecte Circumferencia per parametre;
    //Post: Calcula la distancia entre el dos punts a una grafica i retorna el resultat;

};

#endif // CIRCUMFERENCIA_H
