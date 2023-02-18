#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

struct Tutor
{
    string codi, nomCognom, assignatura, nombreProjectes, projectesDefensats;
};

struct PFGNoCompletats
{
    string codiAlumne, nomCognomAlumne, titolProjecte, especialitat, codiTutor, nota;
};

struct PFGCompletats
{
    string codiAlumne, nomCognomAlumne, titolProjecte, especialitat, codiTutor, nota;
};

const int MAX_L = 100;
typedef Tutor Vec_tutors[MAX_L];

struct Vector_tutors_n
{
    Vec_tutors vec;
    int n;
};

void menu()
{
    cout << "OPCIONS: " << endl;
    cout << "A: ALTA PFG" << endl;
    cout << "B: BAIXA PFG" << endl;
    cout << "P: PUNTUAR PFG" << endl;
    cout << "C: COMPLETAR PFG" << endl;
    cout << "L: MOSTRAR PFGs EN CURS D'UNA ESPECIALITAT" << endl;
    cout << "T: MOSTRAR TUTORS" << endl;
    cout << "H: MOSTRAR EL MENU" << endl;
    cout << "S: FI DEL PROGRAMA" << endl;
}

char llegir_opcio()
{
    char opcio;
    cout << "OPCIO: ";
    cin >> opcio;
    return opcio;
}

void inserir_tutor(Vector_tutors_n &tutors, Tutor nouTutor)
{
    int i = tutors.n - 1;

    while (i >= 0 && tutors.vec[i].codi > nouTutor.codi)
    {
        tutors.vec[i + 1] = tutors.vec[i];
        i--;
    }
    nouTutor.nombreProjectes = "0";
    nouTutor.projectesDefensats = "0";
    tutors.vec[i + 1] = nouTutor;
    tutors.n++;
}

Tutor llegir_tutor(ifstream &f_in, bool primer)
{
    Tutor tuto;
    f_in >> tuto.codi;

    if (not f_in.eof())
    {
        f_in >> tuto.nomCognom >> tuto.assignatura;
    }

    return tuto;
}

void omplir_fitxer(Vector_tutors_n &tutors)
{
    string nomTutors;

    tutors.n = 0;

    cout << "NOM DEL FITXER:" << endl;
    cin >> nomTutors;

    ifstream f_in(nomTutors.c_str());

    Tutor nouTutor;

    if (f_in.is_open())
    {
        nouTutor = llegir_tutor(f_in, true);

        while (not f_in.eof())
        {
            inserir_tutor(tutors, nouTutor);
            nouTutor = llegir_tutor(f_in, true);
        }
    }
};

void cout_tutors(Tutor tutor)
{
    cout << tutor.nomCognom << " (" << tutor.codi << ") "<< tutor.assignatura << " [" << tutor.nombreProjectes << ":" << tutor.projectesDefensats << "]" << endl;
}

void mostrar_tutors(const Vector_tutors_n& tutors) {
    for (int i = 0; i < tutors.n; i++) {
        cout_tutors(tutors.vec[i]);
    }

}

int main()
{
    Vector_tutors_n tutors;

    omplir_fitxer(tutors);
    menu();
    char opcio = llegir_opcio();

    while (opcio != 'S')
    {
        if (opcio == 'A')
            mostrar_tutors(tutors);
        else if (opcio == 'B')
            mostrar_tutors(tutors);
        else if (opcio == 'P')
            mostrar_tutors(tutors);
        else if (opcio == 'C')
            mostrar_tutors(tutors);
        else if (opcio == 'L')
            mostrar_tutors(tutors);
        else if (opcio == 'T')
            mostrar_tutors(tutors);
        else if (opcio == 'H')
            menu();

        opcio = llegir_opcio();
    }
    return 0;
}