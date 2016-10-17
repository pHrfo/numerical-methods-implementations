#include "genvector.h"
#include "matrix.h"

genVector::genVector()
{

}

genVector::genVector(int tam)
{
    size = tam;
    for (int i=0; i<size; i++)
    {
        v.push_back(1);
    }
}

void genVector::normalize()
{
    double sum = 0;
    for (int i=0; i<size; i++)
    {
        sum = sum + v[i]*v[i];
    }
    sum = sqrt(sum);

    for (int i=0; i<size; i++)
    {
        v[i] = v[i]/sum;
    }
}

double genVector::operator *(genVector v)
{
    double aux;
    if (this->size==v.size)
    {
        for (int i=0; i<v.size; i++)
        {
            aux = aux + this->v[i]*v.v[i];
        }
    }

    return aux;
}

void genVector::setSize(int newSize)
{
    this->v.clear();
    this->size = newSize;
    for (int i=0; i<size; i++)
    {
        v.push_back(0);
    }
}

genVector genVector::complete(int size)
{
    genVector output;
    int diff = size - v.size();
    vector<double> aux;
    for (int i=0; i<diff; i++)
        aux.push_back(0);
    for (unsigned int i=0; i<v.size(); i++)
        aux.push_back(v.at(i));

    output.v = aux;
    output.size = aux.size();

    return output;
}

double genVector::norm()
{
    double sum = 0;
    for (int i=0; i<size; i++)
    {
        sum = sum + pow(v[i],2);
    }
    sum = sqrt(sum);

    return sum;
}

Matrix genVector::multiplyByVec(genVector v2)
{
    Matrix m(size);

    for (int i=0; i<size; i++)
    {
        for (int j=0; j<size; j++)
        {
            m.setItem(i,j,this->v.at(i)*v2.v.at(j));
        }
    }

    return m;
}

void genVector::addItem(double val)
{
    v.push_back(val);
    size = size + 1;
}

void genVector::operator =(genVector v2)
{
    vector<double> aux;
    v = aux;
    size = 0;
    for (int i=0; i<v2.size; i++)
    {
        this->addItem(v2.v.at(i));
    }
}
