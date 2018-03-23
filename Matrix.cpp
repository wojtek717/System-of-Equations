#include "Matrix.h"
#include "Consts.h"

Matrix::Matrix(Vector *vectorsA, Vector vectorB)
{
    vectors = new Vector[ROZMIAR + 1];

    for (int i = 0; i < ROZMIAR; ++i)
    {
        vectors[i] = vectorsA[i];
    }

    vectors[ROZMIAR] = vectorB;
}
