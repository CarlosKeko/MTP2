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

        Llibre::Llibre(int c, string t, string a, string e, Data d) {
            codi = c;
            titol = t;
            autor = a;
            editorial = e;
            data = d;
        }
        //Pre: cert;
        //Post: Fa un objeto libro con los parametros pasados;


//CONSULTORS
        void Llibre::mostrar() {
            cout << "CODI: " << codi << endl;
            cout << "TITOL: " << titol << endl;
            cout << "AUTOR: " << autor << endl;
            cout << "EDITORIAL: " << editorial << endl;
            data.mostrar(2);
        }
        //Pre: Cert;
        //Post: Mostra per finestra les dades del llibre;

        bool Llibre::mes_recent(Data d) {
            return data.es_menor(d);
        }
        //Pre: Obtiene una fecha
        //Post: Devuelve true si la fecha entrada por parametro es mas reciente y falso si es al contrario;


//MODIFICADORS
