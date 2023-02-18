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

struct Projectes
{
    string codiAlumne, nomCognomAlumne, titolProjecte, especialitat, codiTutor, nota;
};


const int MAX_T = 100;
typedef Tutor Vec_tutors[MAX_T];

struct Vector_tutors_n
{
    Vec_tutors vec;
    int n;
};

const int MAX_P = 1000;
typedef Projectes Vec_Projectes[MAX_P];

struct Vector_projectes_n
{
    Vec_Projectes vec;
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

void cerca_dicotomica_tutors (const Vector_tutors_n& tutors, string codi, bool& trobat, int& pos) {
    trobat = false;
    int esq = 0;
    int dret = tutors.n - 1;
    int mig;

    while (not trobat && esq <= dret) {
        mig = (esq + dret)/2;
        if (tutors.vec[mig].codi == codi) {
            trobat = true;
        
        }else if (tutors.vec[mig].codi < codi) {
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

void inserir_pfg(string nomTutor, Vector_projectes_n &projectes, string codiAlumne, string nomCognom, string titol, string especialitat, string codiTutor) {
    Projectes nouProjecte;
    nouProjecte.codiAlumne = codiAlumne;
    nouProjecte.nomCognomAlumne = nomCognom;
    nouProjecte.titolProjecte = titol;
    nouProjecte.especialitat = especialitat;
    nouProjecte.codiTutor = codiTutor;
    int i = projectes.n - 1;

    while (i >= 0 && projectes.vec[i].codiAlumne > nouProjecte.codiAlumne)
    {
        projectes.vec[i + 1] = projectes.vec[i];
        i--;
    }
    projectes.vec[i + 1] = nouProjecte;
    projectes.n++;
    
    cout << "Nou PFG: " << nouProjecte.titolProjecte << " (" << nouProjecte.especialitat << "), " << nouProjecte.nomCognomAlumne << " (" << nouProjecte.codiAlumne << "), tutor " << nomTutor << " (" << nouProjecte.codiTutor << ")" << endl; 

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

void cerca_dicotomica_projectes (const Vector_projectes_n& projectes, string codi, bool& trobat, int& pos) {
    trobat = false;
    int esq = 0;
    int dret = projectes.n - 1;
    int mig;

    while (not trobat && esq <= dret) {
        mig = (esq + dret)/2;
        if (projectes.vec[mig].codiAlumne == codi) {
            trobat = true;
        
        }else if (projectes.vec[mig].codiAlumne < codi) {
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

int buscar_tutor (const Vector_tutors_n& tutors, string especialitat) {
    int i = 0;
    int posicio = -1;

    while (i < tutors.n) {
        if (tutors.vec[i].assignatura == especialitat) {            
            if (posicio == -1) {
                posicio = i;

            }else {
                if (stoi(tutors.vec[posicio].nombreProjectes) > stoi(tutors.vec[i].nombreProjectes) || tutors.vec[i].codi < tutors.vec[posicio].codi && tutors.vec[posicio].nombreProjectes == tutors.vec[i].nombreProjectes) {
                    posicio = i;

                } 
            }
        }
        i++;
    }

    return posicio;
}

void alta_pfg (Vector_projectes_n &projectes, Vector_tutors_n &tutors) {
    string codiAlumne, nomCognom, titol, especialitat, codiTutor;
    char teTutor;
    bool trobat, trobatTutor;
    int pos, posTutor;

    cout << "Codi de l'alumne:" <<endl;
    cin >> codiAlumne;
    cerca_dicotomica_projectes(projectes, codiAlumne, trobat, pos);

    if (trobat) {
        cout << "Codi existent" <<endl;

    }else {
        cout << "Cognoms, nom:" <<endl;
        cin >> nomCognom;

        cout << "Titol:" <<endl;
        cin >> titol;

        cout << "Especialitat:" <<endl;
        cin >> especialitat;

        cout << "Te tutor (s/n):" <<endl;
        cin >> teTutor;

        if (teTutor == 's') {
            cout << "Codi tutor:" <<endl;
            cin >> codiTutor;

            cerca_dicotomica_tutors(tutors, codiTutor,  trobatTutor, posTutor);
            
            if (trobatTutor && stoi(tutors.vec[posTutor].nombreProjectes) < 10) {
                inserir_pfg(tutors.vec[posTutor].nomCognom, projectes, codiAlumne, nomCognom, titol, especialitat, codiTutor);

            }else if (trobatTutor && stoi(tutors.vec[posTutor].nombreProjectes) >= 10) {
                int posicioTutorNou = buscar_tutor(tutors, especialitat);
                inserir_pfg(tutors.vec[posTutor].nomCognom, projectes, codiAlumne, nomCognom, titol, especialitat, tutors.vec[posicioTutorNou].codi);

            }else {
                int posicioTutorNou = buscar_tutor(tutors, especialitat);
                inserir_pfg(tutors.vec[posicioTutorNou].nomCognom, projectes, codiAlumne, nomCognom, titol, especialitat, tutors.vec[posicioTutorNou].codi);
            }

        }else {
            int posicioTutorNou = buscar_tutor(tutors, especialitat);
            inserir_pfg(tutors.vec[posicioTutorNou].nomCognom, projectes, codiAlumne, nomCognom, titol, especialitat, tutors.vec[posicioTutorNou].codi);
        }
    }

}

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
    Vector_projectes_n projectes;

    omplir_fitxer(tutors);
    menu();
    char opcio = llegir_opcio();

    while (opcio != 'S')
    {
        if (opcio == 'A')
            alta_pfg(projectes, tutors);
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