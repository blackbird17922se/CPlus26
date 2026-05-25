/* 
    16_paso_param_x_valor.cpp

    Tema: paso de parámetros por valor.

    Pasar por valor significa que la función recibe una COPIA
    del dato original.

    Entonces, si dentro de la función cambiamos esa copia,
    el valor original en main() NO cambia.

    ALGO INTERESATE: veremos q en el main la dir memora es uno, y en cambiarValores() es otro
*/

#include <iostream>
#include <string>

// Prototipo de la función.
// Recibe un std::string por valor, es decir, recibe una copia.
void cambiarValores(std::string val);

int main() {
    
    // Variable original creada dentro de main().
    std::string val = "ALFA";

    // Aquí vemos el valor original antes de llamar la función.
    std::cout << "\n1. Valor de val en main() ANTES de llamar cambiarValores(): " << val 
        << " .Direccion Memoria actual val: " << &val;

    // Llamamos la función y le enviamos val.
    // OJO: se envía una COPIA de val, no la variable original.
    cambiarValores(val);

    // Después de ejecutar la función, val sigue siendo "ALFA",
    // porque dentro de cambiarValores() solo se modificó la copia.
    std::cout << "\n4. Valor de val en main() DESPUES de llamar cambiarValores(): " << val        
        << " .Direccion Memoria actual val: " << &val;

    return 0;
}

// Definición de la función.
// Esta variable val NO es la misma val de main().
// Es una copia independiente.
void cambiarValores(std::string val) {

    // Al entrar, la copia también tiene el valor "ALFA".
    std::cout << "\n2. Valor de val dentro de cambiarValores() al inicio: " << val
        << " .Direccion Memoria actual val: " << &val;
    // Cambiamos el valor de la copia.
    // Esto NO afecta la variable val que está en main().
    val = "BETA";

    // Ahora, dentro de la función, la copia vale "BETA".
    std::cout << "\n3. Nuevo valor de val dentro de cambiarValores(): " << val
        << " .Direccion Memoria actual val: " << &val;
}