#ifndef FUNCTION_H
#define FUNCTION_H

#include "general.h"


class Function
{

public:
    Function();

    //Metodo que retorna o valor da função f em um ponto
    double f(double);

    //Metodo que retorna o valor da função g(s) parametrizada
    double g(double, double, double);

    //Método que controla o erro e o numéro de partições por iteração no calculo da integral.
    double integralPartitions(double, double, double, double, double);

    double simpleExponential(double, double, double);


};

#endif // FUNCTION_H
