#include <iostream>

/* #include <iomanip> 
es una librería/cabecera de C++ para dar formato a lo que imprimes o lees.
El nombre viene de:
    input/output manipulation

O sea: manipulación de entrada/salida.
Sirve para cosas como:
    Imprimir números decimales sin notación científica.
        std::fixed

    Definir cuántos decimales mostrar.
        std::setprecision(2)*/
#include <iomanip>


const int TAM_DIRECCION = 30;
const int TAM_CIUDAD    = 25;
const int TAM_BARRIO    = 20;
const int TAM_NOMBRE    = 20;

const int CANT_EMPLEADOS = 2;

struct info_direccion {

    char direccion[TAM_DIRECCION];
    char ciudad[TAM_CIUDAD];
    char barrio[TAM_BARRIO];

};

struct empleado {

    char nombre[TAM_NOMBRE];
    struct info_direccion dir_empleado; // tipo sctruct - nombre struct - alias para el campo
    double salario;

} empleados[CANT_EMPLEADOS]; // Creamos un array pa esa struct, y ponemos cuantas estructuras de tipo empleado crearemos 


int main(){

    for (int i = 0; i < CANT_EMPLEADOS; i++)
    {
        std::cout << "\nDatos Empleado " << i + 1 << ":\n";
        std::cout << "Nombre: ";
        std::cin.getline(empleados[i].nombre, TAM_NOMBRE, '\n');
        std::cout << "Direccion: ";
        std::cin.getline(empleados[i].dir_empleado.direccion, TAM_DIRECCION, '\n');
        std::cout << "Ciudad: ";
        std::cin.getline(empleados[i].dir_empleado.ciudad, TAM_CIUDAD, '\n');
        std::cout << "Barrio: ";
        std::cin.getline(empleados[i].dir_empleado.barrio, TAM_BARRIO, '\n');
        std::cout << "Salario: ";
        std::cin >> empleados[i].salario;
        std::cin.ignore();
        std::cout << "\n";
    }


    // IMPRIMIR
    for (int i = 0; i < CANT_EMPLEADOS; i++)
    {
        std::cout << "\nEMPLEADOS: "
            << "Nombre: " << empleados[i].nombre
            << " - Direccion: " << empleados[i].dir_empleado.direccion
            << " - Ciudad: " << empleados[i].dir_empleado.ciudad
            << " - Barrio: " << empleados[i].dir_empleado.barrio;
        

        /*Imprimir números decimales sin notación científica.
            std::fixed
        Definir cuántos decimales mostrar.
            std::setprecision(2)
        */
        std::cout << std::fixed << std::setprecision(2);
        std::cout << " - Salario: " << empleados[i].salario << ".\n";
    }
    
}