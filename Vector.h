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

    void Set(int position, float value);
    float Get(int position);
};

std::ostream & operator<< (std::ostream &wyjscie, Vector &v);
std::istream& operator>> (std::istream &is, Vector &v);
Vector operator * (Vector v1, Vector v2);
Vector operator * (float x1, Vector v1);
Vector operator + (Vector v1, Vector v2);
Vector operator - (Vector v1, Vector v2);
Vector operator / (Vector v1, float x1);


#endif //SYSTEMOFEQUATIONS_VECTOR_H
