#ifndef SYSTEMOFEQUATIONS_SYSTEMOFEQUATIONS_H
#define SYSTEMOFEQUATIONS_SYSTEMOFEQUATIONS_H


#include "Vector.h"
#include "Consts.h"

class SystemOfEquations
{
private:
    Vector vectorsA[ROZMIAR]; //Jak zamiast tego bedzie *vectorsA to nie dziala :|
    Vector vectorB;
    Vector vectorX;

public:
    SystemOfEquations();

    void SetVectorsA(int position, Vector vector);
    Vector GetVectorsA(int position);

    void SetVectorB(Vector vector);
    Vector GetVectorB();

    void SetVectorX(Vector vector);
    Vector GetVectorX();
};


#endif //SYSTEMOFEQUATIONS_SYSTEMOFEQUATIONS_H
