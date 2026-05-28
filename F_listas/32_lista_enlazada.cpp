/*
    LISTA ENLAZADA ORDENADA

    Una lista enlazada es una estructura donde cada nodo guarda:

    1. Un dato
    2. La dirección del siguiente nodo

    Ejemplo:

        [3 | sig] -> [8 | sig] -> [15 | NULL]

    En este programa insertaremos números manteniendo la lista ordenada
    de menor a mayor.
*/
#include <iostream>
#include "../Z_lab1/mi_lib.h"

using namespace std;

// Estructura del nodo
struct NODO_MAU {
    INTMAU dato;             // Valor que guarda el nodo
    NODO_MAU *siguiente;     // Puntero al siguiente nodo
};

//(puntero x referencia, dato a insertar)
void insertarLista(NODO_MAU*&, INTMAU);


int main() {

    // lista apunta al primer nodo.
    // Como todavía no hay nodos, empieza en nullptr.
    NODO_MAU *lista = NULL;

    insertarLista(lista, 8);
    insertarLista(lista, 3);
    insertarLista(lista, 15);
    insertarLista(lista, 10);
    
    return 0;
}

void insertarLista(NODO_MAU*& lista, INTMAU num){

    // 1. Creamos un nuevo nodo en memoria dinámica.
    NODO_MAU *nuevo_nodo = new NODO_MAU();

    // 2. Guardamos el número dentro del nuevo nodo
    nuevo_nodo->dato = num;

    // 3. Crear 2 nodos auxiliares
    // al primero se le asigna lista
    // aux1 recorrerá la lista buscando la posición correcta.
    NODO_MAU *aux1 = lista;

    // 4. aux2 recordará el nodo anterior a aux1. o en su defecto null
    NODO_MAU *aux2 = NULL;

    
    /*
        Este while busca dónde insertar el nuevo número.

        Mientras:
        - no lleguemos al final de la lista
        - y el dato actual sea menor que el número nuevo

        seguimos avanzando.

        Ejemplo: lista = 3 -> 8 -> 15
        queremos insertar 10

        aux1 mira 3, luego 8, luego 15.
        Se detiene en 15 porque 15 ya no es menor que 10.
    */
    while ((aux1 != nullptr) && (aux1->dato < num)) {
        // aux2 se queda en el nodo actual
        aux2 = aux1;

        // aux1 avanza al siguiente nodo
        aux1 = aux1->siguiente;
    }

    /*
        CASO 1: insertar al inicio.

        Si lista == aux1 significa que aux1 nunca avanzó.

        Eso pasa cuando:
        - la lista está vacía
        - o el número nuevo debe ir antes del primer nodo

        Ejemplo:
            lista = 8 -> 15
            num = 3

        Resultado:
            3 -> 8 -> 15
    */
    if (lista == aux1) {
        lista = nuevo_nodo;
    }
    /*
        CASO 2: insertar en medio o al final.

        aux2 apunta al nodo anterior.
        Entonces hacemos que aux2 apunte al nuevo nodo.

        Ejemplo medio:
            3 -> 8 -> 15
            insertar 10

            aux2 = 8
            aux1 = 15

            queda:
            8 -> 10 -> 15

        Ejemplo final:
            3 -> 8 -> 15
            insertar 20

            aux2 = 15
            aux1 = nullptr

            queda:
            15 -> 20 -> nullptr
    */
    else {
        aux2->siguiente = nuevo_nodo;
    }

    /*
        Ahora conectamos el nuevo nodo con el nodo que debe quedar después.

        Si va al inicio:
            nuevo_nodo -> antiguo primer nodo

        Si va en medio:
            nuevo_nodo -> nodo siguiente

        Si va al final:
            nuevo_nodo -> nullptr
    */
    nuevo_nodo->siguiente = aux1;

    cout << "Elemento " << num << " insertado correctamente.\n";
}