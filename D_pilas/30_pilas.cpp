/*
    PILA usando nodos y punteros.

    Una pila funciona como una torre de platos:
    el último elemento que entra es el primero que sale.

    A esto se le llama LIFO:
    Last In, First Out.
*/
#include <iostream>
#include "../Z_lab1/mi_lib.h"

using namespace std;

// Estructura que representa un nodo de la pila.
struct NODO_MAU {
    INTMAU      dato;       // Un tipo dato X que guardará el nodo
    NODO_MAU    *p_siguiente; // puntero tipo del mismo nodo creado (pa q apunte al siguiente nodo)
};


// PROTOTIPO
// Recibe la pila puntero por referencia para poder modificar su cima.
// p_pila es un puntero recibido por referencia.
// Así la función puede modificar la pila original de main().
void agregarPila(NODO_MAU *&p_pila, INTMAU num);

// en este caso el valor de dato lo extraemos por referencia
void sacarPila(NODO_MAU *&p_pila, INTMAU &num);

int main() {

    INTMAU dato;

    // p_pila apunta a la cima de la pila.
    // Al inicio no hay nodos, por eso apunta a nullptr.
    NODO_MAU *p_pila = nullptr;
    // puede ser tambien 
    // NODO_MAU *p_pila = NULL;


    // ******************** AGREGAR ELEMENTOS DE LA PILA **********************
    cout << "Digite numero: ";
    cin >> dato;
    agregarPila(p_pila, dato);

    cout << "Digite otro numero: ";
    cin >> dato;
    agregarPila(p_pila, dato);

    cout << "\nsacar elementos de la pila: ";
    

    // ******************** SACAR ELEMENTOS DE LA PILA **********************
    // mientras la pila no este vacia
    while (p_pila != NULL){
        sacarPila(p_pila, dato);

        // sirve solo con fines visuales para saber si hay mas elemento en la pila
        if (p_pila != NULL){
            cout << dato << " , ";
        } else{
            cout << dato << ". No hay mas datos en pila";
        }
        
    }
    
    return 0;
}

void agregarPila(NODO_MAU*& p_pila, int dato){

    // 1. Cargar espacio en memoria para nuevo nodo
    // el puntero obtendra acceso a los campos del nodo
    NODO_MAU *p_nodo = new NODO_MAU();

    // 2. Cargar nuestro valor dato dentro del nodo
    p_nodo->dato = dato;

    // 3. Cargar el puntero dentro del nodo
    // El nuevo nodo apunta al nodo que antes estaba en la cima.
    p_nodo->p_siguiente = p_pila;

    // 4. asignar el nuevo nodo a la pila
    // Ahora la cima de la pila será el nuevo nodo.
    p_pila = p_nodo;

    cout << "\nElemento " << dato << " agregado a la pila.\n";

}

void sacarPila(NODO_MAU *&p_pila, INTMAU &dato){
    // 1. Crear variable aux e igualarlo a la pila
    NODO_MAU *p_aux = p_pila;

    // 2. sacamos nuestro dato de la pila ya q esta se va a eliminar
    dato = p_aux->dato;

    // 3. Apuntamos a pila hacia el siguiente nodo ya q el actual lo eliminaremos
    p_pila = p_aux->p_siguiente;

    // 4. Eliminar nodo
    delete p_aux;
}