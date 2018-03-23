#ifndef SYSTEMOFEQUATIONS_VECTOR_H
#define SYSTEMOFEQUATIONS_VECTOR_H

#include <iostream>

class Vector
{
private:
    float *factors;

public:
    Vector();

    void Set(int position, float value);
    float Get(int position);
};

std::ostream & operator<< (std::ostream &wyjscie, Vector &v);
std::istream& operator>> (std::istream &is, Vector &v);


#endif //SYSTEMOFEQUATIONS_VECTOR_H
