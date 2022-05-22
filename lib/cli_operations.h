#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include "matrix_object.h"


#ifndef MATRIX_OPERATIONS_H
#define MATRIX_OPERATIONS_H

Matrix addMatrices(Matrix& matrixA, Matrix& matrixB, bool save); 
Matrix subMatrices(Matrix& matrixA, Matrix &matrixB, bool save);
Matrix multkMatrix(Matrix& matriA, double n, bool save);
Matrix prodMatrices(Matrix& matrixA, Matrix& matrixB, bool save);
void showMatrix(std::vector< std::vector<double> > matrix, std::string header);

#endif