#include <iostream>

int main() {

    char letras1[] = {'a','b','c','d','e'};
    char letras2[] = {'f','g','h','i','j'};

    // Necesitas 11 espacios para guardar \0:
    char vectorTotal[11];


    for (int i = 0; i < 5; i++) {
        vectorTotal[i] = letras1[i];
    }

    for (int i = 5; i < 10; i++) {
        // -5 porque si lo dejo en i, i arranca en 5, y en letras2 el valor inicial (f) en pos 0
        vectorTotal[i] = letras2[i - 5];
    }

    /* si no quiero hacer for para traer los valores, debo usar vectorTotal[10] = '\0'; ya q  de lo contrario 
    traera abcdefghijfghijabcde debido a que En C++, cuando imprimes un char[] con std::cout, 
    lo trata como una cadena estilo C y sigue leyendo memoria hasta encontrar un '\0'*/

    vectorTotal[10] = '\0';
    std::cout << "\nEl arreglo concatenado es: " << vectorTotal;
    
}