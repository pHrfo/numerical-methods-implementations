#include <QCoreApplication>
#include "general.h"
#include "function.h"

int main(int argc, char *argv[])
{
    Function func;
    int points;

    cout << "Enter the number of points you want:" << endl;
    cin >> points;

    cout << "The integral of f(x) is " << func.integralByGaussChebyshev(points) << endl;


}
