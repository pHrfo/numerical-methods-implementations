#ifndef MATRIX_H
#define MATRIX_H

#include "general.h"
#include "genvector.h"

class Matrix
{
protected:

    int dim;

public:
    vector< vector< double> > mat;
    vector< vector< double> > inverse;
    Matrix(int); //this constructor creates matrix in format int x int
    Matrix();
    ~Matrix();

    void identity();

    //getters and setters
    void setItem(int i,int j,double value);
    double getItem(int i,int j);
    int getDim();
    string getDimS();
    void setDim(int Dim);
    vector< vector< double> > getmat();
    void calcInverse();
    void sumLines(int, int, double);
    void divideLine(int,double);

    //methods
    void powerMethod(double);

    //operators
    Matrix operator*  (Matrix); //concatenate matrix
    genVector operator*(genVector);
    void operator= (Matrix);
    //operators, apply matrix in a vector
    vector<double> operator* (vector<double>);
    void permuteRow(int, int);
    void multAddRow(int,int,double);

};
#endif // MATRIX_H
