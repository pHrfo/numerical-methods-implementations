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

Matrix Matrix::operator * (Matrix m)
{
    int size = this->getDim();
    double sum;
    Matrix output(size);

    for (int i=0; i<size; i++)
    {
        for (int j=0; j<size; j++)
        {
            sum = 0;
            for (int k=0; k<size; k++)
                sum = sum + this->getItem(i,k)*m.getItem(k,j);
            output.setItem(i,j,sum);
        }
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

    output.open("Eigenvalues.txt");
    for (int i=0; i<dim; i++)
    {
        eigenvector.v[i] = 1;
    }

    while(fabs((current_lambda - last_lambda)/current_lambda) > epsilon)
    {
        eigenvector = (*this) * eigenvector;
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

Matrix Matrix::transpose()
{
    Matrix transpost(getDim());
    for (int i=0; i<getDim(); i++)
        for (int j=i; j<getDim(); j++)
        {
            transpost.setItem(i,j,getItem(j,i));
            transpost.setItem(j,i,getItem(i,j));
        }
    return transpost;
}

void Matrix::householder()
{
    double norm;
    double size = this->getDim();
    genVector columnAux;
    genVector e;
    Matrix P(getDim());
    Matrix Identity(size);
    Matrix A(size);
    Matrix H(size);
    ofstream output;

    for (int i=0; i<size; i++)
        for (int j=0; j<size; j++)
            A.setItem(i,j,getItem(i,j));

    output.open("householder.txt");
    output << "Input Matrix: " << endl;
    for (int k=0; k<size; k++)
    {
        for (int j=0; j<size; j++)
        {
            output << A.getItem(k,j) << " ";
        }
        output << endl;
    }
    output << endl;

    for (int i=0; i<size-2; i++)
    {
        columnAux = A.getColumn(i,i+1);
        norm = columnAux.norm();
        if (columnAux.v.at(0) >= 0)
            columnAux.v.at(0) = columnAux.v.at(0) + norm;
        else
            columnAux.v.at(0) = columnAux.v.at(0) - norm;

        e = columnAux.complete(getDim());

        e.normalize();

        P = e.multiplyByVec(e);
        P = Identity - (P*2);
        H = H*P;
        A = P*(A*P);

    }
    output << "Tridiagonal Matrix:" << endl;
    for (int k=0; k<size; k++)
    {
        for (int j=0; j<size; j++)
        {
            if (fabs(A.getItem(k,j)) < 0.0001)
                A.setItem(k,j,0);
            output << A.getItem(k,j) << " ";
        }
        output << endl;
    }
    output << endl << "Householder Matrix: " << endl;


    for (int k=0; k<size; k++)
    {
        for (int j=0; j<size; j++)
        {
            if (fabs(H.getItem(k,j)) < 0.0001)
                H.setItem(k,j,0);
            output << H.getItem(k,j) << " ";
        }
        output << endl;
    }
}

genVector Matrix::getColumn(int i)
{
    genVector output;

    for (int j=0; j<getDim(); j++)
    {
        output.v.push_back(getItem(j,i));
    }

    return output;
}

genVector Matrix::getColumn(int i, int pos)
{
    vector<double> vec;
    genVector output;

    for (int j=pos; j<getDim(); j++)
    {
       vec.push_back(getItem(j,i));
    }

    output.v = vec;
    output.size = vec.size();

    return output;
}

Matrix Matrix::operator -(Matrix m)
{
    Matrix output(getDim());
    for (int i=0; i<getDim(); i++)
        for (int j=0; j<getDim(); j++)
            output.setItem(i,j,this->getItem(i,j) - m.getItem(i,j));
    return output;
}

Matrix Matrix::operator *(double val)
{
    Matrix output(getDim());
    for (int i=0; i<getDim(); i++)
        for (int j=0; j<getDim(); j++)
            output.setItem(i,j,this->getItem(i,j)*val);
    return output;
}
