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

void SystemOfEquations::CreateMatricies()
{
    Matrix m;
    Vector v;
    float value;

    for (int i = 0; i < ROZMIAR+1; ++i)
    {
        for (int x = 0; x < ROZMIAR; ++x) 
        {
            for (int y = 0; y < ROZMIAR; ++y)
            {
                v = vectorsA[x];
                value = v[y];
                m.SetMatrix(value, x, y);
            }    
        }

        if(i > 0)
        {
            for (int y = 0; y < ROZMIAR; ++y)
            {
                v = vectorB;
                value = v[y];
                m.SetMatrix(value, i-1, y);
            }
        }

        matrices[i] = m;
    }
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