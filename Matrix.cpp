#include "Matrix.h"
#include "Consts.h"

#include <cmath>
#include <iomanip>

void Matrix::SetMatrix(float value, int positionx, int positiony)
{
    matrix[positionx][positiony] = value; //Assign value to coordinate
}

float Matrix::GetValue(int positionx, int positiony)
{
    return matrix[positionx][positiony]; //Return value in coordinate
}

bool Matrix::Elimination()
{
    float multipler;

    for (int i = 0; i < SIZE - 1; ++i)
    {
        for (int j = i + 1; j < SIZE; ++j)
        {
            if(fabsf(matrix[i][i]) < EPS) //Absolute value on diagonal can not be 0
            {
                std::cout << "Division by 0!";
                return false;
            }
            multipler = - matrix[j][i] / matrix[i][i]; //Calculate multipler

            for (int k = 0; k <= SIZE ; ++k)
            {
                matrix[j][k] += multipler * matrix[i][k]; //Multiply all values in col
            }
        }
    }

    return true;
}

bool Matrix::Solution()
{
    float sum;

    for (int i = SIZE - 1; i >= 0; --i)
    {
        sum = matrix[i][SIZE]; //Define initial value of sum

        for (int j = SIZE - 1; j >= i + 1; --j)
        {
            sum -= matrix[i][j] * X[j]; //Calculate sum
        }
        if(fabsf(matrix[i][i]) < EPS) //Absolute value on diagonal can not be 0
        {
            std::cout << "Division by 0!";
            return false;
        }

        X[i] = sum / matrix[i][i]; //Calculate solution
    }
    return true;
}

Vector Matrix::GetVectorX()
{
    return X;
}

std::ostream &operator<<(std::ostream &wyjscie,  Matrix m)
{
    for (int x = 0; x < SIZE; ++x)
    {
        for (int y = 0; y < SIZE + 1; ++y)
        {
            wyjscie << m.GetValue(x, y) << " ";
        }
        wyjscie << std::endl;
    }

    return wyjscie;
}