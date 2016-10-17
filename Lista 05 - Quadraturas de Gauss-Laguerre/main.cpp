#include <QCoreApplication>
#include "general.h"
#include "function.h"

int main(int argc, char *argv[])
{
    Function func;
    int roots;

    cout << "Enter the number of Hermite Points you want (fom 2 to 6):" << endl;
    cin >> roots;

    cout << endl << "Integral of f(x) = " << func.integralPartitions(roots) << endl;

}
