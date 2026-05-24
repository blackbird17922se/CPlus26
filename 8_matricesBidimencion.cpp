#include <iostream>

/* MATRIZ BIDIMENSIONAL*/
int main() {

    int numFilas, numColumnas;

    // ESTRUCTURA:
    // tipoDato nombre [num filas] [num columnas]
    int numeros[100][100];


    // ASIGNAR VALORES A MATRIZ
    // FORMA 1
    /*
        Matriz de 2 filas y 3 columnas.

        En total tiene 6 espacios porque:
        2 * 3 = 6

        Los valores se llenan de izquierda a derecha,
        primero completando la fila 0 y luego la fila 1.

        Resultado:
        fila 0: 7, 65, 39
        fila 1: 42, 57, 8
    */
    int alfa[2][3] = {7, 65, 39, 42, 57, 8};


    // FORMA 2 MAS LEGIBLE
    int alfa2[2][3] = {
        {7, 65, 39},
        {42, 57, 8}
    };


    std::cout << "Inserte numero filas: ";
    std::cin >> numFilas;

    std::cout << "Inserte numero columnas: ";
    std::cin >> numColumnas;

    // Con matrices usamos bucles aliñados!!
    // Bucle FILAS
    for (int i = 0; i < numFilas; i++)
    {
        // Bucle COLUMNAS
        for (int j = 0; j < numColumnas; j++)
        {
            std::cout << "Numero para fila " << i << " columna " << j << ": ";
            std::cin >> numeros[i][j]; // Guarda en la fila x columna x
        }
    }

    // IMPRIMIR
    for (int i = 0; i < numFilas; i++)
    {
        std::cout << "\nFila " << i << "\n"; // Nos dice la fila q esta iterando
        for (int j = 0; j < numColumnas; j++)
        {
            std::cout << numeros[i][j] << " ";
        }
    }   
}