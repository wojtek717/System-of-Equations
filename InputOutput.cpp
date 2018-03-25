#include "InputOutput.h"
#include "Vector.h"
#include "Consts.h"
#include "SystemOfEquations.h"
#include <iostream>
#include <fstream>
#include <sstream>

SystemOfEquations OpenFile(std::string filename)
{
    std::fstream file;
    std::string s;
    std::stringstream ss;
    Vector v;
    Vector tmp;
    Vector tmp2;
    SystemOfEquations SoE;

    file.open(filename);

    if(file.is_open())
    {
        std::cout << "FILE IS OPEN" << std::endl;

        for (int i = 0; i <= ROZMIAR ; ++i)
        {
            file >> v;

            if(i < ROZMIAR)
            {
                SoE.SetVectorsA(i, v);
            } else
            {
                SoE.SetVectorB(v);
            }
        }
    }
    file.close();

    return SoE;
}
