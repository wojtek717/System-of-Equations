#include "SystemOfEquations.h"
#include "Consts.h"

SystemOfEquations::SystemOfEquations()
{
    // A tutaj bedzie to vectorsA = new Vector[ROZMIAR];
}

void SystemOfEquations::SetVectorsA(int position, Vector vector)
{
    vectorsA[position] = vector;
}

Vector SystemOfEquations::GetVectorsA(int position)
{
    return vectorsA[position];
}

void SystemOfEquations::SetVectorB(Vector vector)
{
    vectorB = vector;
}

Vector SystemOfEquations::GetVectorB()
{
    return vectorB;
}

void SystemOfEquations::SetVectorX(Vector vector)
{
    vectorX = vector;
}

Vector SystemOfEquations::GetVectorX()
{
    return vectorX;
}

void SystemOfEquations::CreateMatrixAB()
{
    Vector v;
    float value;

    for (int i = 0; i < ROZMIAR + 1; ++i)
    {
        for (int k = 0; k < ROZMIAR; ++k)
        {
            if(i < ROZMIAR)
            {
                v = vectorsA[i];
                value = v[k];
            } else
            {
                v = vectorB;
                value = v[k];
            }

            matrixAB.SetMatrix(value,k,i);
        }
    }

    matrixAB.Det();
}

Matrix SystemOfEquations::GetMatrixAB()
{
    return matrixAB;
}


std::ostream & operator<< (std::ostream &wyjscie, SystemOfEquations SoE)
{
    Vector tmp;

    for (int i = 0; i <= ROZMIAR; ++i)
    {
        if(i < ROZMIAR)
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