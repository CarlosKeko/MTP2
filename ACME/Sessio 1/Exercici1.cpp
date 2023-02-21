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

struct ProjectesCompletats
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

const int MAX_PC = 1000;
typedef ProjectesCompletats Vec_Projectes_completats[MAX_PC];

struct Vector_projectes_completats_n
{
    Vec_Projectes_completats vec;
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
    cout << "-- OPCIO: ";
    cin >> opcio;
    cout <<  "" << endl;
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

void inserir_pfg(string nomTutor, Vector_projectes_n &projectes, string codiAlumne, string nomCognom, string titol, string especialitat, string codiTutor, bool fraseFinal) {
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
    
    if (fraseFinal) {
        cout << "Nou PFG: " << nouProjecte.titolProjecte << " (" << nouProjecte.especialitat << "), " << nouProjecte.nomCognomAlumne << " (" << nouProjecte.codiAlumne << "), tutor " << nomTutor << " (" << nouProjecte.codiTutor << ")" << endl; 

    }

}

void inserir_pfg_completat(string nomTutor, Vector_projectes_completats_n &projectes, string codiAlumne, string nomCognom, string titol, string especialitat, string codiTutor, string nota) {
    ProjectesCompletats nouProjecte;
    nouProjecte.codiAlumne = codiAlumne;
    nouProjecte.nomCognomAlumne = nomCognom;
    nouProjecte.titolProjecte = titol;
    nouProjecte.especialitat = especialitat;
    nouProjecte.codiTutor = codiTutor;
    nouProjecte.nota = nota;
    int i = projectes.n - 1;

    while (i >= 0 && projectes.vec[i].codiAlumne > nouProjecte.codiAlumne)
    {
        projectes.vec[i + 1] = projectes.vec[i];
        i--;
    }
    projectes.vec[i + 1] = nouProjecte;
    projectes.n++;
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

bool omplir_fitxer(Vector_tutors_n &tutors)
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
        return true;
    }else {
        cout << "FITXER NO TROBAT" << endl;
        return false;

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
                if (stoi(tutors.vec[posicio].nombreProjectes) > stoi(tutors.vec[i].nombreProjectes) || tutors.vec[i].codi < tutors.vec[posicio].codi && stoi(tutors.vec[posicio].nombreProjectes) >= stoi(tutors.vec[i].nombreProjectes)) {
                    posicio = i;

                } 
            }
        }
        i++;
    }

    cout << "S'ha assignat el tutor " << tutors.vec[posicio].nomCognom << " (" << tutors.vec[posicio].codi << "), " << tutors.vec[posicio].assignatura << " [" << tutors.vec[posicio].nombreProjectes << ":" << tutors.vec[posicio].projectesDefensats << "]" << endl;

    return posicio;
}

void sumar_projectes_tutor (Vector_tutors_n &tutors, int pos) {
    int suma = stoi(tutors.vec[pos].nombreProjectes) + 1;
    tutors.vec[pos].nombreProjectes = std::to_string(suma);
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
                inserir_pfg(tutors.vec[posTutor].nomCognom, projectes, codiAlumne, nomCognom, titol, especialitat, codiTutor, true);
                sumar_projectes_tutor(tutors, posTutor);                

            }else if (trobatTutor && stoi(tutors.vec[posTutor].nombreProjectes) >= 10) {
                int posicioTutorNou = buscar_tutor(tutors, especialitat);
                inserir_pfg(tutors.vec[posicioTutorNou].nomCognom, projectes, codiAlumne, nomCognom, titol, especialitat, tutors.vec[posicioTutorNou].codi, true);
                sumar_projectes_tutor(tutors, posicioTutorNou);

            }else {
                int posicioTutorNou = buscar_tutor(tutors, especialitat);
                inserir_pfg(tutors.vec[posicioTutorNou].nomCognom, projectes, codiAlumne, nomCognom, titol, especialitat, tutors.vec[posicioTutorNou].codi, true);
                sumar_projectes_tutor(tutors, posicioTutorNou);
            }



        }else {
            int posicioTutorNou = buscar_tutor(tutors, especialitat);
            inserir_pfg(tutors.vec[posicioTutorNou].nomCognom, projectes, codiAlumne, nomCognom, titol, especialitat, tutors.vec[posicioTutorNou].codi, true);
            sumar_projectes_tutor(tutors, posicioTutorNou);

        }
    }


}

