#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include "matrix_object.h"


#ifndef MATRIX_OPERATIONS_H
#define MATRIX_OPERATIONS_H

int add(Matrix& matrixA, Matrix& matrixB); 
int sub(Matrix& matrixA, Matrix &matrixB);
int multWithNumber(Matrix& matriA, double n);
int prodMatrices(Matrix& matrixA, Matrix& matrixB);
void showMatrix(std::vector< std::vector<double> > matrix, std::string header);

#endif