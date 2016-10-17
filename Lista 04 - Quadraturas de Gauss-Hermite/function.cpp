#include "function.h"

Function::Function()
{
    return;
}

double Function::f(double x)
{
    //Usando para os testes a função x².
    //A integral de e^(-x²) * x² de -inf
    //a inf é igual a 0.886227.
    return pow(x,2);
}


double Function::integralByGaussHermite1()
{
    double root1 = -0.70710678;
    double root2 = 0.70710678;

    double value = (0.88622692*f(root1) + 0.88622692*f(root2));

    return value;
}

double Function::integralByGaussHermite2()
{
    double root1 = -1.22474487;
    double root2 = 0.0000000000;
    double root3 = 1.22474487;

    double value = (0.29540897*f(root1) + 1.18163590*f(root2) + 0.29540897*f(root3));

    return value;
}


double Function::integralByGaussHermite3()
{
    double root1 = -0.52464762;
    double root2 = -1.65068012;
    double root3 = 1.65068012;
    double root4 = 0.52464762;

    double value = (0.80491409*f(root1) + 0.08131283*f(root2) + 0.08131283*f(root3) + 0.80491409*f(root4));

    return value;
}

double Function::integralByGaussHermite4()
{
    double root1 = -2.020182870;
    double root2 = -0.958572464;
    double root3 = 0.0000000000;
    double root4 = 0.958572464;
    double root5 = 2.020182870;

    double value = (0.01995324*f(root1) + 0.39361932*f(root2) + 0.94530872*f(root3) + 0.39361932*f(root4) + 0.01995324*f(root5));

    return value;
}

double Function::integralByGaussHermite5()
{
    double root1 = -2.3506049736;
    double root2 = -1.3358490740;
    double root3 = -0.4360774119;
    double root4 = 0.4360774119;
    double root5 = 1.3358490740;
    double root6 = 2.3506049736;

    double value = (0.004530009*f(root1) + 0.1570673203*f(root2) + 0.724629595*f(root3) + 0.724629595*f(root4) + 0.1570673203*f(root5) + 0.004530009*f(root6));

    return value;
}

double Function::integralPartitions(int roots)
{
    double sum = 0;
    switch(roots)
    {
        case 2:

            sum = integralByGaussHermite1();

        break;

        case 3:

            sum = integralByGaussHermite2();

        break;

        case 4:

            sum = integralByGaussHermite3();

        break;

        case 5:

            sum = integralByGaussHermite4();

        break;

        case 6:

            sum = integralByGaussHermite5();

        break;
    }


    return sum;
}
