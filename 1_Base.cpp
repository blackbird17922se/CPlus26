/* DIRECTIVAS DE PREPROCESAMIENTO*/
/*  <iostream> incluye herramientas de entrada/salida*/
#include <iostream> // → cabecera estándar moderna de C++
// <iostream.h>   → estilo antiguo


int main() {

    int edad;

    /* std significa standard y es un namespace.
    Un namespace es como un paquete en Java.
    En Java:
        java.util.ArrayList

    Los :: significan:
        “busca esto dentro de...”

    busca cout dentro del namespace std

    Analogía Java:
        java.util.Scanner */
    
    std::cout << "Hola mundo! :D\n";
    std::cout << "Escribe tu edad: ";

    std::cin >> edad;

    std::cout << "Tu edad es: " << edad << "\n";

    return 0;
}