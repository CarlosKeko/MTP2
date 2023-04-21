#include "Llista_ord_videojocs.h"

Llista_ord_videojocs::Llista_ord_videojocs()
{
    a_inici = NULL;
}


Llista_ord_videojocs::Llista_ord_videojocs(const Llista_ord_videojocs &o)
{
// Pre:--; Post: la llista es còpia de o
    a_inici = NULL;
    copia(o);
}

void Llista_ord_videojocs::esborra_videojocs_previs_a(Data d)
{
    Llista_ord_videojocs aux;
    aux.copia(*this);
    Node *p = aux.a_inici;

    //p = aux.a_inici;

    while (p != NULL) {
        if (p->dada.data_mayor(d)) {
            eliminar(p->dada);

        }

        p = p->seg;
    }
}

bool Llista_ord_videojocs::existeix(Videojoc e) const
{
// Pre:--; Post: ens diu si e existeix a la llista
    Node *p = a_inici;
    bool fiCerca = false;
    bool trobat = false;
    while ((p!=NULL) && (!fiCerca))
    {
        if (p->dada >= e)
        {
            fiCerca = true;
            trobat = p->dada == e;
        }
        else
            p = p->seg;
    }
    return trobat;
}

bool Llista_ord_videojocs::buida() const
{
// Pre:--; Post: ens diu si la llista es buida
    return a_inici == NULL;
}

void Llista_ord_videojocs::mostrar() const
{
// Pre:--; Post: mostra la llista
    cout << "[ VIDEOJOCS VENUTS ]" << endl;
    Node *p = a_inici;
    while (p!= NULL)
    {
        p->dada.mostrar();
        p = p->seg;
    }
    cout << endl;
}
void Llista_ord_videojocs::inserir(Videojoc e)
{
// Pre: --; Post: si e no existeix s'ha inserit en el lloc que li toca per mantenir l'ordre; en cas contrari no es fa cap inserció
    Node *ant, *p, *nou;
    bool fiCerca = false;
    bool trobat = false;
    ant = NULL;
    p = a_inici;
    while((p!=NULL) && (!fiCerca))
    {
        if (p->dada >= e)
        {
            fiCerca = true;
            trobat = p->dada==e;
            if (trobat)
            {
                p->dada.sumarPunts(e);
                p->dada.novaData(e);

            }
        }
        else
        {
            ant = p;
            p = p->seg;
        }
    }
    if (!trobat)
    {
        nou = new Node;
        nou->dada = e;
        nou->seg = p;
        if (ant == NULL)
            a_inici = nou;
        else
            ant->seg = nou;
    }
}

void Llista_ord_videojocs::eliminar(Videojoc e)
{
// Pre:--; Post: e s'ha esborrat en el cas que existís; en cas contrari no es fa res
    Node *ant, *p;
    bool fiCerca = false;
    bool trobat = false;
    ant = NULL;
    p = a_inici;
    while((p!=NULL) && (!fiCerca))
    {
        if (p->dada >= e)
        {
            fiCerca = true;
            trobat = p->dada == e;
        }
        else
        {
            ant = p;
            p = p->seg;
        }
    }
    if (trobat)
    {
        if(ant!= NULL)
            ant->seg = p->seg;
        else a_inici = p->seg;
        delete p;
    }
}



void Llista_ord_videojocs::copia(const Llista_ord_videojocs &o)
{
// Pre: memòria dinàmica alliberada; Post: aquesta llista es còpia de o
    if(!o.buida())
    {
        Node *ant, *p, *q;
        p = o.a_inici;
        q = new Node;
        a_inici = ant = q;
        q->dada = p->dada;
        q->seg = NULL;
        p = p->seg;
        while (p != NULL)
        {
            q = new Node;
            q->dada = p->dada;
            q->seg = NULL;
            ant->seg = q;
            ant = q;
            p = p->seg;
        }
    }
}

Llista_ord_videojocs::~Llista_ord_videojocs()
{
// Pre: --; Post: memòria dinàmica alliberada
    allibera();
}

void Llista_ord_videojocs::allibera()
{
// Pre: --; Post: memòria dinàmica alliberada
    while (!buida())
    {
        Node* aux = a_inici;
        a_inici = a_inici->seg;
        delete aux;
    }
}

Llista_ord_videojocs& Llista_ord_videojocs::operator=(const Llista_ord_videojocs &o)
{
// Pre:--; Post: aquesta llista es copia de o i abans s'ha alliberat la memòria ocupada per aquesta llista
    if (this != &o)
    {
        allibera();
        copia(o);
    }
    return *this;
}


