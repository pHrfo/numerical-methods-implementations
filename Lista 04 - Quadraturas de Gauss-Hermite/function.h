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
    double integralByGaussHermite1();
    double integralByGaussHermite2();
    double integralByGaussHermite3();
    double integralByGaussHermite4();
    double integralByGaussHermite5();

    //Método que controla o erro e o numéro de partições por iteração.
    double integralPartitions(int);
};

#endif // FUNCTION_H
