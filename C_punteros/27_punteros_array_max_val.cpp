/*
    Hallar el máximo elemento de un arreglo usando punteros.

    Idea importante:

    Cuando pasamos un arreglo a una función, NO se copia todo el arreglo.
    Lo que se envía es la dirección del primer elemento.

    Por eso podemos escribir:

        hallarMax(vectorNumeros, numElements);

    sin usar &.

    vectorNumeros ya representa la dirección del primer elemento:

        vectorNumeros == &vectorNumeros[0]
*/

#include <iostream>
#include "../Z_lab1/mi_lib.h"

using namespace std;

// Prototipo.
// INTMAU* significa: la función recibe un puntero a INTMAU.
// En este caso, ese puntero apuntará al primer elemento del arreglo.
INTMAU hallarMax(INTMAU*, INTMAU);

int main() {
    const INTMAU numElements = 5;

    INTMAU vectorNumeros[numElements] = {3, 5, 85, 63, 21};

    /*
        No ponemos &vectorNumeros porque el nombre del arreglo
        ya funciona como dirección del primer elemento.

        vectorNumeros es parecido a escribir:
            &vectorNumeros[0]
    */
    cout << "El mayor elemento es: " << hallarMax(vectorNumeros, numElements);

    return 0;
}

// INTMAU *p_vector significa: la función recibe un puntero tipo INTMAU.
INTMAU hallarMax(INTMAU *p_vector, INTMAU numElementos) {
    INTMAU max = 0;

    for (INTMAU i = 0; i < numElementos; i++) {

        /*
            p_vector apunta al primer elemento del arreglo.

            p_vector + i significa:
            "muévete i posiciones desde el inicio del arreglo".

            Si i = 0:
                p_vector + 0 apunta a p_vector[0]

            Si i = 1:
                p_vector + 1 apunta a p_vector[1]

            Si i = 2:
                p_vector + 2 apunta a p_vector[2]

            *(p_vector + i) significa:
            "dame el valor que está en esa posición".

            Entonces:
                *(p_vector + i)

            es equivalente a:
                p_vector[i]
            
            No olvide que * es para acceder al contenido del vector, no a su dir memoria
        */
        if (*(p_vector + i) > max) {
            max = *(p_vector + i);
        }

        // también se podría escribir  así:
        // if (p_vector[i] > max) {
        //     max = p_vector[i];
        // }
    }

    return max;
}