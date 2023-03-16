/****************************************************
 * Codi de l'exercici Llistat de llibres
 *
 * Falta l'especificació del programa
 ****************************************************/

#include <iostream>
#include "Biblioteca.h" // Ull amb el nom del fitxer
#include "Llibre.h"     // Ull amb el nom del fitxer


using namespace std;


// Pre: cert;
// Post: s'ha afegit un llibre (si no és repetit)
void afegir_llibre_1(Biblioteca& b)
{
    Llibre llibre;

    cout << "ENTRA UN LLIBRE" << endl;
    llibre.llegir();

    if (not b.afegir(llibre))
    {
        cout << "JA EXISTEIX UN LLIBRE AMB AQUEST TITOL I CODI" << endl;
    }
}


// Pre: cert;
// Post: s'afegeixen diversos llibres (si no són repetits)
void afegir_llibre_n(Biblioteca& b)
{
    Llibre llibre;

    cout << "ENTRA UN LLIBRE (CODI " << Llibre::CODI_FI << " PER ACABAR)"
         << endl;
    bool continuar = llibre.llegir();
    while (continuar)
    {
        if (not b.afegir(llibre))
        {
            cout << "JA EXISTEIX UN LLIBRE AMB AQUEST TITOL I CODI" << endl;
        }
        continuar = llibre.llegir();
    }
}


// Pre: cert (el paràmetre es passa per referència constant);
// Post: es fa un llistat dels llibres
void mostrar_llistat(const Biblioteca& b)
{
    cout << "LLISTAT DELS LLIBRES" << endl;
    b.mostrar();
}


// Pre: cert (el paràmetre es passa per referència constant);
// Post: es fa un llistat dels llibres d'un autor entrat per teclat
void mostrar_llistat_autor(const Biblioteca& b)
{
    string autor;

    cout << "LLISTAT DELS LLIBRES PER AUTOR" << endl;
    cout << "AUTOR:" << endl;
    cin >> autor;

    b.mostrar_per_autor(autor);
}


// Pre: cert;
// Post: s'elimina el llibre amb el codi entrat per teclat
void eliminar_llibre(Biblioteca& b)
{
    int codi;

    cout << "ELIMINA UN LLIBRE" << endl;
    cout << "CODI:" << endl;
    cin >> codi;

    if (not b.eliminar(codi))
    {
        cout << "NO S'HA TROBAT CAP LLIBRE AMB AQUEST CODI" << endl;
    }
}


// Pre: cert;
// Post: es mostren les opcions per pantalla
void menu()
{
    cout << "OPCIONS:" << endl;
    cout << "1: ENTRAR UN LLIBRE" << endl;
    cout << "2: ENTRAR DIVERSOS LLIBRES" << endl;
    cout << "3: LLISTAR ELS LLIBRES" << endl;
    cout << "4: LLISTAR ELS LLIBRES PER AUTOR" << endl;
    cout << "5: ELIMINAR UN LLIBRE" << endl;
    cout << "9: MOSTRAR EL MENU D'OPCIONS" << endl;
    cout << "0: SORTIR DEL PROGRAMA" << endl;
}


int main()
{
    int opcio;
    Biblioteca b;

    menu();
    cout << "OPCIO:" << endl;
    cin >> opcio;
    while (opcio != 0)
    {
        if (opcio == 1)
        {
            afegir_llibre_1(b);
        }
        else if (opcio == 2)
        {
            afegir_llibre_n(b);
        }
        else if (opcio == 3)
        {
            mostrar_llistat(b);
        }
        else if (opcio == 4)
        {
            mostrar_llistat_autor(b);
        }
        else if (opcio == 5)
        {
            eliminar_llibre(b);
        }
        else   // if (opcio == 9)
        {
            menu();
        }

        cout << "OPCIO:" << endl;
        cin >> opcio;
    }

    cout << "FINAL DEL PROGRAMA" << endl;

    return 0;
}
