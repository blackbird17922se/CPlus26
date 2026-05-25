/*
    Pasar estructuras a funciones en C++

    En este ejemplo veremos dos formas:

    1. Paso por valor:
       La función recibe una COPIA de la estructura.
       Si la función modifica esa copia, la estructura original NO cambia.

    2. Paso por referencia:
       La función recibe la estructura ORIGINAL.
       Si la función modifica el parámetro, también cambia la variable original.
*/

#include <iostream>
#include "./lab1/mi_lib.h"

using namespace std;

// Estructura PERSONA.
// Usaremos esta para el ejemplo de paso por valor.
struct _PERSONA {
    char nombre[30];
    INTMAU edad;
} VAR_PERSONA;

// Estructura EMPLEADO.
// Usaremos esta para el ejemplo de paso por referencia.
struct _EMPLEADO {
    char nombre[30];
    INTMAU edad;
    double salario;
};

// PROTOTIPOS
void pedirDatosPersona();
void mostrarDatosPersona(_PERSONA person); // paso por valor

void pedirDatosEmpleado(_EMPLEADO &empleado);   // paso por referencia
void mostrarDatosEmpleado(_EMPLEADO empleado);  // paso por valor solo para mostrar

int main() {
    // CASO 1: estructura global pasada por valor
    pedirDatosPersona();
    mostrarDatosPersona(VAR_PERSONA);

    cout << "\n\n--------------------------\n\n";

    // CASO 2: estructura local pasada por referencia
    _EMPLEADO empleado1;

    pedirDatosEmpleado(empleado1);

    // Aquí pasamos la instancia empleado1 a la función.
    // Como empleado1 ya fue llenado/modificado en pedirDatosEmpleado(),
    // mostrarDatosEmpleado() recibirá esos datos actualizados.
    mostrarDatosEmpleado(empleado1);

    return 0;
}

// Llena la variable global VAR_PERSONA.
void pedirDatosPersona() {
    cout << "DATOS PERSONA\n";

    cout << "Nombre: ";
    cin.getline(VAR_PERSONA.nombre, 30, '\n');

    cout << "Edad: ";
    cin >> VAR_PERSONA.edad;

    cin.ignore();
}

// Recibe una copia de VAR_PERSONA.
void mostrarDatosPersona(_PERSONA person) {
    cout << "\nDatos persona:";
    cout << "\nNombre: " << person.nombre;
    cout << "\nEdad: " << person.edad;
}

// Recibe empleado por referencia.
// El símbolo & indica que NO recibe una copia,
// sino la variable original enviada desde main().
void pedirDatosEmpleado(_EMPLEADO &empleado) {
    cout << "DATOS EMPLEADO\n";

    cout << "Nombre: ";
    cin.getline(empleado.nombre, 30, '\n');

    cout << "Edad: ";
    cin >> empleado.edad;

    cout << "Salario: ";
    cin >> empleado.salario;

    cin.ignore();
}

// Aquí no modificamos el empleado, solo lo mostramos.
// Por ahora lo dejamos por valor para comparar,
// aunque más adelante sería mejor usar const referencia.
void mostrarDatosEmpleado(_EMPLEADO empleado) {
    cout << "\nDatos empleado:";
    cout << "\nNombre: " << empleado.nombre;
    cout << "\nEdad: " << empleado.edad;
    cout << "\nSalario: " << empleado.salario;
}