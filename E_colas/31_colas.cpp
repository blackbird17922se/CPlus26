/*
*/
#include <iostream>
#include "../Z_lab1/mi_lib.h"

using namespace std;

struct NODO_MAU {
    INTMAU      dato;
    NODO_MAU    *siguiente;
};


// PROTOTIPOS
// Recibe puntero frente, y fin. y el dato
void insertarElementosEnCola(NODO_MAU*&, NODO_MAU*&, INTMAU);
bool colaVacia(NODO_MAU*);
void suprimirElementoCola(NODO_MAU*&, NODO_MAU*&, INTMAU&);


int main() {

    // Se crean punteros para apuntar al frente y fin de la cola
    NODO_MAU *p_front    = NULL;
    NODO_MAU *p_end      = NULL;
    INTMAU   dato;


    cout << "Digite numero: ";
    cin >> dato;
    insertarElementosEnCola(p_front, p_end, dato);

    cout << "Digite otro numero: ";
    cin >> dato;
    insertarElementosEnCola(p_front, p_end, dato);

    
    // ******************** SACAR ELEMENTOS DE LA PILA **********************
        cout << "\nsacar Nodos de la cola: ";

    // mientras el puntero frente sea diferente a null entonces hay nods pa eliminar
    while (p_front != NULL){
        suprimirElementoCola(p_front, p_end, dato);

        // sirve solo con fines visuales para saber si hay mas elemento en la cola
        if (p_front != NULL){
            cout << dato << " , ";
        } else{
            cout << dato << ". No hay mas datos en la cola";
        }
    }

    return 0;
}

// Recibe puntero frente, y fin. y el dato
void insertarElementosEnCola(NODO_MAU *&p_frente, NODO_MAU *&p_fin, INTMAU num){

    // 1. Creamos nueva instancia de tipo puntero del NODO y le asignamos espacio en memoria
    NODO_MAU *nuevo_nodo = new NODO_MAU();

    // 2. Asignar al nuevo nod el dato q queremos insertar
    nuevo_nodo->dato = num;
    // y el otro campo a NULL
    nuevo_nodo->siguiente = NULL;

    // 3 Asignar punteros frente y fin a nuevo nodo
    if(colaVacia(p_frente)){

        // si cola vacia entonces el frente apunta al nuevo nodo
        p_frente = nuevo_nodo;
    } else{
        // significa q ya hay uno o mas nodos en la cola
        // significa q el puntero debe quedar apuntando al nuevo nodo (que ahora quedo en el fin)
        p_fin->siguiente = nuevo_nodo;
    }

    p_fin = nuevo_nodo;

    cout << "\nElemento " << num << " agregado a la cola.\n";

}

void suprimirElementoCola(NODO_MAU *&p_frente, NODO_MAU *&p_fin, INTMAU &num){

    // 1. sacamos nuestro valor del nodo ya q este se va a eliminar
    // sera del frente porque fue el primero en entrar, primero en salir...
    num = p_frente->dato;

    // 2. Creamos nodo auxiliar y le asignamos el frente
    // porque sera ese nodo del frente el primero en ser eliminado
    NODO_MAU *aux = p_frente;

    // 3. Eliminamos el nodo de la cola
    // primero determinamos si la cola tiene un solo elemento
    // recuerda que CUANDO ES EL ULTIMO NODO, Frente y Fin quedan apuntando
    // al mismo nodo, o sea p_frente sera igual a p_fin
    if(p_frente == p_fin){
        // ponemos a juntos a null, ya q aux queda apuntando al nodo q deseamos eliminar
        p_frente = NULL;
        p_fin = NULL;
    } else{
        // indicamos que ahora el frente va a ser el siguiente nodo
        p_frente = p_frente->siguiente;
    }

    // Borrar nodo
    delete aux;

}

// Funcion que determina si cola esta vacia
bool colaVacia(NODO_MAU *p_frente){

    return (p_frente == NULL) ? true : false;
}
