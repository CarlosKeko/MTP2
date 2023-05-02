#ifndef VECTORTUTORS_H
#define VECTORTUTORS_H

using namespace std;

class VectorTutors
{
    public:

        //CONSTRUCTORS
        VectorTutors();


        //CONSULTORS
        void mostrar() const;
        // Pre: --; Post: mostra tots els tutors del vector numerats de 0 al nombre depunts-1


        //MODIFICADORS
        bool afegir(Tutor& tutor);
        // Pre: nombre_llibres()<MAX; Post: s'ha inserit ordenadament un tutor en el vector de tutors;

    private:
        //CONSTANTS
        static const int NO_TROBAT = -1;
        const int MAX_T = 100;


        Tutor vec_tutors[MAX_T];
        int a_n;

        //FUNCIONS

        int cercar(const Tutor& tutor);
        //Pre: codi del llibre;
        //Post: retorna bool si el troba altrament false;


        void inser_tutor_privat(Tutor tutor);
        // Pre: nombre_llibres()<MAX; Post: s'ha inserit ordenadament un llibre en el vector de llibres;
};

#endif // VECTORTUTORS_H
