/* En C++, cuando queremos guardar textos que pueden tener espacios, como un nombre completo,
una dirección o una frase, es mejor usar `std::getline()` en lugar de `std::cin >>`.
La razón es que `std::cin >>` solo lee hasta encontrar el primer espacio, por lo que si escribes
`Juan David Pérez`, solo guardará `Juan`. En cambio, `std::getline(std::cin, variable)` lee toda
la línea completa, incluyendo los espacios, hasta que presionas Enter. Por eso `getline` es
la opción más adecuada cuando se trabaja con cadenas de texto largas o compuestas. Solo hay
que tener cuidado si antes se leyó un número con `cin`, porque puede quedar un salto de línea
pendiente; en ese caso se usa `std::cin.ignore()` antes del `getline`.
*/
#include <iostream>
#include <string.h> // para usar strlen()

int main()
{

    // Constante que define el tamaño máximo del arreglo de caracteres.
    // En este caso, el nombre puede ocupar hasta 19 caracteres visibles,
    // porque el último espacio se reserva para el caracter especial '\0'.
    const int TAM_CADENA = 50;

    // char nombre[numero de elementos]
    char nombre[TAM_CADENA];

    char nombre2[] = "Mau"; // Asigando valores

    std::cout << "Ingrese su nombre \n";

    // Lee una línea completa desde teclado, incluyendo espacios.
    // Guarda el texto dentro del arreglo nombre.
    // TAM_CADENA indica el máximo de caracteres que puede leer.
    // '\n' indica que debe dejar de leer cuando el usuario presione Enter.
    std::cin.getline(nombre, TAM_CADENA, '\n');

    std::cout << nombre;

    // strlen(nombre) devuelve en entero la longitud de una cadena contando espacios
    std::cout << "\nLongitud cadena: " << strlen(nombre);
}