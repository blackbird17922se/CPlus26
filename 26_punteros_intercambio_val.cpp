/*
 Aqui se intercambiaran los valores de unas variables pero usando sus direcciones de 
 memoria, como si fuera por referencia
*/
#include <iostream>
#include "./lab1/mi_lib.h"

using namespace std;


void intercambiarValores(INTMAU*, INTMAU*);

int main() {

    INTMAU num1 = 20, num2 = 7;

    cout << "Primer numero: " << num1 << endl;
    cout << "Segundo numero: " << num2 << endl;

    // le pasamos la direccion de memoria de las variables
    intercambiarValores(&num1, &num2);

    cout << "\nDespues de Intercambio \n";
    cout << "Primer numero: " << num1 << endl;
    cout << "Segundo numero: " << num2 << endl;
    
    return 0;
}

// indicamos q los parametros son int pero seran de tipo puntero q recibiran la dir. memoria
void intercambiarValores(INTMAU *p_num1, INTMAU *p_num2){

    INTMAU aux;

    aux = *p_num1;

    *p_num1 = *p_num2;

    *p_num2 = aux;
    
}