#ifndef SYSTEMOFEQUATIONS_MATRIX_H
#define SYSTEMOFEQUATIONS_MATRIX_H


#include "Vector.h"

class Matrix
{
private:
    float matrix[ROZMIAR][ROZMIAR];

public:
    void SetMatrix(float value, int positionx, int positiony);
};


#endif //SYSTEMOFEQUATIONS_MATRIX_H
