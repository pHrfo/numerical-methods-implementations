#include "genvector.h"

genVector::genVector()
{

}

genVector::genVector(int tam)
{
    size = tam;
    for (int i=0; i<size; i++)
    {
        v.push_back(0);
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
