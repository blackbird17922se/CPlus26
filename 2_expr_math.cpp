#include <iostream>

int main(int argc, char const *argv[])
{
    float a, b, c, d, e, f, resultado;

    std::cout << "Inserte valor a: ";
    std::cin >> a;
    std::cout << "Inserte valor b: ";
    std::cin >> b;
    std::cout << "Inserte valor c: ";
    std::cin >> c;
    std::cout << "Inserte valor d: ";
    std::cin >> d;
    std::cout << "Inserte valor e: ";
    std::cin >> e;
    std::cout << "Inserte valor f: ";
    std::cin >> f;

    resultado = (a + b/c) / (d + e/f);
    
    std::cout.precision(2); // redondeo decimales!
    std::cout << "Resultado: " << resultado << std::endl;


    /****************************** ejercicio 2 ************************************ */
    std::cout << "\n********* ejercicio 2 *********** \n";

    std::cout << "Inserte valor a: ";
    std::cin >> a;
    std::cout << "Inserte valor b: ";
    std::cin >> b;
    std::cout << "Inserte valor c: ";
    std::cin >> c;
    std::cout << "Inserte valor d: ";
    std::cin >> d;

    std::cout.precision(3); // redondeo decimales!
    resultado = a + b/(c-d);
    std::cout << "Resultado ejercicio dos es:\n" << resultado << std::endl;

    return 0;
}
