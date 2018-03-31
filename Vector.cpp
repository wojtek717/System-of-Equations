#include "Vector.h"
#include "Consts.h"
#include <string>
#include <sstream>

Vector::Vector()
{
    //factors = new float[ROZMIAR]; Tak nie dziala xD? :D
}

void Vector::Set(int position, float value)
{
    factors[position] = value;
}

float Vector::Get(int position)
{
    return factors[position];
}

float Vector::operator[](int id)
{
    return factors[id];
}

std::ostream &operator<<(std::ostream &wyjscie, Vector &v)
{
    for(int i = 0; i < ROZMIAR; ++i)
    {
        wyjscie << v.Get(i) << " ";
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
        v.Set(i, tmp); //Set value of tmp to vector on position i
    }

    return is;
}

Vector operator*(Vector v1, Vector v2)
{
    Vector num;
    float tmp;

    //a2b3−a3b2;    a3b1−a1b3;  a1b2−a2b1

    tmp = v1.Get(1)*v2.Get(2) - v1.Get(2)*v2.Get(1);
    num.Set(0, tmp);

    tmp = v1.Get(2)*v2.Get(0) - v1.Get(0)*v2.Get(2);
    num.Set(1, tmp);

    tmp = v1.Get(0)*v2.Get(1) - v1.Get(1)*v2.Get(0);
    num.Set(2, tmp);

    return  num;
}


Vector operator*(float x1, Vector v1)
{
    Vector num;
    float tmp;

    tmp = v1.Get(0) * x1;
    num.Set(0, tmp);

    tmp = v1.Get(1) * x1;
    num.Set(1, tmp);

    tmp = v1.Get(2) * x1;
    num.Set(2, tmp);

    return num;
}


Vector operator+(Vector v1, Vector v2)
{
    Vector num;
    float tmp;

    tmp = v1.Get(0) + v2.Get(0);
    num.Set(0, tmp);

    tmp = v1.Get(1) + v2.Get(1);
    num.Set(1, tmp);

    tmp = v1.Get(2) + v2.Get(2);
    num.Set(2, tmp);

    return num;
}

Vector operator-(Vector v1, Vector v2)
{
    Vector num;
    float tmp;

    tmp = v1.Get(0) - v2.Get(0);
    num.Set(0, tmp);

    tmp = v1.Get(1) - v2.Get(1);
    num.Set(1, tmp);

    tmp = v1.Get(2) - v2.Get(2);
    num.Set(2, tmp);

    return num;
}

Vector operator/(Vector v1, float x1)
{
    Vector num;
    float tmp;

    if(x1 != 0)
    {
        tmp = v1.Get(0) * x1;
        num.Set(0, tmp);

        tmp = v1.Get(1) * x1;
        num.Set(1, tmp);

        tmp = v1.Get(2) * x1;
        num.Set(2, tmp);

        return num;
    } else
    {
        std::cout << "!!! DIVISION BY 0" << std::endl;

        return v1;
    }
}
