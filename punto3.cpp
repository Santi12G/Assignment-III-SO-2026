#include <iostream>
using namespace std;

int main() {
    int arreglo[5] = {10, 20, 30, 40, 50};

    int *puntero = arreglo;

    cout << "Contenido original del arreglo:" << endl;

    int i = 0;
    while (i < 5) {
        cout << "arreglo[" << i << "] = " << *(puntero + i);
        cout << " | Direccion de memoria: " << (puntero + i) << endl;
        i++;
    }

    cout << endl;

    i = 0;
    while (i < 5) {
        *(puntero + i) = *(puntero + i) + 100;
        i++;
    }

    cout << "Contenido modificado del arreglo usando punteros:" << endl;

    i = 0;
    while (i < 5) {
        cout << "arreglo[" << i << "] = " << *(puntero + i);
        cout << " | Direccion de memoria: " << (puntero + i) << endl;
        i++;
    }

    cout << endl;

    cout << "Direccion de memoria del arreglo: " << arreglo << endl;
    cout << "Direccion de memoria del primer elemento: " << &arreglo[0] << endl;
    cout << "Valor guardado en el puntero: " << puntero << endl;
    cout << "Direccion de memoria de la variable puntero: " << &puntero << endl;

    return 0;
}