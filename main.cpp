#include <iostream>
#include <sstream>
#include "Vector.h"
#include "SystemOfEquations.h"

int main()
{
    std::string s;
    std::stringstream ss; //Sting jako strumien

    Vector v;
    Vector tmp;
    SystemOfEquations SoE;

    s = "1 4 9\n";
    ss.str (s); //Zmienna s jako strumien

    ss >> v;

    std::cout << v << std::endl;

    SoE.SetVectorsA(0, v);
    tmp = SoE.GetVectorsA(0);

    std::cout << tmp;

    s = "9 8 7\n";
    ss.str (s); //Zmienna s jako strumien

    ss >> v;

    SoE.SetVectorB(v);
    tmp = SoE.GetVectorB();
    std::cout << tmp;

    return 0;
}