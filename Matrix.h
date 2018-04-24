#ifndef SYSTEMOFEQUATIONS_MATRIX_H
#define SYSTEMOFEQUATIONS_MATRIX_H


#include <math.h>
#include <string>
#include "Vector.h"
#include "Complex.h"

template<typename T>
class Matrix
{
private:
    T matrix[SIZE][SIZE + 1];
    Vector<T> X;

public:
    Matrix();

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

template<typename T>
void Matrix<T>::SetMatrix(T value, int positionx, int positiony)
{
    matrix[positionx][positiony] = value; //Assign value to coordinate
}

template<typename T>
T Matrix<T>::GetValue(int positionx, int positiony)
{
    return matrix[positionx][positiony]; //Return value in coordinate
}

template<typename T>
bool Matrix<T>::Elimination()
{
    T multipler;
    
    for (int i = 0; i < SIZE - 1; ++i)
    {
        for (int j = i + 1; j < SIZE; ++j)
        {
            if(abs(matrix[i][i]) < EPS) //Absolute value on diagonal can not be 0
            {
                std::cout << "Division by 0!";
                return false;
            }
            multipler = matrix[j][i] / matrix[i][i] * -1; //Calculate multipler
            
            for (int k = 0; k <= SIZE ; ++k)
            {
                matrix[j][k] += multipler * matrix[i][k]; //Multiply all values in col
            }
        }
    }
    return true;
}

template<typename T>
bool Matrix<T>::Solution()
{
    T sum;
    
    for (int i = SIZE - 1; i >= 0; --i)
    {
        sum = matrix[i][SIZE]; //Define initial value of sum
        
        for (int j = SIZE - 1; j >= i + 1; --j)
        {
            sum -= matrix[i][j] * X[j]; //Calculate sum
        }
        if(abs(matrix[i][i]) < EPS) //Absolute value on diagonal can not be 0
        {
            std::cout << "Division by 0!";
            return false;
        }
        
        X[i] = sum / matrix[i][i]; //Calculate solution
    }
    return true;
}

template<typename T>
Vector<T> Matrix<T>::GetVectorX()
{
    return X;
}

template<typename T>
Matrix<T>::Matrix() {

}

template<typename T>
std::ostream &operator<<(std::ostream &wyjscie,  Matrix<T> m)
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

#endif //SYSTEMOFEQUATIONS_MATRIX_H
