#ifndef SEGUIDORS_H
#define SEGUIDORS_H
#include "Carta.h"


class Seguidors
{
public:
    static const int numMagies = 6;

    Seguidors();
    Seguidors(const Seguidors &o);
    ~Seguidors();
    Seguidors &operator=(const Seguidors &o);

    bool buida() const;

    void mostrarSeguidors(int opcio) const;

    bool existeix(Carta e) const;

    void inserir (Carta e);

    void eliminar (Carta e);

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
