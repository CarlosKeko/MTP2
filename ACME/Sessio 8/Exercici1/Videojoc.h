#ifndef VIDEOJOC_H
#define VIDEOJOC_H
#include "Data.h"
#include <iostream>>


class Videojoc
{
    public:
        Videojoc();

        Videojoc(string nom, int u, Data da);

        bool operator>=(const Videojoc &o);

        bool operator==(const Videojoc &o);

        void mostrar();

        void sumarPunts(Videojoc v);

        void novaData(Videojoc v);

        bool data_mayor(Data d);


    private:
        string nomVideojoc;
        int uVenudes;
        Data data;
};

#endif // VIDEOJOC_H
