#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include "matrix_object.h"


#ifndef MATRIX_OPERATIONS_H
#define MATRIX_OPERATIONS_H

void addMatrices(Matrix& matrixA, Matrix& matrixB, bool save); 
void subMatrices(Matrix& matrixA, Matrix &matrixB, bool save);
void multkMatrix(Matrix& matriA, double n, bool save);
void prodMatrices(Matrix& matrixA, Matrix& matrixB, bool save);
void showMatrix(std::vector< std::vector<double> > matrix, std::string header);
void determinantMatrix(Matrix& matrix);
void invMatrix(Matrix& matrix, bool save);

#endif