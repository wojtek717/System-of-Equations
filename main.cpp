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
    Vector<float> v;

    SystemOfEquations<float> SoE; //Create new object - System of equations

    char file[] = "task.txt"; //Import name of file with system of equations
    SoE = OpenFile<float>(file); //Import system of equations

    SoE.CreateMatrixAB(); //Create matrix of algebraic complements

    cout << "Imported matrix: " << endl << SoE << endl; //Print imported matrix
    cout << "Elimination: " << endl << SoE.GetMatrixAB() << endl; //Print matrix after elimination

    for (int i = 0; i < SIZE; ++i)
    {
        cout << "x" << i+1 << " = " << SoE.GetMatrixAB().GetVectorX()[i] << endl; //Print solutions
    }

    v = SoE.Diff();
    cout << endl << "Error's vector: " << v;
    cout << endl << "Error = " << SoE.Diff().Length(); //Calculate and print mistake

    return 0;
}
