#include <iostream>

const int TAM_TITULO    = 30;
const int TAM_ARTISTA   = 25;
const int TAM_FECHA     = 20;

// Una estructura es una coleccion de datos que puede ser de diversos tipos.
struct coleccion_CD {

    // CAMPOS
    char    titulo[TAM_TITULO];
    char    artista[TAM_ARTISTA];
    int     numeroCanciones;
    float   precio;
    char    fechaCompra[TAM_FECHA];

} VALLENATO, MERENGUE, POP; // Aqui Creas las variables deseadas, cada una contiene los campos de la struct


int main() {

    std::cout << "Ingrese datos CD VALLENATO \n";
    std::cout << "Titulo: ";
    std::cin.getline(VALLENATO.titulo, TAM_TITULO, '\n');
    std::cout << "Artista: ";
    std::cin.getline(VALLENATO.artista, TAM_ARTISTA, '\n');
    std::cout << "Num Canciones: ";
    std::cin >> VALLENATO.numeroCanciones;
    std::cout << "Precio: ";
    std::cin >> VALLENATO.precio;
    std::cout << "Fecha Compra: ";

    // Como antes usamos std::cin >> para leer números,
    // quedó un salto de línea pendiente en el buffer.
    // Si no lo ignoramos, getline leería ese Enter vacío
    // y se saltaría la fecha de compra.
    std::cin.ignore();
    std::cin.getline(VALLENATO.fechaCompra, TAM_FECHA, '\n');

    std::cout << "\nDatos del CD: "
        << "Titulo: " << VALLENATO.titulo
        << " - Artista: " << VALLENATO.artista
        << " - Num. Canciones: " << VALLENATO.numeroCanciones
        << " - Precio: " << VALLENATO.precio
        << " - Fecha Compra: " << VALLENATO.fechaCompra
        << ".\n";


    // **************** PODEMOS USAR LA OTRA VARIABLE, SIN ALGUNOS CAMPOS ************//
    std::cout << "Ingrese datos CD POP \n";
    std::cout << "Titulo: ";
    std::cin.getline(POP.titulo, TAM_TITULO, '\n');
    std::cout << "Artista: ";
    std::cin.getline(POP.artista, TAM_ARTISTA, '\n');
    //std::cout << "Num Canciones: ";
    //std::cin >> POP.numeroCanciones;
    //std::cout << "Precio: ";
    //std::cin >> POP.precio;
    std::cout << "Fecha Compra: ";
    std::cin.getline(POP.fechaCompra, TAM_FECHA, '\n');

    std::cout << "\nDatos del CD: "
        << "Titulo: " << POP.titulo
        << " - Artista: " << POP.artista
        << " - Num. Canciones: " << POP.numeroCanciones
        << " - Precio: " << POP.precio
        << " - Fecha Compra: " << POP.fechaCompra
        << ".\n";

    return 0;
}