/*
    PUNTEROS
    Un puntero es una VARIABLE que va a ALMACENAR la DIRECCION DE MEMORIA
    donde esta guardando otra variable.
*/
#include <iostream>
#include "../Z_lab1/mi_lib.h"

using namespace std;

int main() {

    INTMAU num = 20;

    // definicion de la variable puntero para almacenar la dir de memoria
    // estructura:
    // tipoDato de la variable a la cual le queremos guardar la dir de memoria - asterisco* - nombreVarPuntero
    INTMAU *p_dir_num;

    // aqui asignamos a la var puntero, la direccion de memoria (&) de var num
    p_dir_num = &num;

    // al imprimirlo asi * obtendremos lo que hay en esa dir memoria del puntero (20)
    cout << "Numero: " << *p_dir_num << endl;

    // al imprimirlo asi, sin el * obtendremos lo que hay en esa dir memoria del puntero (20)
    cout << "Direccion de memoria (var puntero): " << p_dir_num << endl;

    // USANDO EL &
    // con el & obtenemos la direccion en la memoria (no el valor de la var)
    // mostrara la direccion en hexadecimal (ej: 0x72be7ff6dc)
    cout << "Direccion de memoria USANDO EL &: " << &num << endl;

    
    return 0;
}

/*En la vida real los punteros se usan cuando necesitas trabajar con direcciones de memoria en vez de solo valores.

Casos comunes:

1. Modificar datos originales desde una función

Parecido a referencias:

    void cambiar(int *x) {
        *x = 99;
    }

2. Trabajar con arreglos y cadenas estilo C
Un arreglo muchas veces se maneja como dirección del primer elemento.

    int numeros[3] = {1, 2, 3};
    int *p = numeros;

3. Crear memoria dinámica
Cuando no sabes cuántos datos tendrás hasta que el programa corre.

    int *datos = new int[100];
    delete[] datos;

Aunque en C++ moderno se prefiere:

std::vector<int>

4. Estructuras enlazadas
Listas, árboles, grafos:

    struct Nodo {
        int dato;
        Nodo *siguiente;
    };

5. APIs de C, Windows o sistemas operativos
Muchísimas funciones antiguas o de bajo nivel usan punteros:

    HANDLE
    void*
    char*
    DWORD*

6. Polimorfismo y objetos dinámicos
Trabajar con clases base e hijas:

    Animal *a = new Perro();

7. Hardware, drivers, videojuegos, motores gráficos
Ahí se usan para controlar memoria, buffers, imágenes, audio, dispositivos, etc.

************************
La versión humana:
    Un puntero es una variable que guarda “dónde vive otra cosa”.

Para empezar, aprende bien estas 3 ideas:

    &variable  → dame la dirección
    puntero    → guarda una dirección
    *puntero   → accede al valor que vive en esa dirección
*/