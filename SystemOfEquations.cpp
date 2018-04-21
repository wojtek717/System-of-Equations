#include "SystemOfEquations.h"
#include "Consts.h"

template<typename T>
void SystemOfEquations<T>::SetVectorsA(int position, Vector<T> vector)
{
    vectorsA[position] = vector; //Assign vector to position
}

template<typename T>
Vector<T> SystemOfEquations<T>::GetVectorsA(int position)
{
    return vectorsA[position]; //Return vector in coordinate
}

template<typename T>
void SystemOfEquations<T>::SetVectorB(Vector<T> vector)
{
    vectorB = vector; //Assign vector
}

template<typename T>
Vector<T> SystemOfEquations<T>::GetVectorB()
{
    return vectorB; //Return vector
}

template<typename T>
void SystemOfEquations<T>::CreateMatrixAB()
{
    Vector<T> v;
    T value;

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

template<typename T>
Matrix<T> SystemOfEquations<T>::GetMatrixAB()
{
    return matrixAB; //Return matrix of algebraic complements
}

template<typename T>
Vector<T> SystemOfEquations<T>::Diff()
{
    Vector<T> A[SIZE];
    Vector<T> diff;

    for (int i = 0; i < SIZE; ++i)
    {
        for (int k = 0; k < SIZE; ++k)
        {
            A[k][i] = vectorsA[i][k]; //Transpose matrix
        }
    }

    for (int i = 0; i < SIZE; ++i)
    {
        diff[i] = A[i] * matrixAB.GetVectorX(); //diff = A*X
    }

    diff = diff - vectorB; //diff = (A*X) - B

    return diff;
}

template<typename T>
std::ostream & operator<< (std::ostream &wyjscie, SystemOfEquations<T> SoE)
{
    Vector<T> tmp;

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