#include <iostream>

int main(int argc, char const *argv[]) {

    int numeros[] = {1,2,3,4,5};
    int suma = 0;
    int numeros2[100]; // cuando no se le asigna valores al array, se debe establecer una longitud maxima

    for (int i = 0; i < 5; i++)
    {
        suma += numeros[i];
    }

    std::cout << "Resultado: " << suma;
    
}