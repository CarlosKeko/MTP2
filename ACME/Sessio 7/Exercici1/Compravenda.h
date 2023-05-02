#ifndef COMPRAVENDA_H
#define COMPRAVENDA_H
#include <iostream>

using namespace std;

class Compravenda
{
    public:
        Compravenda();
        Compravenda(string n, int u, int h);

        mostrar();

    private:
        string nomClient;
        int uVideojocs;
        int horaPeticio;

};

#endif // COMPRAVENDA_H
