#include "function.h"

Function::Function()
{
    return;
}

double Function::f(double x)
{
    //Usando para os testes a função 30x⁴ - 2x³ + 8x - 12.5.
    //A integral dessa função no intervalo de -1 a 1 é -13.
    return pow(x,11);
}


double Function::integralByGaussLegendre1(double inferior, double superior)
{
    double root1 = -0.5773502691;
    double root2 = 0.5773502691;

    double x1 = (inferior + superior)/2 + (superior - inferior)*root1/2;
    double x2 = (inferior + superior)/2 + (superior - inferior)*root2/2;

    double value = ((superior - inferior)/2)*(1*f(x1) + 1*f(x2));

    return value;
}

double Function::integralByGaussLegendre2(double inferior, double superior)
{
    double root1 = -0.7745966692;
    double root2 = 0.0000000000;
    double root3 = 0.7745966692;

    double x1 = (inferior + superior)/2 + (superior - inferior)*root1/2;
    double x2 = (inferior + superior)/2 + (superior - inferior)*root2/2;
    double x3 = (inferior + superior)/2 + (superior - inferior)*root3/2;

    double value = ((superior - inferior)/2)*(0.5555555555*f(x1) + 0.8888888888*f(x2) + 0.5555555555*f(x3));

    return value;
}


double Function::integralByGaussLegendre3(double inferior, double superior)
{
    double root1 = -0.8611363115;
    double root2 = -0.3399810435;
    double root3 = 0.3399810435;
    double root4 = 0.8611363115;

    double x1 = (inferior + superior)/2 + (superior - inferior)*root1/2;
    double x2 = (inferior + superior)/2 + (superior - inferior)*root2/2;
    double x3 = (inferior + superior)/2 + (superior - inferior)*root3/2;
    double x4 = (inferior + superior)/2 + (superior - inferior)*root4/2;

    double value = ((superior - inferior)/2)*(0.3478548451*f(x1) + 0.6521451548*f(x2) + 0.6521451548*f(x3) + 0.3478548451*f(x4));

    return value;
}

double Function::integralByGaussLegendre4(double inferior, double superior)
{
    double root1 = -0.9061798459;
    double root2 = -0.5384693101;
    double root3 = 0.0000000000;
    double root4 = 0.5384693101;
    double root5 = 0.9061798459;

    double x1 = (inferior + superior)/2 + (superior - inferior)*root1/2;
    double x2 = (inferior + superior)/2 + (superior - inferior)*root2/2;
    double x3 = (inferior + superior)/2 + (superior - inferior)*root3/2;
    double x4 = (inferior + superior)/2 + (superior - inferior)*root4/2;
    double x5 = (inferior + superior)/2 + (superior - inferior)*root5/2;

    double value = ((superior - inferior)/2)*(0.2369268850*f(x1) + 0.4786286704*f(x2) + 0.5688888888*f(x3) + 0.4786286704*f(x4) + 0.2369268850*f(x5));

    return value;
}

double Function::integralByGaussLegendre5(double inferior, double superior)
{
    double root1 = -0.9324695142;
    double root2 = -0.6612093864;
    double root3 = -0.2386191860;
    double root4 = 0.2386191860;
    double root5 = 0.6612093864;
    double root6 = 0.9324695142;

    double x1 = (inferior + superior)/2 + (superior - inferior)*root1/2;
    double x2 = (inferior + superior)/2 + (superior - inferior)*root2/2;
    double x3 = (inferior + superior)/2 + (superior - inferior)*root3/2;
    double x4 = (inferior + superior)/2 + (superior - inferior)*root4/2;
    double x5 = (inferior + superior)/2 + (superior - inferior)*root5/2;
    double x6 = (inferior + superior)/2 + (superior - inferior)*root6/2;

    double value = ((superior - inferior)/2)*(0.1713244923*f(x1) + 0.3607615730*f(x2) + 0.4679139345*f(x3) + 0.4679139345*f(x4) + 0.3607615730*f(x5) + 0.1713244923*f(x6));

    return value;
}

double Function::integralPartitions(double inferior, double superior, double epsilon, int roots)
{
    double current_value = 0.1;
    double last_value = 1000;
    double number_of_partitions = 1;
    double deltaX;
    double sum;
    double x;
    double xi;
    double xf;

    while(fabs((current_value - last_value)/current_value) > epsilon)
    {
        number_of_partitions = 2*number_of_partitions;
        deltaX = (superior - inferior)/number_of_partitions;
        sum = 0;

        for (int i=0; i<number_of_partitions; i++)
        {
            xi = inferior + i*deltaX;
            xf = inferior + (i+1)*deltaX;

            switch(roots)
            {
                case 2:

                    sum = sum + integralByGaussLegendre1(xi, xf);

                break;

                case 3:

                    sum = sum + integralByGaussLegendre2(xi, xf);

                break;

                case 4:

                    sum = sum + integralByGaussLegendre3(xi, xf);

                break;

                case 5:

                    sum = sum + integralByGaussLegendre4(xi, xf);

                break;

                case 6:

                    sum = sum + integralByGaussLegendre5(xi, xf);

                break;
            }

//            cout << sum << endl << endl;
        }

        last_value = current_value;
        current_value = sum;

    }

    return current_value;
}
