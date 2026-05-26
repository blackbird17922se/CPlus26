/*
    Pasar un matriz a una función en C++
    Es similar a varam vector, ya que la matriz C++ la toma como param 
    por referencia conado se pasa a una funcion.

    por ende si la funcion modifica alguna de las posiciones, la matriz
    original sera editada.
*/
#include <iostream>
#include "../Z_lab1/mi_lib.h"

const INTMAU NUMFILAS = 2;
const INTMAU NUMCOLUMNAS = 3;


// El número de filas puede omitirse, pero el número de columnas debe estar.
void mostrarMatriz(INTMAU [][NUMCOLUMNAS], INTMAU, INTMAU, STRINGMAU);
void calcularCuadrado(INTMAU [][NUMCOLUMNAS], INTMAU, INTMAU);

// se podria escribir asi
// void mostrarMatriz(INTMAU matriz[NUMFILAS][NUMCOLUMNAS], INTMAU nf, INTMAU nc, STRINGMAU ms);


int main() {

    // paso el campo filas vacio porque C++ deduce que hay 2 filas, pero necesita saber que hay 3 columnas.
    INTMAU matriz[][NUMCOLUMNAS] = {{1,2,3} , {4,5,6}};

    mostrarMatriz(matriz, NUMFILAS, NUMCOLUMNAS, "Matriz Original");
    calcularCuadrado(matriz, NUMFILAS, NUMCOLUMNAS);
    mostrarMatriz(matriz, NUMFILAS, NUMCOLUMNAS, "Matriz Al Cuadrado");

    return 0;
}

void mostrarMatriz(INTMAU matr[][NUMCOLUMNAS], INTMAU numFilas, INTMAU numColumnas, STRINGMAU mensaje){

    std::cout<< "\n" << mensaje << "\n";

    for (INTMAU i = 0; i < numFilas; i++) {
        for (INTMAU j = 0; j < numColumnas; j++) {
            std::cout << matr[i][j] << " ";
        }
        std::cout << "\n";
    }
}

void calcularCuadrado(INTMAU matr[][NUMCOLUMNAS], INTMAU numFilas, INTMAU numColumnas){

    for (INTMAU i = 0; i < numFilas; i++) {
        for (INTMAU j = 0; j < numColumnas; j++) {
            matr[i][j] *=  matr[i][j];
        }
    }

}