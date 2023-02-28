#ifndef VECTOR_H
#define VECTOR_H
#include <string>
using namespace std;

class Vector
{
    public:

        //CONSTRUCTOR
        Vector();
        //Pre: cert
        //Post: Vector component x = 1, y = 1, z = 1

        Vector(double x, double y, double z);
        //Pre: cert
        //Post: Asigna el valors X Y y Z a las variables

        //CONSULTORS
        void mostrar();
        // Pre: cert;
        // Post: mostra el vector

        bool vectorZ_positiu();
        // Pre: cert;
        // Post: Retorna si el varlos Z es positiu


        //MODIFICADORS
        void fer_suma(const Vector& v);
        // Pre: cert;
        // Post: fa la suma del vector

        void fer_mult(double valor);
        // Pre: cert;
        // Post: fa la multiplicacio del vector

        void fer_resta(const Vector& v);
        // Pre: cert;
        // Post: fa la resta del vector

        void fer_producte(const Vector& v);
        // Pre: cert;
        // Post: fa el producte vectorial del vector


    private:
        //ATRIBUTOS
        double vector_x;
        double vector_y;
        double vector_z;
};

#endif // VECTOR_H
