#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include "matrix_object.h"


#ifndef MATRIX_OPERATIONS_H
#define MATRIX_OPERATIONS_H

Matrix add(Matrix& matrixA, Matrix& matrixB); 
Matrix sub(Matrix& matrixA, Matrix& matrixB);
Matrix multWithNumber(Matrix& matriA, double n);
Matrix prodBetweenMatrices(Matrix& matrixA, Matrix& matrixB);

#endif