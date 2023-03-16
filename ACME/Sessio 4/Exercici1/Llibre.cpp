#include "Llibre.h"
#include <iostream>
#include "Data.h"

using namespace std;

//CONSTRUCTORS
Llibre::Llibre()
{
    codi = 0;
    titol = "defecto";
    autor = "defecto";
    editorial = "defecto";
    data = Data();
}
//Pre: cert;
//Post: crea el objeto libro con parametros por defecto;

Llibre::Llibre(int c, string t, string a, string e, Data d)
{
    codi = c;
    titol = t;
    autor = a;
    editorial = e;
    data = d;
}
//Pre: cert;
//Post: Fa un objeto libro con los parametros pasados;

Llibre::Llibre(int c)
{
    codi = c;
    titol = "defecto";
    autor = "defecto";
    editorial = "defecto";
    data = Data();
}
//Pre: cert;
//Post: Fa un objeto libro con los parametros pasados y por defecto;


//CONSULTORS
void Llibre::mostrar(int valor) const
{


    if (valor == 1) {
        cout << codi << " " << titol << " (" << autor << "), " << editorial << " - ";
        data.mostrar(valor);
        cout << endl;

    }else {
        cout << "CODI: " << codi << endl;
        cout << "TITOL: " << titol << endl;
        cout << "AUTOR: " << autor << endl;
        cout << "EDITORIAL: " << editorial << endl;
        data.mostrar(valor);
    }
}
//Pre: Cert;
//Post: Mostra per finestra les dades del llibre;

bool Llibre::mes_recent(Data d)
{
    return data.es_menor(d);
}
//Pre: Obtiene una fecha
//Post: Devuelve true si la fecha entrada por parametro es mas reciente y falso si es al contrario;

bool Llibre::operator == (const Llibre &llibre) const
{
    if (codi == llibre.codi && titol == llibre.titol)
    {
        return true;

    }
    else
    {
        return false;
    }
}
//Pre: Pasa un llibre;
//Post: Cert si es igual, altrament false;

bool Llibre::operator < (const Llibre &llibre) const
{
    if (titol < llibre.titol)
    {
        return true;

    }
    else
    {
        return false;
    }

}
//Pre: Pasa un llibre per parametre;
//Post: Cert si es mes petit que el llibre pasat per paramentre, altrament false;

bool Llibre::operator > (const Llibre &llibre) const {
    if (titol > llibre.titol || titol == llibre.titol && codi > llibre.codi) {
        return true;

    }else {
        return false;
    }
}
//Pre: Pasa un llibre per parametre;
//Post: Cert si es mes gran que el llibre pasat per paramentre, altrament false;

bool Llibre::comparar_autor(string aut) const
{
    if (autor == aut)
    {
        return true;

    }
    else
    {
        return false;
    }
}
//Pre: Entra un string per parametre;
//Post: compara si es el mateix autor, return true si es cert, altrament false;


bool Llibre::comparar_codi(int cod) const
{
    if (codi == cod)
    {
        return true;

    }
    else
    {
        return false;
    }
}
//Pre: Entra un string per parametre;
//Post: compara si es el mateix codi, return true si es cert, altrament false;



//MODIFICADORS
bool Llibre::llegir()
{
    cout << "CODI: " << endl;
    cin >> codi;

    if (codi != 0)
    {
        cout << "TITOL: " << endl;
        cin >> titol;
        cout << "AUTOR: " << endl;
        cin >> autor;
        cout << "EDITORIAL: " << endl;
        cin >> editorial;
        cout << "DATA DE PUBLICACIO (AAAAMMDD): " << endl;
        data.llegir(1);
        return true;

    }
    else
    {
        return false;

    }
} //Pre: -; Post: llegeix un llibre, retorna fals si el codi és 0
