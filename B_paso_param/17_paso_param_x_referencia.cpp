/*
    17_paso_param_x_referencia.cpp

    Tema: paso de parámetros por referencia.

    Pasar por referencia significa que la función NO recibe una copia.
    La función recibe acceso directo a la variable original.

    Por eso, si dentro de la función modificamos el parámetro,
    también cambia la variable original que está en main().

    ALGO INTERESATE: veremos q en todo el programa la dir memoria de val es IGUAL
*/

#include <iostream>
#include <string>

// El símbolo & indica que val se recibe por referencia.
// Es decir: no llega una copia, llega la variable original.
void cambiarValores(std::string &val);

int main() {
    
    // Variable original creada dentro de main().
    std::string val = "ALFA";

    // Mostramos el valor original antes de llamar la función.
    std::cout << "\n1. Valor de val en main() ANTES de llamar cambiarValores(): " << val
        << " .Direccion Memoria actual val: " << &val;

    // Enviamos val a la función.
    // Como la función recibe por referencia, trabajará directamente
    // con la variable original.
    cambiarValores(val);

    // Ahora val sí cambió, porque la función modificó la variable original.
    std::cout << "\n4. Valor de val en main() DESPUES de llamar cambiarValores(): " << val
        << " .Direccion Memoria actual val: " << &val;

    return 0;
}

// Esta función recibe val por referencia.
// El & hace que val sea otro nombre para la misma variable de main().
void cambiarValores(std::string &val) {

    // Al entrar, val vale "ALFA".
    std::cout << "\n2. Valor de val dentro de cambiarValores() al inicio: " << val
        << " .Direccion Memoria actual val: " << &val;

    // Cambiamos directamente la variable original (la q esta en el main).
    val = "BETA";

    // Dentro de la función ahora vale "BETA".
    std::cout << "\n3. Nuevo valor de val dentro de cambiarValores(): " << val
        << " .Direccion Memoria actual val: " << &val;
}