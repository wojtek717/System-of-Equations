#include <iostream>
#include <sstream>
#include "Vector.h"
#include "SystemOfEquations.h"
#include "Matrix.h"
#include "Consts.h"
#include "InputOutput.h"

using namespace std;

int main()
{
    SystemOfEquations SoE;
    Vector v;
    float factor;
    Vector tmp;
    string file = "task.txt";

    SoE = OpenFile(file);

    cout << SoE;

    tmp = SoE.GetVectorB();
    factor = tmp[0];
    cout << factor;

    return 0;
}

// TODO Matrix Class
// TODO Det() - in Matrix
// TODO Solution() - in SystemOfEquations

/* OVERLOADS:
 * */