#include <iostream>
#include "Vector.h"
#include <iomanip>

using namespace std;

// CONSTRUCTORS
Vector::Vector()
{
    //Pre: Cert;
    //Post: Per defect x = 1, y = 1, z = 1;
    vector_x = 1;
    vector_y = 1;
    vector_z = 1;

}

Vector::Vector(double x, double y, double z)
{
    //Pre: Cert;
    //Post: Posa el valors de x y z de les variables per parametre;
    vector_x = x;
    vector_y = y;
    vector_z = z;
}


//CONSULTORS
void Vector::mostrar()
{
    std::cout << std::fixed;
    std::cout << std::setprecision( 2 );
    std::cout  << "RESULTAT: (" << vector_x << ", " << vector_y << ", " << vector_z << ")" << std::endl;
}
//Pre: Cert
//Post: Da un cout con el resultado del objeto

bool Vector::vectorZ_positiu() {
    if (vector_z > 0) {
        return true;

    }else {
        return false;
    }
}
// Pre: cert;
// Post: Retorna true si el varlos Z es positiu, altrament fals

//MODIFICADORS
void Vector::fer_suma(const Vector& v) {
    vector_x = vector_x + v.vector_x;
    vector_y = vector_y + v.vector_y;
    vector_z = vector_z + v.vector_z;
}
// Pre: cert;
// Post: fa la suma del vector

void Vector::fer_mult(double valor) {
    vector_x = vector_x * valor;
    vector_y = vector_y * valor;
    vector_z = vector_z * valor;
}
// Pre: cert;
// Post: fa la multiplicacio del vector

void Vector::fer_resta(const Vector& v) {
    vector_x = vector_x - v.vector_x;
    vector_y = vector_y - v.vector_y;
    vector_z = vector_z - v.vector_z;
}
// Pre: cert;
// Post: fa la resta del vector

void Vector::fer_producte(const Vector& v) {
    double aux1 = vector_x;
    double aux2 = vector_y;
    double aux3 = vector_z;

    vector_x = (aux2 * v.vector_z) - (v.vector_y * aux3);
    vector_y = -((aux1 * v.vector_z) - (v.vector_x * aux3));
    vector_z = (aux1 * v.vector_y) - (v.vector_x * aux2);

}
// Pre: cert;
// Post: fa el producte vectorial del vector


