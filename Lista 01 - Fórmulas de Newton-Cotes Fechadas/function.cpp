#include "function.h"

Function::Function()
{
    return;
}

double Function::f(double x)
{
    //Usando para os testes a função 30x⁴ - 2x³ + 8x - 12.5.
    //A integral dessa função no intervalo de -1 a 1 é -13.
    return pow(log(x),7);
}


double Function::integralByNewtonCotes2(double inferior, double superior)
{
    double f1;
    double f2;
    double f3;
    double value;
    double deltaX;

    deltaX = (superior - inferior);
    f1 = f(inferior);
    f2 = f((inferior + superior)/2);
    f3 = f(superior);
    value = (deltaX/6)*(f1 + 4*f2 + f3);

    return value;
}


double Function::integralByNewtonCotes3(double inferior, double superior)
{
    double f1;
    double f2;
    double f3;
    double f4;
    double value;
    double deltaX;

    deltaX = (superior - inferior);
    f1 = f(inferior);
    f2 = f(inferior + deltaX/3);
    f3 = f(inferior + deltaX*2/3);
    f4 = f(superior);
    value = (deltaX*3/24)*(f1 + 3*f2 + 3*f3 + f4);

    return value;
}

double Function::integralByNewtonCotes4(double inferior, double superior)
{
    double f1;
    double f2;
    double f3;
    double f4;
    double f5;
    double value;
    double deltaX;

    deltaX = (superior - inferior);
    f1 = f(inferior);
    f2 = f(inferior + deltaX/4);
    f3 = f(inferior + deltaX/2);
    f4 = f(inferior + deltaX*3/4);
    f5 = f(superior);
    value = (deltaX/90)*(7*f1 + 32*f2 + 12*f3 + 32*f4 + 7*f5);

    return value;
}

double Function::integralByNewtonCotes5(double inferior, double superior)
{
    double f1;
    double f2;
    double f3;
    double f4;
    double f5;
    double f6;
    double value;
    double deltaX;

    deltaX = (superior - inferior);
    f1 = f(inferior);
    f2 = f(inferior + deltaX/5);
    f3 = f(inferior + deltaX*2/5);
    f4 = f(inferior + deltaX*3/5);
    f5 = f(inferior + deltaX*4/5);
    f6 = f(superior);
    value = (deltaX/288)*(19*f1 + 75*f2 + 50*f3 + 50*f4 + 75*f5 + 19*f6);

    return value;
}

double Function::integralPartitions(double inferior, double superior, double epsilon, int degree)
{
    double current_value = 0.1;
    double last_value = 1000;
    double number_of_partitions = 1;
    double deltaX;
    double sum;
    double x;
    double xi;
    double xp;

    while(fabs((current_value - last_value)/current_value) > epsilon)
    {
        number_of_partitions = 2*number_of_partitions;
        deltaX = (superior - inferior)/number_of_partitions;
        sum = 0;

        for (int i=0; i<number_of_partitions; i++)
        {
            x = inferior + i*deltaX;
            xi = x + deltaX;

            switch(degree)
            {
                case 0:
                //Caso da integral por retângulo!

                    xp = inferior + deltaX*i;
                    sum = sum + deltaX*f(xp);

                break;

                case 1:
                //Caso da integral por Trapézio

                    xi = inferior + i*deltaX;
                    sum = sum + deltaX*(f(xi) + f(xi + deltaX))/2;

                break;

                case 2:
                //Newton-Cotes com grau 2

                    sum = sum + integralByNewtonCotes2(x, xi);

                break;

                case 3:
                //Newton-Cotes com grau 3

                    sum = sum + integralByNewtonCotes3(x, xi);

                break;

                case 4:
                //Newton-Cotes com grau 4

                    sum = sum + integralByNewtonCotes4(x, xi);

                break;

                case 5:
                //Newton-Cotes com grau 5

                sum = sum + integralByNewtonCotes5(x, xi);

                break;
            }

//            cout << sum << endl << endl;
        }

        last_value = current_value;
        current_value = sum;

    }

    return current_value;
}
