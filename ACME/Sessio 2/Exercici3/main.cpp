#include <iostream>
#include "Joc.h"

using namespace std;

const string EOS = " ";

int main()
{
    string nom = "";
    char coop, cooperatiu;
    int edat, numJugadors, any, edatMinima, numMinim, numMaxim;
    int requisits = 0;
    double duresa;
    Joc jocDuresa;
    Joc jocModern;
    bool primeraVez = true;

    cout << "REQUISITS" << endl;
    cout << "COOPERATIU:" << endl;
    cin >> coop;

    cout << "EDAT:" << endl;
    cin >> edat;

    cout << "NUMERO DE JUGADORS:" << endl;
    cin >> numJugadors;

    cout << "ENTRA LA INFORMACIO DELS JOCS ACABADA AMB #" << endl;
    cout << "NOM, ANY, COOPERATIU (s/n), DURESA, EDAT MINIMA, NUMERO MINIM DE JUGADORS, NUMERO MAXIM DE JUGADORS" << endl;

    while (nom != "#")
    {
        cin >> nom;
        if (nom != "#") {
            cin >> any >> cooperatiu >> duresa >> edatMinima >> numMinim >> numMaxim;
            Joc joc (nom, cooperatiu, any, duresa, edatMinima, numMaxim, numMinim);

            if (joc.compleixRequisits(coop, edat, numJugadors)) {
                if (primeraVez) {
                    jocDuresa = joc;
                    jocModern = joc;
                    primeraVez = false;

                }else {
                    if (jocDuresa.compararDuresa(joc)) {
                        jocDuresa = joc;
                    }

                    if (jocModern.compararAny(joc)) {
                        jocModern = joc;
                    }

                }

                requisits++;
            }

        }
    }

    if (requisits == 0) {
        cout << "NO S'HA TROBAT CAP JOC AMB LES CARACTERISTIQUES REQUERIDES" << endl;

    }else {
        cout << "HI HA " << requisits << " JOCS AMB LES CARACTERISTIQUES REQUERIDES" << endl;
        cout << "EL QUE TE MENYS DURESA ES:" << endl;
        jocDuresa.mostrar();
        cout << "EL MES MODERN ES:" << endl;
        jocModern.mostrar();


    }

    return 0;
}
