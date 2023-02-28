#include "Joc.h"
#include <iostream>
#include <iomanip>

using namespace std;
//CONSTRUCTORS
Joc::Joc()
{
    nom = "DEFECTE";
    cooperatiu = 'n';
    any = 2000;
    duresa = 0;
    edatMinima = 0;
    numMaximJugadors = 0;
    numMinimJugadors = 0;
}
//Pre: Cert;
//Post: Post posa valors del objecte per defecte;

Joc::Joc(string n, char c, int a, double d, int e, int nMaxim, int nMinim) {
    nom = n;
    cooperatiu = c;
    any = a;
    duresa = d;
    edatMinima = e;
    numMaximJugadors = nMaxim;
    numMinimJugadors = nMinim;
}
//Pre: Ens dona els valors per parametre;
//Post: Posa el valors pasats per parametre als atributs del objecte;



//CONSULTORS
void Joc::mostrar() const {
    cout << "- NOM: " << nom << endl;
    cout << "- ANY: " << any << endl;
    if (cooperatiu == 'n') {
        cout << "- COOPERATIU: NO" << endl;
    }else {
        cout << "- COOPERATIU: SI" << endl;
    }
    std::cout << std::fixed;
    std::cout << std::setprecision( 2 );
    std::cout << "- DURESA: " << duresa << std::endl;
    cout << "- EDAT MINIMA: " << edatMinima << endl;
    cout << "- NUMERO DE JUGADORS: " << numMinimJugadors << " - " << numMaximJugadors << endl;
}

bool Joc::compleixRequisits(char coop, int edat, int numJugadors) const {
    if (coop == cooperatiu && edat >= edatMinima && numJugadors >= numMinimJugadors && numJugadors <= numMaximJugadors) {
        return true;

    }else {
        return false;
    }

}
//Pre: Ens dona valors si es coop o no, la edat i el numJugadors
//Post: True si el joc compleix el requisits, altrament false

bool Joc::compararDuresa(Joc j) const {
    if (duresa > j.duresa) {
        return true;

    }else {
        return false;

    }
}
//Pre: Entra un objecte Joc
//Post: True si el joc entrat per parametre te menys duresa, false altrament

bool Joc::compararAny(Joc j) const {
    if (any < j.any) {
        return true;

    }else {
        return false;

    }
}
//Pre: Entra un objecte Joc
//Post: True si el joc entrat per parametre es mes modern, false altrament


//MODIFICADORS
