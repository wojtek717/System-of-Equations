#include "Vector.h"
#include "Consts.h"
#include <string>
#include <sstream>

Vector::Vector()
{
    factors = new float[ROZMIAR];
}

void Vector::Set(int position, float value)
{
    factors[position] = value;
}

float Vector::Get(int position)
{
    return factors[position];
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
    std::stringstream ss; //Sting jako strumien

    std::getline(is, s);
    ss.str (s); //Zmienna s jako strumien

    for (int i = 0; i < ROZMIAR; ++i)
    {
        ss >> tmp;
        v.Set(i, tmp);
    }

    return is;
}
