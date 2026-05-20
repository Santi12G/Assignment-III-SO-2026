#include <iostream>
using namespace std;

int main()
{
    int numero = 10;
    // Puntero a la variable
    int *puntero = &numero;
    // Referencia a la variable
    int &referencia = numero;
    cout << "Valor inicial de la variable: " << numero << endl;
    // Modificar usando el puntero
    *puntero = 20;
    cout << "Valor despues de modificar con puntero: " << numero << endl;
    // Modificar usando la referencia
    referencia = 30;
    cout << "Valor despues de modificar con referencia: " << numero << endl;
    // Direcciones de memoria
    cout << endl;
    cout << "Direccion de la variable: " << &numero << endl;
    cout << "Direccion almacenada en el puntero: " << puntero << endl;
    cout << "Direccion de la referencia: " << &referencia << endl;
    return 0;
}