#include <QCoreApplication>

#include "genvector.h"
#include "matrix.h"

int main(int argc, char *argv[])
{
    ifstream input;
    int dim;
    Matrix m;
    genVector v;
    string line;
    int linecounter;
    double epsilon;

    input.open("Matrix.txt");
    if (input.is_open())
    {
        input >> dim;
        m.setDim(dim);
        v.setSize(dim);
        for (unsigned int i=0; i<m.getDim(); i++)
        {
            for (unsigned int j=0; j<m.getDim(); j++)
            {
                input >> m.mat.at(i).at(j);
            }
        }
        input >> epsilon;
    }

//    for (int i=0; m.getDim(); i++)
//    {
//        for (int j=0; j<m.getDim(); j++)
//        {
//            cout << m.getItem(i,j) << " ";
//        }
//        cout << endl;
//    }
//    cout << endl;

    m.powerMethod(epsilon);

}
