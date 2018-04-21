#ifndef SYSTEMOFEQUATIONS_INPUTOUTPUT_H
#define SYSTEMOFEQUATIONS_INPUTOUTPUT_H

#include <iostream>
#include <fstream>
#include "SystemOfEquations.h"

/* [IN](std::string) filename - file name with task
 * [RETURN](SystemOfEquations) - Object with loaded factors */
template<typename T>
SystemOfEquations<T> OpenFile(char* filename);


#endif //SYSTEMOFEQUATIONS_INPUTOUTPUT_H
