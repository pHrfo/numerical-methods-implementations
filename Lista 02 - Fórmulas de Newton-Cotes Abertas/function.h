#ifndef FUNCTION_H
#define FUNCTION_H

#include "general.h"


class Function
{

public:
    Function();

    //Metodo que retorna o valor da função f em um ponto
    double f(double);

    //Metodos que calculam o valor da integral em um intervalo,
    //usando formulas de Newton-Cotes, dependendo do grau do po-
    //linômio de substituição g(x) que queremos.
    double integralByNewtonCotes1(double, double);
    double integralByNewtonCotes2(double, double);
    double integralByNewtonCotes3(double, double);
    double integralByNewtonCotes4(double, double);
    double integralByNewtonCotes5(double, double);

    //Método que controla o erro e o numéro de partições por iteração.
    double integralPartitions(double, double, double, int);
};

#endif // FUNCTION_H
