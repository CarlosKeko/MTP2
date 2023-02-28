#ifndef JOC_H
#define JOC_H
#include <iostream>

using namespace std;
class Joc
{
    public:
    //CONSTRUCTORS
        Joc();
        //Pre: Cert;
        //Post: Post posa valors del objecte per defecte;

        Joc(string n, char c, int a, double d, int e, int nMaxim, int numMinim);
        //Pre: Ens dona els valors per parametre;
        //Post: Posa el valors pasats per parametre als atributs del objecte;

    //CONSULTORS
        void mostrar() const;
        //Pre: Cert;
        //Post: Mostra els valors del objecte per finestra;

        bool compleixRequisits(char coop, int edat, int numJugadors) const;
        //Pre: Ens dona valors si es coop o no, la edat i el numJugadors
        //Post: True si el joc compleix el requisits, altrament false

        bool compararDuresa(Joc j) const;
        //Pre: Entra un objecte Joc
        //Post: True si el joc entrat per parametre te menys duresa, false altrament

        bool compararAny(Joc j) const;
        //Pre: Entra un objecte Joc
        //Post: True si el joc entrat per parametre es mes modern, false altrament


    //MODIFICADORS


    private:
        //ATRIBUTS
        string nom;
        char cooperatiu;
        int any;
        double duresa;
        int edatMinima;
        int numMinimJugadors;
        int numMaximJugadors;


};

#endif // JOC_H
