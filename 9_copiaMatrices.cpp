#include <iostream>
#include <cstdlib> // Necesario para usar: rand(), srand()
#include <time.h> // Necesario para usar: time(0)

/* Copia datos de una matriz a otra, asignando valores random*/
int main() {

    int matriz[100][100];

    int numFilas, numColumnas;

    // inicializar semilla random, “Usa la hora actual como semilla”, Entonces los números cambian en cada ejecución.
    srand(time(0));

    std::cout << "Inserte numero filas: ";
    std::cin >> numFilas;

    std::cout << "Inserte numero columnas: ";
    std::cin >> numColumnas;

    for (int i = 0; i < numFilas; i++)
    {
        for (int j = 0; j < numColumnas; j++)
        {
            matriz[i][j] = rand() % 10; // número aleatorio entre 0 y 99
        }
        
    }
    
    // IMPRIMIR MATRIZ
    for (int i = 0; i < numFilas; i++) {
        std::cout << "\nFila " << i << ": ";

        for (int j = 0; j < numColumnas; j++) {
            std::cout << matriz[i][j] << " ";
        }
    }

}