#ifndef SYSTEMOFEQUATIONS_SYSTEMOFEQUATIONS_H
#define SYSTEMOFEQUATIONS_SYSTEMOFEQUATIONS_H


#include "Vector.h"
#include "Consts.h"
#include "Matrix.h"

class SystemOfEquations
{
private:
    Vector vectorsA[SIZE];
    Vector vectorB;
    Matrix matrixAB;

public:
    SystemOfEquations();

    /* Set vector for matrix A
     * [IN](int) position - coordinate of array
     * [IN](Vector) vector - Vector to set */
    void SetVectorsA(int position, Vector vector);

    /* Get vector in coordinate
     * [IN](int) position - coordinate of array
     * [RETURN](Vector) - Vector from array in coordinate*/
    Vector GetVectorsA(int position);


    /* Set vector B
     * [IN](Vector) - Vector to set */
    void SetVectorB(Vector vector);

    /* Get vector B
     * [RETURN](Vector) - vector B */
    Vector GetVectorB();


    /* Function creates matrix of algebraic complements */
    void CreateMatrixAB();

    /* [RETURN](Matrix) - Function returns matrix of algebraic complements */
    Matrix GetMatrixAB();

    /* Function calculate calculations error
     * [Return](Vector) - vector of calculations error */
    Vector Diff();
};

/* Overload for operatrs */
std::ostream & operator<< (std::ostream &wyjscie, SystemOfEquations SoE);



#endif //SYSTEMOFEQUATIONS_SYSTEMOFEQUATIONS_H
