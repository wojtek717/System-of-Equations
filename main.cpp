#include <iostream>
#include <sstream>
#include "Vector.h"
#include "SystemOfEquations.h"
#include "Matrix.h"
#include "Consts.h"

int main()
{
    std::string s;
    std::stringstream ss; //Sting jako strumien

    Vector v;
    Vector tmp;
    Vector *A;
    SystemOfEquations SoE;

    s = "1 4 9\n";
    ss.str (s); //Zmienna s jako strumien

    ss >> v;

    for (int i = 0; i < ROZMIAR; ++i)
    {
        SoE.SetVectorsA(i, v);

        tmp = SoE.GetVectorsA(i);
        std::cout << tmp << std::endl;
    }

    s = "9 8 7\n";
    ss.str (s); //Zmienna s jako strumien

    ss >> v;

    SoE.SetVectorB(v);
    tmp = SoE.GetVectorB();
    std::cout << tmp << std::endl << std::endl;

    Matrix matrix(SoE.GetA(), SoE.GetVectorB());

    for (int j = 0; j <= ROZMIAR ; ++j)
    {
        tmp = matrix.GetVector(j);
        std::cout << tmp << std::endl;

    }

    /*
    A = SoE.GetVectorsA();
    tmp = A[0];
    std::cout << tmp << std::endl;

    tmp = matrix.GetVector(0);
    std::cout << tmp << std::endl;
*/

    return 0;
}