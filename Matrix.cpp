#include "Matrix.h"
#include "Consts.h"

Matrix::Matrix()
{
    vectors = new Vector[ROZMIAR + 1];
}

Vector Matrix::GetVector(int position)
{
    return vectors[position];
}

void Matrix::SetVector(int position, Vector vector)
{
    vectors[position] = vector;
}
