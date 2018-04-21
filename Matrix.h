#ifndef SYSTEMOFEQUATIONS_MATRIX_H
#define SYSTEMOFEQUATIONS_MATRIX_H


#include "Vector.h"

template<typename T>
class Matrix
{
private:
    T matrix[SIZE][SIZE + 1];
    Vector<T> X;

public:
    /* Set value of matrix in coordinate XY
     * [IN] value - value to set
     * [IN] positionx - coordinate X of matrix
     * [IN] positiony - coordinate Y of matrix */
    void SetMatrix(T value, int positionx, int positiony);

    /* Get value of matrix in coordinate XY
     * [IN] positionx - coordinate X of matrix
     * [IN] positiony - coordinate Y of matrix
     * [RETURN](float) - value of matrix in coordinate XY*/
    T GetValue(int positionx, int positiony);

    /* Function returns solutions vector
     * [RETURN](Vector) - vector with solutions */
    Vector<T> GetVectorX();


    /* Function conducts Gaussian elimination
     * [RETURN](bool) - was elimination conducted correctly */
    bool Elimination();

    /* Function calculate solutions of SoE
     * [RETURN](bool) - was solutions calculated correctly */
    bool Solution();
};

/* Overload for operators */
template<typename T>
std::ostream & operator<< (std::ostream &wyjscie, Matrix<T> m);

#endif //SYSTEMOFEQUATIONS_MATRIX_H
