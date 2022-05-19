#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include "matrix_object.h"


#ifndef MATRIX_OPERATIONS_H
#define MATRIX_OPERATIONS_H

int add(Matrix matrix1, Matrix matrix2); 
int sub(Matrix matrix1, Matrix matrix2);
int multWithNumber(Matrix matrix, double n);
void showMatrix(std::vector< std::vector<double> > matrix, std::string header);

#endif