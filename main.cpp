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
    SoE.CreateMatricies();

    cout << SoE;
    cout << endl << "###" << endl << endl;

    for (int i = 0; i < ROZMIAR + 1; ++i)
    {
        cout << SoE.matrices[i];
        cout << "**************************" << endl;
    }


    return 0;
}

// TODO Matrix Class
// TODO Det() - in Matrix
// TODO Solution() - in SystemOfEquations

/* OVERLOADS:
 * */