#include "function.h"

Function::Function()
{
    return;
}

double Function::f(double x)
{
    //Usando para os testes a função x².
    //A integral de sqrt(1-x²) * x² no
    //intervalo [-1;1] é igual à 1.5708
    //Note que, como essa função é de grau
    //dois, o número de pontos necessários
    //pra calcular essa integral é pelo
    //menos 2.
    return pow(x,2);
}


double Function::integralByGaussChebyshev(int degree)
{
    double sum = 0;
    double xk;

    for (int i=0; i<degree; i++)
    {
        xk = cos((2*i-1)*M_PI/(2*degree));
        sum = sum + f(xk);
    }

    sum = sum*M_PI/degree;

    return sum;
}
