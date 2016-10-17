#include "initialvalueproblem.h"

InitialValueProblem::InitialValueProblem()
{
    
}

vector<State> InitialValueProblem::solveIVP(State initial, double delta, int n)
{
    vector<State> output;
    vector<double> v;
    v.push_back(0); v.push_back(0); v.push_back(0); v.push_back(0);
    State F_value(v);


    double t=0;
    State s = initial;


    for (int i=0; i<n; i++)
    {
        t = t + delta;
        output.push_back(s);
        s.printState(i+1);
        F_value = s.F(t);
        s = s + F_value*delta;
    }

    return output;
}

vector<State> InitialValueProblem::solveBackwardIVP(State initial, double delta, int n, double epsilon)
{
    vector<State> output;

    double t=0;
    State s = initial;
    State nextState;

    for (int i=0; i<n; i++)
    {
        t = t + delta;
        output.push_back(s);
        s.printState(i+1);
        nextState = calculateNextState(s, delta, epsilon, t);
        s = s + nextState.F(t)*delta;
    }

    return output;
}

vector<State> InitialValueProblem::solveModifiedIVP(State initial, double delta, int n, double epsilon)
{
    vector<State> output;

    double t=0;
    State s = initial;
    State nextState;

    for (int i=0; i<n; i++)
    {
        t = t + delta;
        output.push_back(s);
        s.printState(i+1);
        nextState = calculateNextState(s, delta, epsilon, t);
        s = s + (nextState.F(t) + s.F(t))*(delta/2);
    }

    return output;
}

vector<State> InitialValueProblem::RungeKutta(State initial, double delta, int n, double epsilon)
{
    vector<State> output;

    double t=0;
    State s = initial;
    State nextState1;
    State nextState2;
    State nextState3;
    State nextState4;
    State nextState5;

    for (int i=0; i<n; i++)
    {
        output.push_back(s);
        s.printState(i+1);
        nextState1 = calculateNextState(s, delta*(1/5), epsilon, t+(1/5)*delta);
        nextState2 = calculateNextState(s, delta*(2/5), epsilon, t+(2/5)*delta);
        nextState3 = calculateNextState(s, delta*(3/5), epsilon, t+(3/5)*delta);
        nextState4 = calculateNextState(s, delta*(4/5), epsilon, t+(4/5)*delta);
        nextState5 = calculateNextState(s, delta*(5/5), epsilon, t+(5/5)*delta);

        s = s + (s.F(t)*(95/288) + nextState1.F(t+(1/5)*delta)*(125/96) + nextState2.F(t+(2/5)*delta)*(125/144) + nextState3.F(t+(3/5)*delta)*(125/144) + nextState4.F(t+(4/5)*delta)*(125/96) + nextState5.F(t+(5/5)*delta)*(95/288))*(delta/2);
        t = t + delta;
    }

    return output;
}

State InitialValueProblem::calculateNextState(State initial, double delta, double epsilon, double nextT)
{
    double bigDiff = 0;
    State nextS = initial;
    State lastS;

    do
    {
        lastS = nextS;
        nextS = lastS.F(nextT)*delta;
        nextS = nextS + initial;

        bigDiff = nextS.distanceTo(lastS);
    }
    while (bigDiff>epsilon);
    return nextS;
}

