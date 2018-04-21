#include "Vector.h"
#include "Consts.h"
#include <string>
#include <sstream>
#include <math.h>

template<typename T>
T Vector<T>::Length()
{
    T sum = 0;

    for (int i = 0; i < SIZE; ++i)
    {
        sum = sum + (factors[i] * factors[i]); //Sum up squares of each factors
    }

    sum = sqrtf(sum); //Take square root of sum

    return sum;
}

template<typename T>
T& Vector<T>::operator[](int id)
{
    return factors[id];
}

template<typename T>
std::ostream &operator<<(std::ostream &wyjscie, Vector<T> &v)
{
    for(int i = 0; i < SIZE; ++i)
    {
        wyjscie << v[i] << " ";
    }
    return wyjscie;
}

template<typename T>
std::istream &operator>>(std::istream &is, Vector<T> &v)
{
    T tmp;
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

template<typename T>
T operator*(Vector<T> v1, Vector<T> v2)
{
    T num = 0;

    for (int i = 0; i < SIZE; ++i)
    {
        num += v1[i] * v2[i];
    }

    return  num;
}

template<typename T>
Vector<T> operator*(T x1, Vector<T> v1)
{
    Vector<T> num;

    for (int i = 0; i < SIZE; ++i)
    {
        num[i] = v1[i] * x1;
    }

    return num;
}

template<typename T>
Vector<T> operator+(Vector<T> v1, Vector<T> v2)
{
    Vector<T> num;

    for (int i = 0; i < SIZE; ++i)
    {
        num[i] = v1[i] + v2[i];
    }

    return num;
}

template<typename T>
Vector<T> operator-(Vector<T> v1, Vector<T> v2)
{
    Vector<T> num;

    for (int i = 0; i < SIZE; ++i)
    {
        num[i] = v1[i] - v2[i];
    }

    return num;
}

template<typename T>
Vector<T> operator/(Vector<T> v1, T x1)
{
    Vector<T> num;

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
