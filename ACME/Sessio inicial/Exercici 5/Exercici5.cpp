#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

struct Llibre {
    string titol, ISBN, editorial, autor, estocPrimer, estocSegon;

};

const int MAX_L = 10000;
typedef Llibre Vec_llibre[MAX_L];

struct Vector_llibres_n {
    Vec_llibre vec;
    int n;
};


Llibre llegir_llibre(ifstream &f_in, bool primer) {
    Llibre llib;
    f_in>> llib.titol;

    if (primer) {
        if (not f_in.eof()) {
            f_in>>llib.ISBN>>llib.editorial>>llib.autor>>llib.estocPrimer;

        }

    }else {
        if (not f_in.eof()) {
            f_in>>llib.ISBN>>llib.editorial>>llib.autor>>llib.estocSegon;

        }
    }


    return llib;
}

void cerca_dicotomica (const Vector_llibres_n& llibres, string titol, bool& trobat, int& pos) {
    trobat = false;
    int esq = 0;
    int dret = llibres.n - 1;
    int mig;

    while (not trobat && esq <= dret) {
        mig = (esq + dret)/2;
        if (llibres.vec[mig].titol == titol) {
            trobat = true;
        
        }else if (llibres.vec[mig].titol < titol) {
            esq = mig + 1;

        }else {
            dret = mig - 1;

        }
    }

    if (trobat) {
        pos = mig;

    }else {
        pos = esq;
    }
}

void inserir_llibre(Vector_llibres_n& llibres, Llibre nouLlibre) {
    int i = llibres.n - 1;
    bool trobat;
    int pos;

    cerca_dicotomica(llibres, nouLlibre.titol, trobat, pos);

    if (trobat) {
        llibres.vec[pos].estocSegon = nouLlibre.estocSegon;

    }else {
        while (i >= 0 && llibres.vec[i].titol>nouLlibre.titol) {
            llibres.vec[i + 1] = llibres.vec[i];
            i--;

        }

        llibres.vec[i+1] = nouLlibre;
        if (llibres.vec[i+1].estocSegon == "") llibres.vec[i+1].estocSegon = "0";
        if (llibres.vec[i+1].estocPrimer == "") llibres.vec[i+1].estocPrimer = "0";  
        llibres.n++;

    }
}

void ordenar_isbn(Vector_llibres_n& llibres) {
    int i = 0;
    Llibre auxLlibre;
    auxLlibre = llibres.vec[0];
    int pos = 0;
    int posVector = 0;
    bool dentro = true;

    while (dentro) {
        if (i < llibres.n) {
            if (llibres.vec[pos].ISBN > llibres.vec[i].ISBN) {
                auxLlibre = llibres.vec[pos];
                llibres.vec[pos] = llibres.vec[i];
                llibres.vec[i] = auxLlibre;
                i = pos;
            }

            i++;

        }else {
            if (pos + 1 < llibres.n) {
                pos++;
                i = pos;

            }else {
                dentro = false;

            }

        }
    }

}

void omplir_fitxer (Vector_llibres_n& primeraLlibreria) {
    string llibreria1;
    string llibreria2;

    primeraLlibreria.n = 0;

    cout << "ENTRA EL NOM DE FITXER DE L'INVENTARI DE LA LLIBRERIA 1:" << endl;
    cin >> llibreria1;

    cout << "ENTRA EL NOM DE FITXER DE L'INVENTARI DE LA LLIBRERIA 2:" << endl;
    cin >> llibreria2;

    ifstream f_in(llibreria1.c_str());
    ifstream f_inSegon(llibreria2.c_str());

    Llibre nouLlibre;

    if (f_in.is_open()) {
        nouLlibre = llegir_llibre(f_in, true);

        while (not f_in.eof()) {
            inserir_llibre(primeraLlibreria, nouLlibre);
            nouLlibre = llegir_llibre(f_in, true);

        }
    }

    if (f_inSegon.is_open()) {
        nouLlibre = llegir_llibre(f_inSegon, false);
    
        while (not f_inSegon.eof()) {
            inserir_llibre(primeraLlibreria, nouLlibre);
            nouLlibre = llegir_llibre(f_inSegon, false);

        }
    }
};

void mostrar_llibre(const Llibre& llib) {
    cout  << llib.estocPrimer << " - " << llib.estocSegon << " " << llib.titol << ", " << llib.autor << " Ed. " << llib.editorial << " - " << llib.ISBN << endl;
}

void mostrar_inventari_alfabetic(const Vector_llibres_n& llibres) {
    cout << "INVENTARI PER ORDRE ALFABETIC" << endl;
    cout << "Estocs Titol, Autor Editorial - ISBN" << endl;
    for (int i = 0; i < llibres.n; i++) {
        mostrar_llibre(llibres.vec[i]);
    }

}

void mostrar_inventari_isbn(const Vector_llibres_n& llibres) {
    cout << "\nINVENTARI PER ORDRE D'ISBN" << endl;
    cout << "Estocs Titol, Autor Editorial - ISBN" << endl;
    for (int i = 0; i < llibres.n; i++) {
        mostrar_llibre(llibres.vec[i]);
    }

}

int main() {
    Vector_llibres_n primeraLlibreria;
    omplir_fitxer(primeraLlibreria);
    mostrar_inventari_alfabetic(primeraLlibreria);
    ordenar_isbn(primeraLlibreria);
    mostrar_inventari_isbn(primeraLlibreria);
    return 0;
}