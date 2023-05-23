#include "Seguidors.h"
#include "Carta.h"
#include <iomanip>

#include <iostream>

using namespace std;

Seguidors::Seguidors()
{
    a_inici = NULL;
    a_tMagies[0] = 'b';
    a_tMagies[1] = 'o';
    a_tMagies[2] = 'p';
    a_tMagies[3] = 'r';
    a_tMagies[4] = 't';
    a_tMagies[5] = 'v';
}


Seguidors::Seguidors(const Seguidors &o)
{
// Pre:--; Post: la llista es c�pia de o
    a_inici = NULL;
    copia(o);
}

bool Seguidors::buida() const
{
// Pre:--; Post: ens diu si la llista es buida
    return a_inici == NULL;
}

void Seguidors::mostrarSeguidors(int opcio) const
{
// Pre:--; Post: mostra la llista

    Node *p = a_inici;


    //if (p == NULL) {
    //  cout << "\nNO HI HA CAP CARTA" << endl;

    //}else {
    if (opcio == 1)
    {
        while (p != NULL)
        {
            p->dada.mostrar(1);
            p = p->seg;
        }

    }
    else
    {

        for (int i = 0; i < numMagies; i++)
        {
            int influencia = 0;
            p = a_inici;

            while (p != NULL)
            {
                if (p->dada.coincideixMagia(a_tMagies[i]))
                {
                    influencia = influencia + p->dada.getInfluencia();

                }
                p = p->seg;
            }
            cout << "[" << setfill(' ') << setw(2);
            if (influencia > 0)
            {
                cout << influencia;

            }
            else
            {
                cout << ' ';

            }

            cout << a_tMagies[i] << "] ";

        }
    }

    //}

    /*cout << "[ VIDEOJOCS VENUTS ]" << endl;
    Node *p = a_inici;
    while (p!= NULL)
    {
        p->dada.mostrar();
        p = p->seg;
    }
    cout << endl;*/
}

void Seguidors::eliminar(Carta e)
{
// Pre:--; Post: e s'ha esborrat en el cas que existís; en cas contrari no es fa res
    //cout << "\nENTRA A ELIMINAR" << endl;
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
        //cout << "\nELIMINA EL VALOR" << endl;
        if(ant!= NULL)
            ant->seg = p->seg;
        else a_inici = p->seg;
        delete p;
    }

}

void Seguidors::inserir(Carta e)
{
// Pre: --; Post: si e no existeix s'ha inserit en el lloc que li toca per mantenir l'ordre; en cas contrari no es fa cap inserci�
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

void Seguidors::copia(const Seguidors &o)
{
// Pre: mem�ria din�mica alliberada; Post: aquesta llista es c�pia de o
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

Seguidors::~Seguidors()
{
// Pre: --; Post: mem�ria din�mica alliberada
    allibera();
}

void Seguidors::allibera()
{
// Pre: --; Post: mem�ria din�mica alliberada
    while (!buida())
    {
        Node* aux = a_inici;
        a_inici = a_inici->seg;
        delete aux;
    }
}

Seguidors& Seguidors::operator=(const Seguidors &o)
{
// Pre:--; Post: aquesta llista es copia de o i abans s'ha alliberat la mem�ria ocupada per aquesta llista
    if (this != &o)
    {
        allibera();
        copia(o);
    }
    return *this;
}

bool Seguidors::donarSeguidors(Seguidors& s, char magia)
{
    Node *p = a_inici;

    //cout << "\nENTRA A LA FUNCIO DE SEGUIDORS" << endl;
    if (tenimSeguidorMagia(magia) && !s.tenimSeguidorMagia(magia))
    {
        //cout << "\nENTRA AL IF DE SEGUIDORS" << endl;
        while (p != NULL)
        {
            if (p->dada.coincideixMagia(magia)) {
                //cout << "\n ESTEM DONANT SEGUIDORS" << endl;
                s.inserir(p->dada);
                eliminar(p->dada);

            }

            p = p ->seg;
        }

        return true;

    }else {
        return false;
    }

}

bool Seguidors::tenimSeguidorMagia(char magia)
{
    Node *p = a_inici;
    bool trobat = false;

    while (p != NULL && !trobat)
    {

        if (p->dada.coincideixMagia(magia))
        {
            //cout << "\n TROBA LA MAGIA" << endl;
            trobat = true;

        }

        p = p->seg;

    }

    return trobat;
}

