#include <iostream>
#include <string> // Para facilitar usar string como parametro

/*
    PLANTILLAS / TEMPLATES EN C++

    Una plantilla permite crear funciones o clases que trabajan
    con distintos tipos de datos sin tener que repetir código.

    Ejemplo:
    En vez de hacer una función para sumar int,
    otra para sumar float,
    otra para sumar double,
    usamos una plantilla.

    El tipo de dato se vuelve "variable".

    template <class T>
    significa:

    "T será un tipo de dato que se decidirá cuando se llame la función".
*/

// Alias personalizados
using VOIDMAU = void;
using INTMAU = int;
using STRINGMAU = std::string; // Para facilitar usar string como parametro, no es necesario poner longitud

// ************************* TEMPLATE *************************
//Ten presente eso, aqui no fue necesario prototipo funcion porque defin. la funcion antes de llamarla.
// T es un tipo de dato genérico
template <class T>
VOIDMAU sumarNumeros(
    INTMAU num1,          // Primer número, siempre será int
    T num2,               // Segundo número, puede ser int, float, double, etc.
    STRINGMAU mensaje     // Texto tipo cadena estilo C
) {
    // auto deja que C++ deduzca el tipo del resultado.
    // Ejemplo: int + double da double.
    auto resultado = num1 + num2;

    std::cout << mensaje << ": " << resultado << "\n";
}


int main() {
    sumarNumeros(2, 3.5, "Suma con double");
    sumarNumeros(10, 5, "Suma con int");
    sumarNumeros(4, 2.8f, "Suma con float");

    return 0;
}