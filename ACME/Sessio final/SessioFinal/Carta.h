#ifndef CARTA_H
#define CARTA_H

using namespace std;

class Carta
{
    public:
        //CONSTRUCTORS
        Carta();

        Carta(char m, char g, int i);

        //OPERATORS

        bool operator>=(const Carta &o);

        bool operator==(const Carta &o);

        //CONSULTORS
        void mostrar(int format);

        void mostrarMagia(int format);

        int getInfluencia();

        bool cartaValida();

        bool coincideixMagiaGermandat(Carta c);

        bool esCopia(Carta c);


        //MODIFICADORS

    private:
        char magia;
        char germandat;
        int influencia;

};

#endif // CARTA_H
