#include "state.h"

State::State()
{
    value.push_back(0);
    value.push_back(0);
    value.push_back(0);
    value.push_back(0);
}

State::State(vector<double> value)
{
    this->value = value;
}

void State::changeState(int pos, double val)
{
    value[pos] = val;
}

double State::getState(int pos)
{
    return value.at(pos);
}

void State::printState(int pos)
{
    cout << "Estado " << pos << ":" << endl;
    for(int i=0; i<value.size(); i++)
    {
        cout << getState(i) << ' ';
    }
    cout << endl;
}

State State::F(double t)
{
    State output = *this;

    double aceleracao1;
    double aceleracao2;
    double x1 = this->getState(0);
    double x2 = this->getState(1);
    double v1 = this->getState(2);
    double v2 = this->getState(3);

    //Constant values:
    double c1 = 50; double c2 = 30;
    double k1 = 2; double k2 = 5;
    double M1 = 30; double M2 = 23;

    aceleracao1 = (1/M1)*(k2*(x2 - x1) + c2*(v2 - v1) - k1*x1 - c1*v1 + calculateForce(t));
    aceleracao2 = (1/M2)*((-k2)*(x2 - x1) - c2*(v2 - v1) + calculateForce(t));
    double val = 2*(0.1 - x1)*(0.4 - x1);
    output.changeState(0, val);
    output.changeState(1, 0);
    output.changeState(2, 0);
    output.changeState(3, 0);

    return output;
}

double State::distanceTo(State s)
{
    double distance = 0;
    for (int i=0; i<4; i++)
        distance = max(distance, this->getState(i) - s.getState(i));
    return distance;
}

double State::calculateForce(double t)
{
    return 4*cos(t);
}

State State::operator +(State s)
{
    State output;

    for (int i=0; i<4; i++)
    {
        output.changeState(i, this->getState(i) + s.getState(i));
    }

    return output;
}

State State::operator *(double val)
{
    State output;

    for (int i=0; i<4; i++)
    {
        output.changeState(i, this->getState(i) * val);
    }

    return output;
}

void State::operator =(State s)
{
    this->changeState(0,s.getState(0));
    this->changeState(1,s.getState(1));
    this->changeState(2,s.getState(2));
    this->changeState(3,s.getState(3));
}