void moure_vector_projectes (Vector_projectes_n &projectes, int pos) {
    Projectes nouP;
    if (pos == projectes.n - 1) {
        projectes.vec[pos] = nouP;
        projectes.n--;

    }else {
        while (pos < projectes.n) {
            if (pos + 1 < projectes.n) {
                projectes.vec[pos] = projectes.vec[pos + 1];

            }else {
                projectes.vec[pos] = nouP;

            }
            
            pos++;
        }

        projectes.n--;
    }

}

void restar_projectes_tutor (Vector_tutors_n &tutors, int pos) {
    int resta = stoi(tutors.vec[pos].nombreProjectes) - 1;
    tutors.vec[pos].nombreProjectes = std::to_string(resta);

}

void sumar_defenses_tutors (Vector_tutors_n &tutors, int pos) {
    int suma = stoi(tutors.vec[pos].projectesDefensats) + 1;
    tutors.vec[pos].projectesDefensats = std::to_string(suma);

}

void baixa_pfg (Vector_projectes_n &projectes, Vector_tutors_n &tutors) {
    string codiPFG;
    bool trobat, trobatTutor;
    int pos, posTutor;

    cout << "Codi de l'alumne:" <<endl;
    cin >> codiPFG;

    cerca_dicotomica_projectes(projectes, codiPFG, trobat, pos);

    if (!trobat) {
        cout << "Codi inexistent" <<endl;

    }else {
        cerca_dicotomica_tutors(tutors, projectes.vec[pos].codiTutor, trobatTutor, posTutor);
        moure_vector_projectes(projectes, pos);
        restar_projectes_tutor(tutors, posTutor);
        cout << "PFG eliminat" <<endl;

    }

}

void modificar_nota_projectes (Vector_projectes_n &projectes, int pos) {
    string nota;

    cout << "Nota obtinguda a la defensa:" <<endl;
    cin >> nota;

    projectes.vec[pos].nota = nota;
    
}

void puntuar_pfg (Vector_projectes_n &projectes, Vector_tutors_n &tutors) {
    string codiPFG;
    bool trobat, trobatTutor;
    int pos, posTutor;

    cout << "Codi de l'alumne:" <<endl;
    cin >> codiPFG;    

    cerca_dicotomica_projectes(projectes, codiPFG, trobat, pos);

    if (!trobat) {
        cout << "Codi inexistent" <<endl;

    }else {
        cerca_dicotomica_tutors(tutors, projectes.vec[pos].codiTutor, trobatTutor, posTutor);
        modificar_nota_projectes(projectes, pos);
        sumar_defenses_tutors(tutors, posTutor);
        restar_projectes_tutor(tutors, posTutor);

    }

}

void cout_projectes_defensats(ProjectesCompletats proje, Vector_tutors_n& tutors) {

    bool trobat;
    int pos;

    cerca_dicotomica_tutors(tutors, proje.codiTutor, trobat, pos);
    cout << proje.titolProjecte << " (" << proje.especialitat << "), " << proje.nomCognomAlumne << " (" << proje.codiAlumne << "), tutor " << tutors.vec[pos].nomCognom << " (" << proje.codiTutor << ") nota: " << proje.nota << endl;
}

void cout_projectes(Projectes proje, Vector_tutors_n tutors) {

    bool trobat;
    int pos;

    cerca_dicotomica_tutors(tutors, proje.codiTutor, trobat, pos);
    cout << proje.titolProjecte << " (" << proje.especialitat << "), " << proje.nomCognomAlumne << " (" << proje.codiAlumne << "), tutor " << tutors.vec[pos].nomCognom << " (" << proje.codiTutor << ")" << endl;

}

void cout_projectes_amb_tutor(Projectes proje, Vector_tutors_n& tutors) {

    bool trobat;
    int pos;

    cerca_dicotomica_tutors(tutors, proje.codiTutor, trobat, pos);
    cout << proje.titolProjecte << " (" << proje.especialitat << "), " << proje.nomCognomAlumne << " (" << proje.codiAlumne << "), tutor " << tutors.vec[pos].nomCognom << " (" << proje.codiTutor << ")" << endl;
}

