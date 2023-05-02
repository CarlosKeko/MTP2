#include "Compravenda.h"
#include <iostream>

using namespace std;

Compravenda::Compravenda()
{
    nomClient = "Default";
    uVideojocs = 0;
    horaPeticio = 0;
}

Compravenda::Compravenda(string n, int u, int h)
{
    nomClient = n;
    uVideojocs = u;
    horaPeticio = h;
}

Compravenda::mostrar() {
    cout << "[" << horaPeticio << "]: " << nomClient << "->" << uVideojocs << " UNITATS" << endl;
}

