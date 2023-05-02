#include <iostream>
#include "Cuacompravenda.h"
#include "Compravenda.h"

using namespace std;

void afegirPeticio(int horaIn, Cuacompravenda& cua) {
    string nomClient;
    int nUnitats, horaInici;

    cout << "NOM CLIENT:" << endl;
    cin >> nomClient;

    cout << "NOMBRE D'UNITATS:" << endl;
    cin >> nUnitats;

    cout << "HORA PETICIO:" << endl;
    cin >> horaInici;

    if (horaInici < horaIn) {
        cout << "PETICIO FETA ABANS D'HORA, TORNEU MES TARD" << endl;

    }else {
        Compravenda compraVenda(nomClient, nUnitats, horaInici);
        cua.encua(compraVenda);
        cout << "PETICIO ENREGISTRADA CORRECTAMENT" << endl;

    }

}


void mostrarPeticions(Cuacompravenda& cua) {
    while (!cua.buida()) {

    }
}


void mostrarMenu() {
    cout << "OPCIONS:" << endl;
    cout << "1: AFEGIR UNA PETICIO" << endl;
    cout << "2: PROCESSAR SEGUENT PETICIO" << endl;
    cout << "3: MOSTRAR PETICIONS PENDENTS" << endl;
    cout << "4: MOSTRAR EL MENU D'OPCIONS" << endl;
    cout << "0: FINALITZAR" << endl;
}

int main()
{
    int uDisponibles, vMaxima, hInici;
    int opcio = 1;
    Cuacompravenda cua;

    cout << "COMPRAVENDA DEL VIDEOJOC" << endl;

    do {
        cout << "UNITATS DISPONIBLES A LA BOTIGA:" << endl;
        cin >> uDisponibles;


    } while(uDisponibles <= 0);

    do {
        cout << "VENDA MAXIMA PER OPERACIO:" << endl;
        cin >> vMaxima;


    } while(vMaxima <= 0);

    cout << "HORA D'INICI DE LES OPERACIONS:" << endl;
    cin >> hInici;

    mostrarMenu();
    cout << "OPCIO:" << endl;
    cin >> opcio;

    while (opcio != 0) {

        if (opcio == 1) {
            afegirPeticio(hInici, cua);

        }else if (opcio == 2) {

        }else if (opcio == 3) {

        }else if (opcio == 4) {

        }else if (opcio == 0){

        }else {
            cout << "OPCIO INCORRECTA" << endl;
        }
        cout << "OPCIO:" << endl;
        cin >> opcio;
    }

    return 0;
}
