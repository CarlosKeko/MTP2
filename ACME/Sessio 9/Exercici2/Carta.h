#ifndef CARTA_H
#define CARTA_H

using namespace std;

class Carta
{
    public:
        //CONSTRUCTORS
        Carta();

        Carta(char m, char g, int i);

        //CONSULTORS
        void mostrar();


        //MODIFICADORS

    private:
        char magia;
        char germandat;
        int influencia;

};

#endif // CARTA_H
