
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;

int main()
{
    double numero;
    cout << "ENTRA LES NOTES (-1 PER ACABAR):" << endl;
    bool dins = true;
    float mitjana = 0;
    int comptador = 0;
    float extraodinaria;

    int nombreExtraodinarias = 0;
    float notaBaixa = -2;
    float notaAlta = 11;

    float extraodinariaAlta;
    float extraodinariaBaja;
    std::vector<float> vectorNumeros;

    while (dins)
    {

        cin >> numero;

        if (numero == -1)
        {
            dins = false;
        }
        else
        {
            mitjana = mitjana + numero;
            comptador++;
            vectorNumeros.push_back(numero);
            
        }
    }

    cout << "ENTRA LA DIFERENCIA PER A SER NOTA EXTRAORDINARIA:" << endl;
    cin >> extraodinaria;

    cout << "LA MITJANA ES: " << mitjana / comptador << endl;
    extraodinariaAlta = (mitjana / comptador) + extraodinaria;
    extraodinariaBaja = (mitjana / comptador) - extraodinaria;

    vectorNumeros.erase(vectorNumeros.end() - 1);

    for (int i = 0; i <= vectorNumeros.size(); i++)
    {   
          
        if (vectorNumeros[i] > extraodinariaAlta)
        {
            nombreExtraodinarias++;

            if (notaBaixa == -2 || notaBaixa > vectorNumeros[i]){
                notaBaixa = vectorNumeros[i];

            }
        }

        else if (vectorNumeros[i] < extraodinariaBaja)
        {
            nombreExtraodinarias++;

            if (notaAlta == 11 || notaAlta < vectorNumeros[i]){
                notaAlta = vectorNumeros[i];

            }
        }
    }
    cout << "NOMBRE D'EXTRAORDINARIES: " << nombreExtraodinarias << endl;

    if (notaAlta == 11) {
        cout << "NO HI HA NOTES EXTRAORDINARIAMENT BAIXES" << endl;
    }else {
        cout << "LA NOTA MES ALTA ENTRE LES EXTRAORDINARIAMENT BAIXES ES: " << notaAlta << endl;    

    }

    if (notaBaixa == -2) {
        cout << "NO HI HA NOTES EXTRAORDINARIAMENT ALTES" << endl;

    }else {
        cout << "LA NOTA MES BAIXA ENTRE LES EXTRAORDINARIAMENT ALTES ES: " << notaBaixa << endl;

    }

    return 0;
}