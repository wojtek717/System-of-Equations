#ifndef SYSTEMOFEQUATIONS_SYSTEMOFEQUATIONS_H
#define SYSTEMOFEQUATIONS_SYSTEMOFEQUATIONS_H


#include "Vector.h"
#include "Consts.h"
#include "Matrix.h"
#include "Complex.h"
#include <fstream>

template<typename T>
class SystemOfEquations
{
    Vector<T> vectorsA[SIZE];
    Vector<T> vectorB;
    Matrix<T> matrixAB;

public:
  explicit SystemOfEquations(char *filename);

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


template<typename T>
void SystemOfEquations<T>::SetVectorsA(int position, Vector<T> vector)
{
    vectorsA[position] = vector; //Assign vector to position
}

template<typename T>
Vector<T> SystemOfEquations<T>::GetVectorsA(int position)
{
    return vectorsA[position]; //Return vector in coordinate
}

template<typename T>
void SystemOfEquations<T>::SetVectorB(Vector<T> vector)
{
    vectorB = vector; //Assign vector
}

template<typename T>
Vector<T> SystemOfEquations<T>::GetVectorB()
{
    return vectorB; //Return vector
}

template<typename T>
void SystemOfEquations<T>::CreateMatrixAB()
{
    Vector<T> v;
    T value;
    
    for (int i = 0; i < SIZE + 1; ++i)
    {
        for (int k = 0; k < SIZE; ++k)
        {
            if(i < SIZE) //Matrix A
            {
                v = vectorsA[i];
                value = v[k];
            } else //Vector B
            {
                v = vectorB;
                value = v[k];
            }
            matrixAB.SetMatrix(value,k,i); //Assign value to transpose matrix in coordinate
        }
    }
    
    matrixAB.Elimination(); //Conduct elimination
    matrixAB.Solution(); //Calculate solutions
}

template<typename T>
Matrix<T> SystemOfEquations<T>::GetMatrixAB()
{
    return matrixAB; //Return matrix of algebraic complements
}

template<typename T>
Vector<T> SystemOfEquations<T>::Diff()
{
    Vector<T> A[SIZE];
    Vector<T> diff;
    
    for (int i = 0; i < SIZE; ++i)
    {
        for (int k = 0; k < SIZE; ++k)
        {
            A[k][i] = vectorsA[i][k]; //Transpose matrix
        }
    }
    
    for (int i = 0; i < SIZE; ++i)
    {
        diff[i] = A[i] * matrixAB.GetVectorX(); //diff = A*X
    }
    
    diff = diff - vectorB; //diff = (A*X) - B
    
    return diff;
}

template<typename T>
SystemOfEquations<T>::SystemOfEquations(char *filename) {
    std::fstream file;
    Vector<T> v;
    
    file.open(filename); //Open file
    
    if(file.is_open()) //Has file opened succesfully?
    {
        std::cout << "FILE IS OPEN" << std::endl << std::endl;
        
        for (int i = 0; i <= SIZE ; ++i)
        {
            file >> v; //From stream file to Vector
            
            if(i < SIZE)
            {
                SetVectorsA(i, v);
            } else //Last vector is B matrix
            {
                SetVectorB(v);
            }
        }
    }
    file.close(); //Close file
}

template<typename T>
std::ostream & operator<< (std::ostream &wyjscie, SystemOfEquations<T> SoE)
{
    Vector<T> tmp;
    
    for (int i = 0; i <= SIZE; ++i)
    {
        if(i < SIZE)
        {
            tmp = SoE.GetVectorsA(i);
            std::cout << tmp << std::endl;
        } else
        {
            tmp = SoE.GetVectorB();
            std::cout << tmp << std::endl;
        }
    }
    
    return wyjscie;
}



#endif //SYSTEMOFEQUATIONS_SYSTEMOFEQUATIONS_H
