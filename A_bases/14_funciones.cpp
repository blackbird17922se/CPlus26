#include <iostream>

// Si definimos una función DESPUÉS del lugar donde será llamada,
// debemos escribir primero su PROTOTIPO.
//
// El prototipo le avisa al compilador:
// "Esta función existe, recibe estos tipos de datos y devuelve este tipo de dato".
//
// Sin este prototipo, main() intentaría usar encontrarMax()
// antes de que el compilador sepa que esa función existe.

// PROTOTIPO:
// devuelve int, se llama encontrarMax y recibe dos int.
int encontrarMax(int x, int y);


int main() {
    int n1, n2;

    std::cout << "Digite 2 numeros: \n";
    std::cin >> n1 >> n2;

    std::cout << "Numero maximo: " << encontrarMax(n1, n2);

    return 0;
}

// DEFINICIÓN de la función.
// Aquí ya escribimos el código real de la función.
int encontrarMax(int x, int y) {
    int max;

    if (x > y) {
        max = x;
    } else {
        max = y;
    }

    return max;
}