void mostrar_projectes_defensats(const Vector_projectes_completats_n& projectes, Vector_tutors_n& tutors) {
    for (int i = 0; i < projectes.n; i++) {
        cout_projectes_defensats(projectes.vec[i], tutors);
    }
}

void mostrar_projectes(const Vector_projectes_n& projectes, const Vector_tutors_n& tutors) {
    for (int i = 0; i < projectes.n; i++) {
        cout_projectes(projectes.vec[i], tutors);
    }
}

void completar_projectes (Vector_projectes_n &projectes, Vector_projectes_completats_n &projectesCompletats, Vector_tutors_n &tutors) { 
    Vector_projectes_completats_n aux;
    int i = 0;

    while (i < projectes.n) {
        if (projectes.vec[i].nota != "") {
            inserir_pfg_completat(projectes.vec[i].nomCognomAlumne, projectesCompletats, projectes.vec[i].codiAlumne, projectes.vec[i].nomCognomAlumne, projectes.vec[i].titolProjecte, projectes.vec[i].especialitat, projectes.vec[i].codiTutor, projectes.vec[i].nota);
            moure_vector_projectes(projectes, i);

        }else {
            i++;

        }

    }
    cout << "S'han completat els projectes defensats" << endl;
    mostrar_projectes_defensats(projectesCompletats, tutors);

}

void ordenar_titol(Vector_projectes_n& projectes) {
    int i = 0;
    Projectes auxProjectes;
    auxProjectes = projectes.vec[0];
    int pos = 0;
    int posVector = 0;
    bool dentro = true;

    while (dentro) {
        if (i < projectes.n) {
            if (projectes.vec[pos].titolProjecte > projectes.vec[i].titolProjecte) {
                auxProjectes = projectes.vec[pos];
                projectes.vec[pos] = projectes.vec[i];
                projectes.vec[i] = auxProjectes;
                i = pos;
            }

            i++;

        }else {
            if (pos + 1 < projectes.n) {
                pos++;
                i = pos;

            }else {
                dentro = false;

            }

        }
    }

}

void ordenar_codiAlumne(Vector_projectes_n& projectes) {
    int i = 0;
    Projectes auxProjectes;
    auxProjectes = projectes.vec[0];
    int pos = 0;
    int posVector = 0;
    bool dentro = true;

    while (dentro) {
        if (i < projectes.n) {
            if (projectes.vec[pos].codiAlumne > projectes.vec[i].codiAlumne) {
                auxProjectes = projectes.vec[pos];
                projectes.vec[pos] = projectes.vec[i];
                projectes.vec[i] = auxProjectes;
                i = pos;
            }

            i++;

        }else {
            if (pos + 1 < projectes.n) {
                pos++;
                i = pos;

            }else {
                dentro = false;

            }

        }
    }

}

void llistar_pfg(Vector_projectes_n projectes, Vector_tutors_n tutors) {
    string especialitat;
    bool trobat;
    int pos;

    cout << "ESPECIALITAT:" << endl;
    cin >> especialitat;

    ordenar_titol(projectes);
    for (int i = 0; i < projectes.n; i++) {
        if (projectes.vec[i].especialitat == especialitat) {
             cout_projectes_amb_tutor(projectes.vec[i], tutors);
      
        }
    }
    ordenar_codiAlumne(projectes);

}

void cout_tutors(Tutor tutor)
{
    cout << tutor.nomCognom << " (" << tutor.codi << "), "<< tutor.assignatura << " [" << tutor.nombreProjectes << ":" << tutor.projectesDefensats << "]" << endl;
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
    Vector_projectes_completats_n projectesCompletats;

    bool entra = omplir_fitxer(tutors);

    if (entra) {
        menu();
        char opcio = llegir_opcio();

        while (opcio != 'S')
        {
            if (opcio == 'A')
                alta_pfg(projectes, tutors);
            else if (opcio == 'B')
                baixa_pfg(projectes, tutors);
            else if (opcio == 'P')
                puntuar_pfg(projectes, tutors);
            else if (opcio == 'C')
                completar_projectes(projectes, projectesCompletats, tutors);
            else if (opcio == 'L')
                llistar_pfg(projectes, tutors);
            else if (opcio == 'T')
                mostrar_tutors(tutors);
            else if (opcio == 'H')
                menu();

            cout << "" << endl;
            opcio = llegir_opcio();

        }
    }

    return 0;
}