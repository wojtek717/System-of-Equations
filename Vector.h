#ifndef SYSTEMOFEQUATIONS_VECTOR_H
#define SYSTEMOFEQUATIONS_VECTOR_H

#include <iostream>
#include "Consts.h"

class Vector
{
private:
    float factors[SIZE];

public:
    Vector();

    /* Function calculate length of vector */
    float Length();

    /* Overload operator [] */
    float& operator[] (int id);
};

/* Overloads for operators */
std::ostream & operator<< (std::ostream &wyjscie, Vector &v);
std::istream& operator>> (std::istream &is, Vector &v);
float operator * (Vector v1, Vector v2);
Vector operator * (float x1, Vector v1);
Vector operator + (Vector v1, Vector v2);
Vector operator - (Vector v1, Vector v2);
Vector operator / (Vector v1, float x1);



#endif //SYSTEMOFEQUATIONS_VECTOR_H
