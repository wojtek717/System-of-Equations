#include "Vector.h"
#include "Consts.h"
#include <string>
#include <sstream>
#include <math.h>

Vector::Vector()
{

}

float Vector::Length()
{
    float sum = 0;

    for (int i = 0; i < SIZE; ++i)
    {
        sum = sum + (factors[i] * factors[i]); //Sum up squares of each factors
    }

    sum = sqrtf(sum); //Take square root of sum

    return sum;
}

float& Vector::operator[](int id)
{
    return factors[id];
}

std::ostream &operator<<(std::ostream &wyjscie, Vector &v)
{
    for(int i = 0; i < SIZE; ++i)
    {
        wyjscie << v[i] << " ";
    }
    return wyjscie;
}

std::istream &operator>>(std::istream &is, Vector &v)
{
    float tmp;
    std::string s;
    std::stringstream ss; //Sting as stream

    std::getline(is, s); //Get line from input stream to variable s
    ss.str (s); //Variable s as stream

    for (int i = 0; i < SIZE; ++i)
    {
        ss >> tmp;
        v[i] = tmp; //Set value of tmp to vector on position i
    }

    return is;
}

float operator*(Vector v1, Vector v2)
{
    float num = 0;

    for (int i = 0; i < SIZE; ++i)
    {
        num += v1[i] * v2[i];
    }

    return  num;
}


Vector operator*(float x1, Vector v1)
{
    Vector num;

    for (int i = 0; i < SIZE; ++i)
    {
        num[i] = v1[i] * x1;
    }

    return num;
}


Vector operator+(Vector v1, Vector v2)
{
    Vector num;

    for (int i = 0; i < SIZE; ++i)
    {
        num[i] = v1[i] + v2[i];
    }

    return num;
}

Vector operator-(Vector v1, Vector v2)
{
    Vector num;

    for (int i = 0; i < SIZE; ++i)
    {
        num[i] = v1[i] - v2[i];
    }

    return num;
}

Vector operator/(Vector v1, float x1)
{
    Vector num;

    if(x1 != 0)
    {
        for (int i = 0; i < SIZE; ++i)
        {
            num[i] = v1[i] * x1;
        }

        return num;
    } else
    {
        std::cout << "!!! DIVISION BY 0" << std::endl;

        return v1;
    }
}
