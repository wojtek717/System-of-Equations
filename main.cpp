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
    SoE.CreateMatrixAB();

    cout << SoE;
    cout << endl << "###" << endl << endl;


    cout << SoE.GetMatrixAB() << endl;
    cout << SoE.GetMatrixAB().X[2];



    return 0;
}
