/*
*/
#include <iostream>
#include "../Z_lab1/mi_lib.h"

using namespace std;

int main() {

    INTMAU vectNumeros[] = {5,9,13,56,100};

    // Var puntero
    INTMAU *p_dir_vecNumeros;

    // Accedemos a la pos memoria del array
    p_dir_vecNumeros = vectNumeros;
    // equivale a:
    //p_dir_vecNumeros = &vectNumeros[0];
    // ya que queremos acceder a la primera posicion de memoria del array

    for (int i = 0; i < 5; i++) {
        /*
            p_dir_vecNumeros apunta al primer elemento del vector.

            *p_dir_vecNumeros obtiene el valor de la posición actual.

            p_dir_vecNumeros++ mueve el puntero a la siguiente posición del vector.

            Por eso usamos:
                *p_dir_vecNumeros++

            que equivale a:
                *(p_dir_vecNumeros++)

            Primero lee el valor actual y luego avanza el puntero.

            Usar *p_dir_vecNumeros[i] es un error
        */
        cout << "\nElemento en la pos. " << i 
            << " del vector: " << *p_dir_vecNumeros 
            << ". Direccion memoria: " << p_dir_vecNumeros;
        
        // Incrementamos la pocision el puntero a la siguiente posición del vector.
        p_dir_vecNumeros++;


        // o se puede
        /* cout << "\nElemento en la pos. " << i 
            << " del vector: " << *p_dir_vecNumeros++ << ". Direccion memoria: " << p_dir_vecNumeros;
        */
    }
    
    
    return 0;
}
