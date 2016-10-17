#include <QCoreApplication>
#include "initialvalueproblem.h"

int main(int argc, char *argv[])
{
    InitialValueProblem ivp;
    vector<double> v;

    v.push_back(0);
    v.push_back(0);
    v.push_back(0);
    v.push_back(0);

    State initial(v);

    vector<State> output;
    output = ivp.RungeKutta(initial, 0.001, 100, 0.001);
}
