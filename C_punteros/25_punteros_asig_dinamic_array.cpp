/*
    ASIGNACIÓN DINÁMICA DE ARREGLOS

    Normalmente, un arreglo clásico necesita un tamaño conocido
    antes de compilar:

        int notas[5];

    Pero si el tamaño lo decide el usuario mientras el programa se ejecuta,
    necesitamos reservar memoria dinámicamente.

    Para eso usamos:

        new[]     -> reserva memoria para varios elementos
        delete[]  -> libera esa memoria cuando ya no la necesitamos

    IMPORTANTE:
    Si usamos new[], debemos liberar con delete[].
*/
#include <iostream>
#include "../Z_lab1/mi_lib.h"

using namespace std;


// PROTOTIPOS
void pedirNotas();
void mostrarNotas();


// VARIABLES GLOBALES
INTMAU numCalificaciones;

// VARIABLE PUNTERO
// Puntero que guardará la dirección del primer elemento
// del arreglo dinámico.
// En otras palabras: un puntero que apunta a un array dinámico.
INTMAU *p_calificaciones;

int main() {
    
    pedirNotas();
    mostrarNotas();

    // Liberamos la memoria que reservamos con new[].
    // Si no hacemos esto, queda memoria ocupada innecesariamente.
    delete[] p_calificaciones;

    // Buena práctica: después de liberar, dejamos el puntero en nullptr.
    p_calificaciones = nullptr;

    return 0;
}

void pedirNotas(){
    cout << "Digite numero de calificaciones: ";
    cin >> numCalificaciones;


    // Reservamos memoria para numCalificaciones enteros.
    // new[] permite crear el arreglo en tiempo de ejecución, cuando ya sabes cuántas notas quiere el usuario.
    //
    // Ejemplo:
    // Si numCalificaciones vale 5, se crea algo parecido a:
    //
    // [ _ ][ _ ][ _ ][ _ ][ _ ]
    //
    // p_calificaciones apunta al primer elemento.
    p_calificaciones = new INTMAU[numCalificaciones];

    for (int i = 0; i < numCalificaciones; i++) {
        cout << "Digite una nota: ";

        // p_calificaciones[i] accede a la posición i del arreglo dinámico.
        cin >> p_calificaciones[i];
    }
    
}


void mostrarNotas(){
    cout << "\n\nMostrar notas del usuario: \n";
    for (int i = 0; i < numCalificaciones; i++)
    {
        cout << p_calificaciones[i] << endl;
    }
    
}