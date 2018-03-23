//
// Created by wojci on 23.03.2018.
//

#include "SystemOfEquations.h"
#include "Consts.h"

SystemOfEquations::SystemOfEquations()
{
    vectorsA = new Vector[ROZMIAR];
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

Vector *SystemOfEquations::GetA() //TO NIE DZIALA
{
    return vectorsA;
}

