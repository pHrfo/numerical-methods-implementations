#include "matrix.h"

Matrix::Matrix()
{

}

Matrix::Matrix(int n) //creates a n x n, empy, matrix
{
    vector<double> line(n,0); //creates a line with zeroes values

    for(int i = 0; i<n ; i++)
        mat.push_back(line);
    dim = n;
    identity();
}

Matrix::~Matrix()
{
    mat.clear();
    dim = 0;
}

void Matrix::setItem(int i, int j, double value)
{
    mat[i][j] = value;
}

double Matrix::getItem(int i, int j)
{
    return mat[i][j];
}

int Matrix::getDim()
{
    return dim;
}

void Matrix::setDim(int Dim)
{
    this->mat.clear();
    this->dim = Dim;
    vector<double> line(Dim,0);
    for(int i = 0; i<Dim ; i++)
        mat.push_back(line);

}

string Matrix::getDimS()
{
    ostringstream strs;
    strs << dim;
    return strs.str();
}

vector< vector< double> > Matrix::getmat()
{
    return mat;
}

void Matrix::identity()
{
    for(int i=0; i<dim; i++)
    {
        for (int j=0; j<dim; j++)
        {
            if(i==j)
                mat[i][j] = 1;
            else
                mat[i][j] = 0;
        }
    }

}

vector<double> Matrix::operator * (vector<double> d)
{
    vector<double> output;
    double sum;

    for(int i=0; i<dim; i++)
    {
        sum = 0;
        for(int j=0; j<dim; j++)
        {
            sum = sum + mat[i][j] * d[j];
        }
        output.push_back(sum);
    }

    return output;
}

void Matrix::operator = (Matrix matrix)
{
    for(int i=0; i<dim; i++)
        for(int j=0; j<dim; j++)
            mat[i][j] = matrix.getItem(i,j);
}

void Matrix::permuteRow(int a, int b)
{
    vector<double> aux;
    if((dim>1)&&(a!=b))
    {
        aux = mat[a];
        mat[a] =  mat[b];
        mat[b] = aux;
    }
}

void Matrix::multAddRow(int a, int b, double mult)
{
    if((dim>1)&&(a!=b))
    {
        for(int i=0; i<dim;i++)
        {
            mat[b][i] = mat[b][i] + mat[a][i]*mult;
        }
    }

}

genVector Matrix::operator *(genVector v)
{
    genVector out(v.size);
    if (this->getDim()==v.size)
    {
        double sum;
        for (int i=0; i<v.size; i++)
        {
            sum = 0;
            for (int j=0; j<v.size; j++)
            {
                sum = sum + this->getmat().at(i).at(j) * v.v[j];
            }
            out.v[i] = sum;
        }
    }

    return out;
}

void Matrix::powerMethod(double epsilon)
{
    ofstream output;
    double current_lambda = 0.1;
    double last_lambda = 1000;
    genVector eigenvector(dim);
    this->calcInverse();
    Matrix inv(this->getDim());

    inv.mat = this->inverse;

    output.open("Eigenvalues.txt");
    for (int i=0; i<dim; i++)
    {
        eigenvector.v[i] = 1;
    }

    while(fabs((current_lambda - last_lambda)/current_lambda) > epsilon)
    {
        eigenvector = (inv) * eigenvector;
        eigenvector.normalize();
        last_lambda = current_lambda;
        current_lambda = eigenvector * (*this * eigenvector);
    }

    output << "Dominant eigenvalue: " << current_lambda << endl << endl;
    output << "Corresponding eigenvector:" << endl << endl;
    for (int i=0; i<eigenvector.size; i++)
    {
        output << eigenvector.v[i] << endl;
    }

}

void Matrix::calcInverse()
{
    Matrix aux(this->getDim());
    aux.mat = this->mat;
    Matrix auxInverse(this->getDim());

    double pivot;
    double multiplier;

    for (int i=0; i<this->getDim(); i++)
    {
        for (int j=0; j<this->getDim(); j++)
        {
            if (i != j)
            {
                pivot = aux.getItem(i,i);
                multiplier = (-1)*aux.getItem(j,i)/pivot;
                aux.sumLines(i,j,multiplier);
                auxInverse.sumLines(i,j,multiplier);
            }

            if(fabs(aux.getItem(j,i)) < 0.0001)
            {
                aux.setItem(j,i,0);
            }

            if(fabs(auxInverse.getItem(j,i)) < 0.0001)
            {
                auxInverse.setItem(j,i,0);
            }
        }
    }

    for (int i=0; i<this->getDim(); i++)
    {
        auxInverse.divideLine(i,aux.getItem(i,i));
        aux.setItem(i,i,1);
        for (int j=0; j<this->getDim(); j++)
        {
            if (fabs(auxInverse.getItem(i,j)) < 0.0001)
            {
                auxInverse.setItem(i,j,0);
            }
        }
    }

    this->inverse = auxInverse.mat;
}

void Matrix::sumLines(int i, int j, double mult)
{
    double newElem;
    for (int p=0; p<this->getDim(); p++)
    {
        newElem = this->getItem(j,p) + mult*this->getItem(i,p);
        this->setItem(j,p,newElem);
    }
}

void Matrix::divideLine(int i, double divider)
{
    for (int j=0; j<this->getDim(); j++)
    {
        this->setItem(i,j,this->getItem(i,j)/divider);
    }
}
