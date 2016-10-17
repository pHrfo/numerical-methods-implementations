#ifndef INITIALVALUEPROBLEM_H
#define INITIALVALUEPROBLEM_H

#include "state.h"

class InitialValueProblem
{

public:
    InitialValueProblem();

    //Metodo que soluciona o problema de valor inicial
    vector<State> solveIVP(State initial, double delta, int n);
    vector<State> solveBackwardIVP(State initial, double delta, int n, double epsilon);
    vector<State> solveModifiedIVP(State initial, double delta, int n, double epsilon);
    vector<State> RungeKutta(State initial, double delta, int n, double epsilon);

    //Metodo iterativo para solução de equação
    State calculateNextState(State initial, double delta, double epsilon, double nextT);

};

#endif // INITIALVALUEPROBLEM_H
