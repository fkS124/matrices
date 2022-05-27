#pragma once 
#include "./matrix_object.h"

Matrix add(Matrix& matrixA, Matrix& matrixB); 
Matrix sub(Matrix& matrixA, Matrix& matrixB);
Matrix multWithNumber(Matrix& matriA, double n);
Matrix prodBetweenMatrices(Matrix& matrixA, Matrix& matrixB);
Matrix matrixInversion(Matrix &matrix);
Matrix transpose(Matrix &matrix);
Matrix smallerMatrix(Matrix &matrix, int i, int j);
double detMatrix(Matrix matrix);
