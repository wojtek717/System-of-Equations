#ifndef SYSTEMOFEQUATIONS_MATRIX_H
#define SYSTEMOFEQUATIONS_MATRIX_H


#include "Vector.h"

class Matrix
{
private:
    float matrix[ROZMIAR][ROZMIAR + 1];


public:
    float X[ROZMIAR];

    void SetMatrix(float value, int positionx, int positiony);
    float GetValue(int positionx, int positiony);

    bool Det();
};

std::ostream & operator<< (std::ostream &wyjscie, Matrix m);

#endif //SYSTEMOFEQUATIONS_MATRIX_H
