#ifndef FUNCTION_H
#define FUNCTION_H

#include "general.h"


class Function
{

public:
    Function();

    //Metodo que retorna o valor da função f em um ponto
    double f(double);

    double integralByGaussChebyshev(int);
};

#endif // FUNCTION_H
