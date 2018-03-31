#include "Matrix.h"
#include "Consts.h"

void Matrix::SetMatrix(float value, int positionx, int positiony)
{
    matrix[positionx][positiony] = value;
}

float Matrix::GetValue(int positionx, int positiony)
{
    return matrix[positionx][positiony];
}

std::ostream &operator<<(std::ostream &wyjscie,  Matrix m)
{
    for (int x = 0; x < ROZMIAR; ++x)
    {
        for (int y = 0; y < ROZMIAR; ++y)
        {
            wyjscie << m.GetValue(x, y) << " ";
        }
        wyjscie << std::endl;
    }


    return wyjscie;
}
