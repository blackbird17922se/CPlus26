/*
    Recursividad en C++

    Recursividad significa que una función se llama a sí misma.

    Para que funcione bien necesita dos cosas:

    1. Caso base:
       Es la condición que detiene la recursividad.
       Sin esto, la función se llamaría infinitamente.

    2. Llamada recursiva:
       Es cuando la función se llama a sí misma,
       pero acercándose poco a poco al caso base.
*/

#include <iostream>

// Prototipo
void cuentaRegresiva(int numero);

int main() {
    int numero;

    std::cout << "Digite un numero para iniciar la cuenta regresiva: ";
    std::cin >> numero;

    cuentaRegresiva(numero);

    return 0;
}

void cuentaRegresiva(int numero) {
    // CASO BASE:
    // Si numero llega a 0, detenemos la recursividad.
    if (numero == 0) {
        std::cout << "Llegamos a 0. Fin.\n";
        return;
    }

    // Mostramos el número actual.
    std::cout << numero << "\n";

    // LLAMADA RECURSIVA:
    // La función se llama a sí misma,
    // pero con un número menor.
    cuentaRegresiva(numero - 1);
}