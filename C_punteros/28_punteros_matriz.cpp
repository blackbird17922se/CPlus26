/*
    MATRIZ DINÁMICA CON PUNTERO DOBLE

    Una matriz dinámica permite crear una matriz cuyo tamaño
    se conoce mientras el programa se ejecuta.

    Ejemplo:
    El usuario decide cuántas filas y columnas quiere.

    Para esto usamos:

        INTMAU **p_matriz;

    Se lee así:

        p_matriz es un puntero a puntero de INTMAU.

    ¿Por qué doble puntero?

    Porque primero reservamos un arreglo de filas.
    Cada fila será un puntero.

    Luego, para cada fila, reservamos un arreglo de columnas.

    Visualmente:

        p_matriz
           ↓
        [ fila0 ] → [ col0 ][ col1 ][ col2 ]
        [ fila1 ] → [ col0 ][ col1 ][ col2 ]
        [ fila2 ] → [ col0 ][ col1 ][ col2 ]
*/

#include <iostream>
#include "../Z_lab1/mi_lib.h"

using namespace std;

// PROTOTIPOS
void pedirDatos(INTMAU &numFilas, INTMAU &numColumnas);
void mostrarMatriz(INTMAU **matriz, INTMAU nFilas, INTMAU nCol);
void liberarMemoria(INTMAU **matriz, INTMAU nFilas);

// Puntero doble global.
// Guardará la matriz dinámica.
INTMAU **p_matriz;

int main() {
    INTMAU numFilas, numColumnas;

    pedirDatos(numFilas, numColumnas);
    mostrarMatriz(p_matriz, numFilas, numColumnas);

    liberarMemoria(p_matriz, numFilas);

    return 0;
}

void pedirDatos(INTMAU &numFilas, INTMAU &numColumnas) {
    cout << "Digite numero de filas: ";
    cin >> numFilas;

    cout << "Digite numero de columnas: ";
    cin >> numColumnas;

    /*
        Reservamos memoria para las filas.

        p_matriz = new INTMAU*[numFilas];

        ¿Por qué INTMAU*?

        Porque cada fila será un puntero a un arreglo de columnas.

        Si numFilas = 3, se crea algo como:

            p_matriz
               ↓
            [ puntero fila 0 ]
            [ puntero fila 1 ]
            [ puntero fila 2 ]
    */
    p_matriz = new INTMAU*[numFilas];

    /*
        Ahora reservamos memoria para las columnas de cada fila.

        p_matriz[i] representa una fila.

        Cada fila será un arreglo de INTMAU.
    */
    for (INTMAU i = 0; i < numFilas; i++) {
        p_matriz[i] = new INTMAU[numColumnas];
    }

    cout << "\nDigite elementos de la matriz:\n";

    for (INTMAU i = 0; i < numFilas; i++) {
        for (INTMAU j = 0; j < numColumnas; j++) {
            cout << "Digite un numero[" << i << "][" << j << "]: ";

            /*
                Esta forma:

                    *(*(p_matriz + i) + j)

                es equivalente a:

                    p_matriz[i][j]

                Explicación:

                    p_matriz + i
                    → se mueve a la fila i

                    *(p_matriz + i)
                    → entra a la fila i

                    (*(p_matriz + i) + j)
                    → se mueve a la columna j

                    *(*(p_matriz + i) + j)
                    → obtiene/modifica el valor de esa posición
            */
           // puede escribirse:
            cin >> p_matriz[i][j];

            // o asi:
            // cin >> *(*(p_matriz + i) + j);
            /*
                Esta notación:
                    *(*(p_matriz + i) + j)

                es equivalente a:
                    p_matriz[i][j]

                No es necesariamente vieja, sino una forma más explícita
                de trabajar con punteros y aritmética de direcciones.

                En código real normalmente se prefiere p_matriz[i][j]
                porque es más legible.
            */
        }
    }
}

void mostrarMatriz(INTMAU **matriz, INTMAU nFilas, INTMAU nCol) {
    cout << "\nMatriz ingresada:\n";

    for (INTMAU i = 0; i < nFilas; i++) {
        for (INTMAU j = 0; j < nCol; j++) {
            cout << matriz[i][j] << " ";
            // o asi:
            // cout << *(*(p_matriz + i) + j);
        }

        cout << "\n";
    }
}

void liberarMemoria(INTMAU **matriz, INTMAU nFilas) {
    /*
        Como usamos new[], debemos liberar con delete[].

        Primero liberamos cada fila.
    */
    for (INTMAU i = 0; i < nFilas; i++) {
        delete[] matriz[i];
    }

    // Luego liberamos el arreglo principal de filas.
    delete[] matriz;
}