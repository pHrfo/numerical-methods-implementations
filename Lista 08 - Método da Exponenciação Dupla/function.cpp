#include "function.h"

Function::Function()
{
    return;
}

double Function::f(double x)
{
    //Usando para os testes a função X².
    //A integral dessa função no intervalo de -1 a 1 é 2/3.
    return pow(x,2);
}

double Function::g(double a, double b, double s)
{
    double x = (a+b)/2 + (b-a)*tanh(sinh(s) + M_PI/2)/2;
    return f(x)*cosh(s)/pow(cosh(sinh(s) + M_PI/2),2);
}


double Function::integralPartitions(double inferior, double superior, double epsilon, double a, double b)
{
    double current_value = 0.1;
    double last_value = 1000;
    double number_of_partitions = 1;
    double deltaX;
    double sum;
    double xi;

    while(fabs((current_value - last_value)/current_value) > epsilon)
    {
        number_of_partitions = 2*number_of_partitions;
        deltaX = (superior - inferior)/number_of_partitions;
        sum = 0;

        for (int i=0; i<number_of_partitions; i++)
        {
            xi = inferior + i*deltaX;
            sum = sum + deltaX*(g(a, b, xi) + g(a, b, xi + deltaX))/2;
        }
        last_value = current_value;
        current_value = sum;

    }

    return current_value;
}

double Function::simpleExponential(double a, double b, double epsilon)
{
    double inf=-1;
    double sup= 1;
    double last_value = 0;
    double current_value = 0;

    current_value = ((b-a)/2)*integralPartitions(inf, sup, epsilon, a, b);

    while(fabs((current_value - last_value)/current_value) > epsilon)
    {
        last_value = current_value;
        inf = inf*1.05;
        sup = sup*1.05;
        current_value = ((b-a)/2)*integralPartitions(inf, sup, epsilon, a, b);
    }

    return current_value;

}



















