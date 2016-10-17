#include <QCoreApplication>

#include "genvector.h"
#include "matrix.h"

int main()
{
    ifstream input;
    int dim;
    Matrix m;
    genVector v;
    double epsilon;

    input.open("Matrix.txt");
    if (input.is_open())
    {
        input >> dim;
        m.setDim(dim);
        v.setSize(dim);
        for (int i=0; i<m.getDim(); i++)
        {
            for (int j=0; j<m.getDim(); j++)
            {
                input >> m.mat.at(i).at(j);
            }
        }
        input >> epsilon;
    }

    m.householder();

}
