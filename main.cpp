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
    string file = "task.txt";

    SoE = OpenFile(file);

    cout << SoE;

    return 0;
}

// TODO Matrix Class
// TODO Det() - in Matrix
// TODO Solution() - in SystemOfEquations