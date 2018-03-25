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

