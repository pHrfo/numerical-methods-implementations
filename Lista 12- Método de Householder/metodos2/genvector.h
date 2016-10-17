#ifndef GENVECTOR_H
#define GENVECTOR_H

#include "general.h"

class Matrix;

class genVector
{


public:
    vector <double> v;
    int size;
    genVector(int);
    genVector();
    void normalize();
    void setSize(int);
    genVector complete(int);
    double norm();
    void addItem(double);


    double operator*  (genVector);
    void operator=  (genVector);
    Matrix multiplyByVec (genVector);
};

#endif // GENVECTOR_H
