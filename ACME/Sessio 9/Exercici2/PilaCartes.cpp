#include "PilaCartes.h"

PilaCartes::PilaCartes()
{
    a_cim= NULL;
}

PilaCartes::PilaCartes(const PilaCartes& o)
{
    a_cim= NULL;
    copia(o); // crida a mètode privat
}

PilaCartes::~PilaCartes()
{
    allibera(); // crida a mètode privat
}

PilaCartes &PilaCartes::operator=(const PilaCartes &t)
{
//Pre: --; Post: aquesta taula �s c�pia de la taula t
    if (this != &t){
        allibera();
        copia(t);
    }
    return *this;
}


void PilaCartes::empila(Carta s){
    Node* nou= new Node; // necessari reservar memoria
    nou->valor= s;
    nou->seg= a_cim;
    a_cim= nou;
}

void PilaCartes::desempila(){
    Node* aux= a_cim;
    a_cim= a_cim->seg;
    delete aux;
}

bool PilaCartes::buida() const
{
    return a_cim==NULL;
}

Carta PilaCartes::cim() const
{
    return a_cim->valor;
}

void PilaCartes::mostrar() const {
    Node *aux = a_cim;
    while (aux !=  NULL) {
        aux->valor.mostrar();
        aux = aux->seg;
    }
    cout << endl;

}

void PilaCartes::allibera()
{
    while (not buida()) {
        Node* aux= a_cim;
        a_cim= a_cim->seg;
        delete aux;
    }
}

void PilaCartes::copia(const PilaCartes &o)
{
    if(not o.buida()){
        Node *p, *q, *aux;
        p = new Node; a_cim = p;
        aux = o.a_cim; p->valor = aux->valor; p->seg = NULL;
        q = p;
        while (aux->seg != NULL) {
            aux = aux->seg;
            p = new Node; q->seg = p;
            p->valor = aux->valor; p->seg = NULL;
            q = p;
        }
    }
}
