#include <iostream>

int main(int argc, char const *argv[]) {

    int numeros[100];
    int longitudMinima;
    int mayor = 0;

    std::cout << "Digite longitud del arreglo: ";
    std::cin >> longitudMinima;

    for (int i = 0; i < longitudMinima; i++) {
        std::cout << "Inserte valor " << i+1 << std::endl;
        std::cin >> numeros[i];

        if(numeros[i] > mayor){
            mayor = numeros[i];
        }
    }

    std::cout << "\nEl numero mayor del arreglo es: " << mayor;
    
}