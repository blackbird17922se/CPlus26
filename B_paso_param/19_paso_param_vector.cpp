/*
    Pasar un arreglo/vector a una función en C++

    Cuando pasamos un arreglo a una función, C++ NO copia todo el arreglo.

    En realidad, la función recibe la dirección de memoria del primer elemento
    del arreglo. Por eso, si modificamos el arreglo dentro de la función,
    también se modifica el arreglo original que está en main().

    Por eso se parece a pasar por referencia, aunque no escribamos &.
    podemos ver eso mirando la dir memoria del primer elemento del vector,
    siempre es la misma.

    También es necesario enviar el tamaño del arreglo, porque dentro de la
    función C++ no sabe automáticamente cuántos elementos tiene.
*/
#include <iostream>
#include "../Z_lab1/mi_lib.h"


// Prototipos de funciones.
// Las funciones reciben un arreglo de tipo dato INTMAU (int) y su tamaño.
void calcularCuadrado(INTMAU[], INTMAU);
void mostrarResultado(INTMAU[], INTMAU);

int main()
{
    const INTMAU TAM = 5;

    // Este arreglo NO es const porque lo vamos a modificar.
    INTMAU VECT[TAM] = {1, 2, 3, 4, 5};

    std::cout << "\n1. Dir memoria del elemento 1 de VECT antes de llamar calcularCuadrado(): " <<  &VECT[1] << "\n";

    // Enviamos el arreglo a la función.
    // Realmente se envía la dirección del primer elemento (o sea el 1).
    calcularCuadrado(VECT, TAM);

    // Mostramos el arreglo después de ser modificado.
    mostrarResultado(VECT, TAM);

    std::cout << "\n2. Dir memoria del elemento 1 de VECT despues de llamar calcularCuadrado(): " <<  &VECT[1] << "\n";
}


// Esta función recibe el arreglo original.
// No recibe una copia completa.
void calcularCuadrado(INTMAU vec[], INTMAU tam){

    std::cout << "\n2. Dir memoria del elemento 1 de VECT en calcularCuadrado() antes de calculo: " <<  &vec[1] << "\n";

    for (int i = 0; i < tam; i++) {

        // Modifica directamente el arreglo original.
        vec[i] *= vec[i];
    }
    
    std::cout << "\n3. Dir memoria del elemento 1 de VECT en calcularCuadrado() DESPUES de calculo: " <<  &vec[1] << "\n";
}


void mostrarResultado(INTMAU vec[], INTMAU tam){

    for (int i = 0; i < tam; i++) {
        std::cout << vec[i] << " ";
    }

}
