#ifndef SYSTEMOFEQUATIONS_SYSTEMOFEQUATIONS_H
#define SYSTEMOFEQUATIONS_SYSTEMOFEQUATIONS_H


#include "Vector.h"
#include "Consts.h"
#include "Matrix.h"

template<typename T>
class SystemOfEquations
{
private:
    Vector<T> vectorsA[SIZE];
    Vector<T> vectorB;
    Matrix<T> matrixAB;

public:

    /* Set vector for matrix A
     * [IN](int) position - coordinate of array
     * [IN](Vector) vector - Vector to set */
    void SetVectorsA(int position, Vector<T> vector);

    /* Get vector in coordinate
     * [IN](int) position - coordinate of array
     * [RETURN](Vector) - Vector from array in coordinate*/
    Vector<T> GetVectorsA(int position);


    /* Set vector B
     * [IN](Vector) - Vector to set */
    void SetVectorB(Vector<T> vector);

    /* Get vector B
     * [RETURN](Vector) - vector B */
    Vector<T> GetVectorB();


    /* Function creates matrix of algebraic complements */
    void CreateMatrixAB();

    /* [RETURN](Matrix) - Function returns matrix of algebraic complements */
    Matrix<T> GetMatrixAB();

    /* Function calculate calculations error
     * [Return](Vector) - vector of calculations error */
    Vector<T> Diff();
};

/* Overload for operatrs */
template<typename T>
std::ostream & operator<< (std::ostream &wyjscie, SystemOfEquations<T> SoE);



#endif //SYSTEMOFEQUATIONS_SYSTEMOFEQUATIONS_H
