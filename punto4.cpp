#include <iostream>
using namespace std;

int main() {
    int filas;
    int columnas;

    cout << "Ingrese la cantidad de filas: ";
    cin >> filas;

    cout << "Ingrese la cantidad de columnas: ";
    cin >> columnas;

    int **matriz = new int*[filas];

    int i = 0;
    while (i < filas) {
        matriz[i] = new int[columnas];
        i++;
    }

    cout << endl;
    cout << "Ingrese los datos de la matriz:" << endl;

    i = 0;
    while (i < filas) {
        int j = 0;

        while (j < columnas) {
            cout << "matriz[" << i << "][" << j << "]: ";
            cin >> matriz[i][j];
            j++;
        }

        i++;
    }

    cout << endl;
    cout << "Matriz ingresada:" << endl;

    i = 0;
    while (i < filas) {
        int j = 0;

        while (j < columnas) {
            cout << matriz[i][j] << " ";
            j++;
        }

        cout << endl;
        i++;
    }

    cout << endl;
    cout << "Direcciones de memoria de los elementos:" << endl;

    i = 0;
    while (i < filas) {
        int j = 0;

        while (j < columnas) {
            cout << "Direccion de matriz[" << i << "][" << j << "]: ";
            cout << &matriz[i][j] << endl;
            j++;
        }

        i++;
    }

    cout << endl;

    i = 0;
    while (i < filas) {
        delete[] matriz[i];
        i++;
    }

    delete[] matriz;

    matriz = nullptr;

    cout << "Memoria liberada correctamente." << endl;

    return 0;
}