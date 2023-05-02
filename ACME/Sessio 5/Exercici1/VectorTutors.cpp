#include "VectorTutors.h"

using namespace std;

//CONSTRUCTOR
VectorTutors::VectorTutors()
{
    a_n = 0;
}

//CONSULTORS

void VectorTutors::mostrar() const
{
    if (vec_tutors != 0)
    {
        for (int i = 0; i < vec_tutors; i++)
        {
            vec_tutors[i].mostrar(1);
        }
    }


}
// Pre: --; Post: mostra tots els tutors del vector numerats de 0 al nombre depunts-1


//MODIFICADORS
bool Biblioteca::afegir(Tutor& tutor)
{
    int pos = cercar(tutor);

    if (pos == NO_TROBAT)
    {
        if (a_nDades < MAX_LLIBRES)
        {
            inser_tutor_privat(tutor);
            return true;
        }
        else
            cout << "NO HI HA CABUDA PER A MES LLIBRES" << endl;
    }

    return false;
}
// Pre: nombre_llibres()<MAX; Post: s'ha inserit ordenadament un llibre en el vector de llibr
