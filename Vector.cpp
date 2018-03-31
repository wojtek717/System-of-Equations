#include "Vector.h"
#include "Consts.h"
#include <string>
#include <sstream>

Vector::Vector()
{
    //factors = new float[ROZMIAR]; Tak nie dziala xD? :D
}

float& Vector::operator[](int id)
{
    return factors[id];
}

std::ostream &operator<<(std::ostream &wyjscie, Vector &v)
{
    for(int i = 0; i < ROZMIAR; ++i)
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

    for (int i = 0; i < ROZMIAR; ++i)
    {
        ss >> tmp;
        v[i] = tmp; //Set value of tmp to vector on position i
    }

    return is;
}

Vector operator*(Vector v1, Vector v2)
{
    Vector num;
    float tmp;

    //a2b3−a3b2;    a3b1−a1b3;  a1b2−a2b1

    tmp = v1[1]*v2[2] - v1[2]*v2[1];
    num[0] = tmp;

    tmp = v1[2]*v2[0] - v1[0]*v2[2];
    num[1] = tmp;

    tmp = v1[0]*v2[1] - v1[1]*v2[0];
    num[2] = tmp;

    return  num;
}


Vector operator*(float x1, Vector v1)
{
    Vector num;
    float tmp;

    tmp = v1[0] * x1;
    num[0] = tmp;

    tmp = v1[1] * x1;
    num[1] = tmp;

    tmp = v1[2] * x1;
    num[2] = tmp;

    return num;
}


Vector operator+(Vector v1, Vector v2)
{
    Vector num;
    float tmp;

    tmp = v1[0] + v2[0];
    num[0] = tmp;

    tmp = v1[1] + v2[1];
    num[1] = tmp;

    tmp = v1[2] + v2[2];
    num[2] = tmp;

    return num;
}

Vector operator-(Vector v1, Vector v2)
{
    Vector num;
    float tmp;

    tmp = v1[0] - v2[0];
    num[0] = tmp;

    tmp = v1[1] - v2[1];
    num[1] = tmp;

    tmp = v1[2] - v2[2];
    num[2] = tmp;

    return num;
}

Vector operator/(Vector v1, float x1)
{
    Vector num;
    float tmp;

    if(x1 != 0)
    {
        tmp = v1[0] * x1;
        num[0] = tmp;

        tmp = v1[1] * x1;
        num[1] = tmp;

        tmp = v1[2] * x1;
        num[2] = tmp;

        return num;
    } else
    {
        std::cout << "!!! DIVISION BY 0" << std::endl;

        return v1;
    }
}
