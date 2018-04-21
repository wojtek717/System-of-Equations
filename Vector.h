#ifndef SYSTEMOFEQUATIONS_VECTOR_H
#define SYSTEMOFEQUATIONS_VECTOR_H

#include <iostream>
#include "Consts.h"

template<typename T>
class Vector
{
private:
    T factors[SIZE];

public:

    /* Function calculate length of vector */
    T Length();

    /* Overload operator [] */
    T& operator[] (int id);
};

/* Overloads for operators */
template<typename T>
std::ostream & operator<< (std::ostream &wyjscie, Vector<T> &v);

template<typename T>
std::istream& operator>> (std::istream &is, Vector<T> &v);

template<typename T>
T operator * (Vector<T> v1, Vector<T> v2);

template<typename T>
Vector<T> operator * (T x1, Vector<T> v1);

template<typename T>
Vector<T> operator + (Vector<T> v1, Vector<T> v2);

template<typename T>
Vector<T> operator - (Vector<T> v1, Vector<T> v2);

template<typename T>
Vector<T> operator / (Vector<T> v1, T x1);



#endif //SYSTEMOFEQUATIONS_VECTOR_H
