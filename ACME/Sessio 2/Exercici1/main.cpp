#include <iostream>
#include "Data.h"
using namespace std;
int main()
{
    Data data1, data2;
    cout << "ENTRA LA DATA ACTUAL:" << endl;
    data1.llegir(1);
    cout << "ENTRA LA DATA DE NAIXEMENT:" << endl;
    data2.llegir(1);

    if (data2.es_cumple(data1))
    {
        cout << "AVUI ES L'ANIVERSARI! FA " << data2.comptar_anys(data1) << " ANYS" << endl;

    }else {
        cout << "TE " << data2.comptar_anys(data1) << " ANYS"<< endl;

    }

    //cout<<" ES ABANS QUE ";
    //data1.mostrar(2);

    return 0;
}
