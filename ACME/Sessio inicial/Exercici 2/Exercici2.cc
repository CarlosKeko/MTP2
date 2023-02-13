
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;

int main()
{
    int numero;
    cout << "Entra la mida del triangle:" << endl;
    cin >> numero;
    std::vector<int> vectorNumeros;
    string frase;
    int resultado = 0;

    for (int i = 0; i < numero; i++)
    {
        vectorNumeros.push_back(i + 1);
        frase = "";
        resultado = 0;
        
        for (int j = 1; j <= vectorNumeros.size(); j++)
        {
            resultado = resultado + j;
            frase = frase + std::to_string(j) + " + ";

        }

        frase.resize(frase.length() - 3);
        std::cout << std::setw(2) << frase + " = " + std::to_string(resultado) << std::endl;

    }

    return 0;
}