#ifndef SYSTEMOFEQUATIONS_MATRIX_H
#define SYSTEMOFEQUATIONS_MATRIX_H


#include "Vector.h"

class Matrix
{
private:
    float matrix[SIZE][SIZE + 1];
    Vector X;

public:
    /* Set value of matrix in coordinate XY
     * [IN] value - value to set
     * [IN] positionx - coordinate X of matrix
     * [IN] positiony - coordinate Y of matrix */
    void SetMatrix(float value, int positionx, int positiony);

    /* Get value of matrix in coordinate XY
     * [IN] positionx - coordinate X of matrix
     * [IN] positiony - coordinate Y of matrix
     * [RETURN](float) - value of matrix in coordinate XY*/
    float GetValue(int positionx, int positiony);

    /* Function returns solutions vector
     * [RETURN](Vector) - vector with solutions */
    Vector GetVectorX();


    /* Function conducts Gaussian elimination
     * [RETURN](bool) - was elimination conducted correctly */
    bool Elimination();

    /* Function calculate solutions of SoE
     * [RETURN](bool) - was solutions calculated correctly */
    bool Solution();
};

/* Overload for operators */
std::ostream & operator<< (std::ostream &wyjscie, Matrix m);

#endif //SYSTEMOFEQUATIONS_MATRIX_H
