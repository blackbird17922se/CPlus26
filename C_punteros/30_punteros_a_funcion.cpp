/*
    Un puntero a función es una variable que no guarda un número ni un texto, 
    sino la dirección de una función. Eso permite decidir en tiempo de ejecución 
    qué función ejecutar.

    Por ejemplo, si tienes varias funciones con la misma forma:
        INTMAU sumar(INTMAU, INTMAU);
        INTMAU restar(INTMAU, INTMAU);

    puedes crear un puntero así:
        INTMAU (*p_operacion)(INTMAU, INTMAU);

    Eso significa: “p_operacion puede apuntar a cualquier función que devuelva 
    INTMAU y reciba dos INTMAU”.

    Entonces puedes hacer:
        p_operacion = sumar;
        p_operacion(2, 3); // ejecuta sumar

        p_operacion = restar;
        p_operacion(2, 3); // ejecuta restar

    En palabras simples: es como tener un control remoto que puede cambiar entre 
    botones. El control remoto es el puntero, y las funciones son las acciones.

    Se usan cuando quieres elegir una operación dinámicamente, por ejemplo en menús, 
    calculadoras, callbacks, sistemas de eventos, APIs antiguas de C/Windows, hilos, 
    señales o motores donde una función debe “llamar otra función” sin saber
    exactamente cuál será hasta el momento de ejecución.

    Idea clave:
        Puntero normal       → apunta a datos
        Puntero a función    → apunta a código ejecutable
*/
#include <iostream>
#include "../mi_lib.h"

using namespace std;

INTMAU sumar(INTMAU, INTMAU);
INTMAU restar(INTMAU, INTMAU);

int main() {

    // Puntero a función.
    // Puede apuntar a funciones que:
    // - devuelvan INTMAU
    // - reciban dos INTMAU
    INTMAU (*p_operacion)(INTMAU, INTMAU);
    /*
        Esto:
            INTMAU (*p_operacion)(INTMAU, INTMAU);

        define un puntero que solo puede apuntar a funciones con esta “forma”:
            INTMAU funcion(INTMAU, INTMAU);
        O sea:
            retorna INTMAU
            recibe INTMAU
            recibe INTMAU

        Entonces puede apuntar a:
            INTMAU sumar(INTMAU a, INTMAU b);
            INTMAU restar(INTMAU a, INTMAU b);
            INTMAU multiplicar(INTMAU a, INTMAU b);

        Pero NO a:
            void saludar();
            double dividir(double a, double b);
            INTMAU cuadrado(INTMAU a);
    */


    // Ahora el puntero apunta a la función sumar.
    p_operacion = sumar;

    INTMAU result = p_operacion(2, 3);
    cout << "Resultado suma: " << result << "\n";


    // Ahora el mismo puntero apunta a la función restar.
    p_operacion = restar;

    result = p_operacion(2, 3);
    cout << "Resultado resta: " << result << "\n";
    
    return 0;
}

INTMAU sumar(INTMAU a, INTMAU b) {
    return a + b;
}

INTMAU restar(INTMAU a, INTMAU b) {
    return a - b;
}
