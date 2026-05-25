/* paso deparametro por falor y otros por referencia */
#include <iostream>
#include "./lab1/mi_lib.h"

// en el prototipo no es necesario poner nombres de variables, SOLO EL TIPO
void calcular(INTMAU, INTMAU, INTMAU&, INTMAU&);


int main() {

    INTMAU num1 = 5, num2 = 2, resultSuma = 0, resultResta = 0;

    calcular(num1, num2, resultSuma, resultResta);

    // Vemos como calcular() cambio los valores de las var result
    std::cout << "\nResultado suma: " << resultSuma;
    std::cout << "\nResultado resta: " << resultResta;
    
    return 0;
}

// void calcular(num1 por valor, num2 por valor, resultSuma por ref, resultResta por ref)
// importante, no importa la hubicacion del &. puede ir al final del tipo dato o al comienzo de la var
void calcular(INTMAU num1, INTMAU num2, INTMAU& resultSuma, INTMAU &resultResta){

    resultSuma  = num1 + num2;
    resultResta = num1 - num2;

}