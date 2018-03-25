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

    return 0;
}