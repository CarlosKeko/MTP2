#include "Videojoc.h"
#include "Data.h";
Videojoc::Videojoc()
{
    nomVideojoc = "default";
    uVenudes = 0;
    data = Data();
}

Videojoc::Videojoc(string nom, int u, Data da)
{
    nomVideojoc = nom;
    uVenudes = u;
    data = da;
}

bool Videojoc::operator>=(const Videojoc &o) {
    if (nomVideojoc >= o.nomVideojoc) {
        return true;

    }else {
        return false;
    }
}

bool Videojoc::operator==(const Videojoc &o) {
    if (nomVideojoc == o.nomVideojoc) {
        return true;

    }else {
        return false;
    }
}

void Videojoc::mostrar() {
    cout << nomVideojoc << ": " << uVenudes << " - ";
    data.mostrar(1);
    cout << endl;
}

void Videojoc::sumarPunts(Videojoc v) {
    uVenudes = uVenudes + v.uVenudes;
}

void Videojoc::novaData(Videojoc v) {

    if (data_mayor(v.data)) {
        data = v.data;
    }
}

bool Videojoc::data_mayor(Data d) {
    return data.es_menor(d);
}
