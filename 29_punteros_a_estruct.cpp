/*
    Punteros || Punteros a Estructura
*/
#include <iostream>
#include "./lab1/mi_lib.h"

using namespace std;

const INTMAU TAM_NOMBRE = 30;

// ESTRUCTURA
struct _PERSONA {
    char     nombre[TAM_NOMBRE];
    INTMAU   edad;
} VAR_PERSONA;

// Se podria declarar el puntero en la misma estructura poniendo una coma
//} VAR_PERSONA, *p_persona = &VAR_PERSONA;


// Crearemos un puntero de tipo _PERSONA, tomando la dir. de memoria de la variable VAR_PERSONA de tipo _PERSONA
_PERSONA *p_persona = &VAR_PERSONA;


// PROTOTIPOS
void pedirDatos();
void mostrarDatos(_PERSONA*);

int main() {
    
    pedirDatos();
    mostrarDatos(p_persona);

    return 0;
}


void pedirDatos() {
    cout << "Digite nombre: ";

    // Para acceder a un campo de la estruct puntero, usamos el ->
    cin.getline(p_persona -> nombre, TAM_NOMBRE, '\n');

    cout << "Digite edad: ";
    cin >> p_persona->edad;

}


void mostrarDatos(_PERSONA* p_person) {

    cout << "\n ***** Datos Persona ***** \n";
    // igualmente para mostrar accedemos con el ->
    cout << "Nombre: "  << p_person->nombre << endl;
    cout << "Edad: "    << p_person->edad   << endl;

}