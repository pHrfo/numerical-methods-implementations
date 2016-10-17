#ifndef GENVECTOR_H
#define GENVECTOR_H

#include "general.h"

class genVector
{


public:
    vector <double> v;
    int size;
    genVector(int);
    genVector();
    void normalize();
    void setSize(int);

    double operator*  (genVector);
};

#endif // GENVECTOR_H
