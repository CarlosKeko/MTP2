#ifndef SEGUIDORS_H
#define SEGUIDORS_H
#include "Carta.h"


class Seguidors
{
public:
    static const int numMagies = 6;


    //CONSTRUCOTRS
    Seguidors();
    Seguidors(const Seguidors &o);
    ~Seguidors();
    Seguidors &operator=(const Seguidors &o);

    //CONSULTORS
    bool buida() const;

    void mostrarSeguidors(int opcio) const;

    bool existeix(Carta e) const;

    bool tenimSeguidorMagia(char magia);


    //MODIFICADORS
    void inserir (Carta e);

    void eliminar (Carta e);

    bool donarSeguidors(Seguidors& s, char magia);

    //void esborra_videojocs_previs_a(Data d);



private:
    struct Node
    {
        Carta dada;
        Node *seg;
    };

    Node *a_inici;
    char a_tMagies[numMagies];

    void copia(const Seguidors &o);
    void allibera();

};

#endif // SEGUIDORS_H
