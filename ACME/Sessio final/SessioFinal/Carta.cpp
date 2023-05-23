#include "Carta.h"
#include <iostream>

using namespace std;

Carta::Carta()
{
    magia = ' ';
    germandat = ' ';
    influencia = 0;

}

Carta::Carta(char m, char g, int i) {
    magia = m;
    germandat = g;
    influencia = i;
}

//CONSULTORS

void Carta::mostrar(int format) {
    if (format == 1) {
        if (magia == ' ' || germandat == ' ' || influencia == 0) {
            cout << "[   ] ";

        }else {
            cout << "[" << magia << influencia << germandat << "] ";

        }


    }else if (format == 2){
        if (magia == ' ' || germandat == ' ' || influencia == 0) {
            cout << "[   ]";

        }else {
            cout << "[" << magia << influencia << germandat << "]";

        }

    }else {
        if (magia == ' ' || germandat == ' ' || influencia == 0) {
            cout << "[   ]";

        }else {
            cout << "[" << magia << "] ";

        }

    }
}

void Carta::mostrarMagia(int format) {
    if (format == 1) {
        cout << "[" << magia << "] ";

    }else {
        cout << "[" << magia << "]";
    }

}

bool Carta::operator>=(const Carta &o) {
    if (magia >= o.magia) {
        return true;

    }else {
        return false;
    }
}

bool Carta::cartaValida() {
    if (magia != ' ' && germandat != ' ' && influencia != 0) {
        return true;

    }else {
        return false;

    }
}

bool Carta::operator==(const Carta &o) {
    /*if (nomVideojoc == o.nomVideojoc) {
        return true;

    }else {
        return false;
    }*/
    return false;
}

int Carta::getInfluencia() {
    return influencia;
}

bool Carta::coincideixMagiaGermandat(Carta c) {
    if (magia == c.magia || germandat == c.germandat) {
        cout << "SI QUE COINCIDEIX MAGIA O GERMANDAT" << endl;
        return true;

    }else {
        cout << "NO COINCIDEIX MAGIA O GERMANDAT" << endl;
        return false;

    }
}

bool Carta::esCopia(Carta c) {
    if (magia == c.magia && germandat == c.germandat && influencia == c.influencia) {
        cout << "ES COPIA" << endl;
        return true;

    }else {
        cout << "NO ES COPIA" << endl;
        return false;

    }
}

bool Carta::coincideixGermandat(Carta c) {
    if (germandat == c.germandat) {
        return true;

    }else {
        return false;

    }
}

bool Carta::coincideixMagia(char c) {
    if (magia == c) {
        return true;

    }else {
        return false;

    }
}
