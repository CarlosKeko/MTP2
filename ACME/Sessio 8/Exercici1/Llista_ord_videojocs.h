#ifndef LLISTA_ORD_VIDEOJOCS_H
#define LLISTA_ORD_VIDEOJOCS_H
#include "Videojoc.h"
#include "Data.h"

class Llista_ord_videojocs
{
public:
    Llista_ord_videojocs();
    Llista_ord_videojocs(const Llista_ord_videojocs &o);
    ~Llista_ord_videojocs();
    Llista_ord_videojocs &operator=(const Llista_ord_videojocs &o);

    bool buida() const;

    void mostrar() const;

    bool existeix(Videojoc e) const;

    void inserir (Videojoc e);

    void eliminar (Videojoc e);

    void esborra_videojocs_previs_a(Data d);

private:
    struct Node
    {
        Videojoc dada;
        Node *seg;
    };

    Node *a_inici;
    void copia(const Llista_ord_videojocs &o);
    void allibera();

};

#endif // LLISTA_ORD_VIDEOJOCS_H
