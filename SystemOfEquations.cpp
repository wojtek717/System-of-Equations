#include "SystemOfEquations.h"
#include "Consts.h"

SystemOfEquations::SystemOfEquations()
{

}

void SystemOfEquations::SetVectorsA(int position, Vector vector)
{
    vectorsA[position] = vector; //Assign vector to position
}

Vector SystemOfEquations::GetVectorsA(int position)
{
    return vectorsA[position]; //Return vector in coordinate
}

void SystemOfEquations::SetVectorB(Vector vector)
{
    vectorB = vector; //Assign vector
}

Vector SystemOfEquations::GetVectorB()
{
    return vectorB; //Return vector
}

void SystemOfEquations::CreateMatrixAB()
{
    Vector v;
    float value;

    for (int i = 0; i < SIZE + 1; ++i)
    {
        for (int k = 0; k < SIZE; ++k)
        {
            if(i < SIZE) //Matrix A
            {
                v = vectorsA[i];
                value = v[k];
            } else //Vector B
            {
                v = vectorB;
                value = v[k];
            }
            matrixAB.SetMatrix(value,k,i); //Assign value to transpose matrix in coordinate
        }
    }

    matrixAB.Elimination(); //Conduct elimination
    matrixAB.Solution(); //Calculate solutions
}

Matrix SystemOfEquations::GetMatrixAB()
{
    return matrixAB; //Return matrix of algebraic complements
}

Vector SystemOfEquations::Diff()
{
    Vector A[SIZE];
    Vector diff;

    for (int i = 0; i < SIZE; ++i)
    {
        for (int k = 0; k < SIZE; ++k)
        {
            A[k][i] = vectorsA[i][k]; //Transpose matrix
        }
    }

    for (int i = 0; i < SIZE; ++i)
    {
        diff[i] = A[i] * matrixAB.GetVectorX(); //diff = A*B
    }

    diff = diff - vectorB; //diff = (A*B) - X

    return diff;
}


std::ostream & operator<< (std::ostream &wyjscie, SystemOfEquations SoE)
{
    Vector tmp;

    for (int i = 0; i <= SIZE; ++i)
    {
        if(i < SIZE)
        {
            tmp = SoE.GetVectorsA(i);
            std::cout << tmp << std::endl;
        } else
        {
            tmp = SoE.GetVectorB();
            std::cout << tmp << std::endl;
        }
    }
}