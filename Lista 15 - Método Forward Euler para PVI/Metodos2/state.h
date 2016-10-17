#ifndef STATE_H
#define STATE_H

#include "general.h"


class State
{
private:
    /*
     * Vetor que segue o formato:
     *
     *         (  x1  )
     * value = (  x2  )
     *         (  v1  )
     *         (  v2  )
     */
    vector<double> value;
public:
    //Construtores
    State();
    State(vector<double> value);

    //Metodo que altera o valor de uma posicao do estado
    void changeState(int pos, double val);

    //Metodo que retorna uma posicao do estado
    double getState(int pos);

    //Metodo que retorna o F(S,t)
    State F(double t);

    double calculateForce(double t);

    double distanceTo(State s);

    void printState(int pos);

    State operator +(State);
    State operator *(double);
    void operator =(State);

};

#endif // STATE_H
