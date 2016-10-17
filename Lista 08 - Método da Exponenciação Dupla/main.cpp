#include <QCoreApplication>
#include "general.h"
#include "function.h"

int main(int argc, char *argv[])
{
    Function func;
    double inferior, superior, epsilon;

    cout << "Enter the lower bound of the integration interval:" << endl;
    cin >> inferior;
    cout << "Enter the upper bound of the integration interval:" << endl;
    cin >> superior;
    cout << "Enter the maximum relative error that is going to be accepted:" << endl;
    cin >> epsilon;

    cout << endl << "Integral of f(x) = " << func.simpleExponential(inferior, superior, epsilon) << endl;

}
