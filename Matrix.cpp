#include "Matrix.h"
#include "Consts.h"

#include <cmath>
#include <iomanip>

void Matrix::SetMatrix(float value, int positionx, int positiony)
{
    matrix[positionx][positiony] = value;
}

float Matrix::GetValue(int positionx, int positiony)
{
    return matrix[positionx][positiony];
}

bool Matrix::Det()
{
    const double eps = 1e-12;
    float multipler;
    float sum;

    for (int i = 0; i < ROZMIAR - 1; ++i)
    {
        for (int j = i + 1; j < ROZMIAR; ++j)
        {
            if(fabsf(matrix[i][i]) < eps)
            {
                return false;
            }
            multipler = - matrix[j][i] / matrix[i][i];

            for (int k = 0; k <= ROZMIAR ; ++k)
            {
                matrix[j][k] += multipler * matrix[i][k];
            }
        }
    }

    for (int i = ROZMIAR - 1; i >= 0; --i)
    {
        sum = matrix[i][ROZMIAR];
        for (int j = ROZMIAR - 1; j >= i + 1; --j)
        {
            sum -= matrix[i][j] * X[j];
        }
        if(fabsf(matrix[i][i]) < eps)
        {
            return false;
        }

        X[i] = sum / matrix[i][i];
    }
    return true;
}

std::ostream &operator<<(std::ostream &wyjscie,  Matrix m)
{
    for (int x = 0; x < ROZMIAR; ++x)
    {
        for (int y = 0; y < ROZMIAR + 1; ++y)
        {
            wyjscie << m.GetValue(x, y) << " ";
        }
        wyjscie << std::endl;
    }


    return wyjscie;
}
