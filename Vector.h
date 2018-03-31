#ifndef SYSTEMOFEQUATIONS_VECTOR_H
#define SYSTEMOFEQUATIONS_VECTOR_H

#include <iostream>
#include "Consts.h"

class Vector
{
private:
    float factors[ROZMIAR]; //JAK *factors TO NIE DZIALA XD?

public:
    Vector();

    void Set(int position, float value); //Set new value for factor on position
    float Get(int position); //Get value of factor on position

    float operator[] (int id);
};

/* Overloads for operators */
std::ostream & operator<< (std::ostream &wyjscie, Vector &v);
std::istream& operator>> (std::istream &is, Vector &v);
Vector operator * (Vector v1, Vector v2);
Vector operator * (float x1, Vector v1);
Vector operator + (Vector v1, Vector v2);
Vector operator - (Vector v1, Vector v2);
Vector operator / (Vector v1, float x1);



#endif //SYSTEMOFEQUATIONS_VECTOR_H
