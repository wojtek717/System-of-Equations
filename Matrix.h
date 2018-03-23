#ifndef SYSTEMOFEQUATIONS_MATRIX_H
#define SYSTEMOFEQUATIONS_MATRIX_H


#include "Vector.h"

class Matrix
{
private:
    Vector *vectors;

public:
    Matrix(Vector *vectorsA, Vector vectorB);
    Vector GetVector(int position);
};


#endif //SYSTEMOFEQUATIONS_MATRIX_H
