#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

struct Llibre {
    string titol, ISBN, editorial, autor, estoc;

};

// struct Llibreria {
//     string estoc, quantitat;

// };

const int MAX_L = 10000;
typedef Llibre Vec_llibre[MAX_L];

struct Vector_llibres_n {
    Vec_llibre vec;
    int n;
};

Llibre llegir_llibre(ifstream &f_in) {
    Llibre llib;
    f_in>> llib.titol;
    if (not f_in.eof()) {
        f_in>>llib.ISBN>>llib.editorial>>llib.autor>>llib.estoc;

    }

    return llib;
}

void inserir_llibre(Vector_llibres_n& llibres, Llibre nouLlibre) {
    int i = llibres.n - 1;
    while (i >= 0 && llibres.vec[i].titol>nouLlibre.titol) {
        llibres.vec[i + 1] = llibres.vec[i];
        i--;

    }
    llibres.vec[i+1] = nouLlibre; llibres.n++;

}

void omplir_fitxer (Vector_llibres_n& llibres) {
    string llibreria1, llibreria2;
    llibres.n = 0;

    cout << "ENTRA EL NOM DE FITXER DE L'INVENTARI DE LA LLIBRERIA 1:" << endl;
    cin >> llibreria1;

    // cout << "ENTRA EL NOM DE FITXER DE L'INVENTARI DE LA LLIBRERIA 2:" << endl;
    // cin >> llibreria2;

    ifstream f_in(llibreria1.c_str());

    if (f_in.is_open()) {
        Llibre nouLlibre = llegir_llibre(f_in);
        while (not f_in.eof()) {
            inserir_llibre(llibres, nouLlibre);
            nouLlibre = llegir_llibre(f_in);

        }
    }
};

void mostrar_llibre(const Llibre& llib) {
    cout  << llib.estoc << " " << llib.titol << ", " << llib.autor << " Ed. " << llib.editorial << " - " << llib.ISBN << endl;
}

void mostrar_inventari_alfabetic(const Vector_llibres_n& llibres) {
    cout << "INVENTARI PER ORDE ALFABETIC" << endl;
    cout << "Estocs Titol, Autor Editorial - ISBN" << endl;
    for (int i = 0; i < llibres.n; i++) {
        mostrar_llibre(llibres.vec[i]);
    }

}

int main() {
    Vector_llibres_n llibresMeus;
    omplir_fitxer(llibresMeus);
    mostrar_inventari_alfabetic(llibresMeus);

    return 0;
}