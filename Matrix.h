#ifndef SYSTEMOFEQUATIONS_MATRIX_H
#define SYSTEMOFEQUATIONS_MATRIX_H


#include "Vector.h"

class Matrix
{
private:
    Vector *vectors;

public:
    Matrix();
    void SetVector(int position, Vector vector);
    Vector GetVector(int position);
};


#endif //SYSTEMOFEQUATIONS_MATRIX_H
