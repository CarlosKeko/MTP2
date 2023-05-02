#include "Cuacompravenda.h"
#include "Compravenda.h"

//CONSTRUCTORS Y ALLIBERADORS
Cuacompravenda::Cuacompravenda()
{
    a_primer=a_darrer= NULL;
}

Cuacompravenda::Cuacompravenda(const Cuacompravenda& o)
{
    a_primer=a_darrer= NULL;
    copia(o);
}

Cuacompravenda::~Cuacompravenda()
{
    allibera();
}


//CONSULTORS
bool Cuacompravenda::buida() const
{
    return a_primer == NULL;

}

Compravenda Cuacompravenda::primer() const
{
    return a_primer->valor;
}

//MODIFICADORS
void Cuacompravenda::encua(Compravenda s)
{
    Node* nou = new Node;
    nou->valor = s;
    nou->seg = NULL;

    if (buida())
    {
        a_primer = nou;
        a_darrer = nou;

    }
    else
    {
        a_darrer->seg = nou;
        a_darrer = nou;

    }

}

void Cuacompravenda::desencua()
{
    Node* aux = a_primer;
    if (a_primer==a_darrer)
    {
        a_primer = NULL;
        a_darrer = NULL;

    }
    else
    {
        a_primer = a_primer->seg;
    }
    delete aux;
}

//METODES PRIVATS

void Cuacompravenda::copia(const Cuacompravenda& o)
{
// Pre: cua buida; Post: aquesta cua és còpia de o
// COST: O(n)
    Node* p = o.a_primer;
    while(p!=NULL)  // recorrem cua o
    {
        encua(p->valor); // this->encua(p->valor)
        p=p->seg;
    }
}

void Cuacompravenda::allibera()
{
// Pre: --; Post: cua buida
// COST: O(n)
    while (a_primer!=NULL)   //!buida()
    {
        Node* aux= a_primer;
        a_primer= a_primer->seg;
        delete aux;
    }
    a_darrer= NULL;
}

// OPERADOR ASSIGNACIÓ
Cuacompravenda& Cuacompravenda::operator=(const Cuacompravenda& o)
{
// Pre: -- ; Post: aquesta cua és còpia de o
// COST: O(n)
    if (this != &o)
    {
        allibera();
        copia(o);
    }
    return *this;
}
