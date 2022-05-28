#pragma once
#include "./matrix_object.h"

void addMatrices(Matrix& matrixA, Matrix& matrixB, bool save); 
void subMatrices(Matrix& matrixA, Matrix &matrixB, bool save);
void multkMatrix(Matrix& matriA, double n, bool save);
void prodMatrices(Matrix& matrixA, Matrix& matrixB, bool save);
void showMatrix(std::vector< std::vector<double> > matrix, std::string header);
void determinantMatrix(const Matrix& matrix);
void invMatrix(Matrix& matrix, bool save);
void powMatrix(Matrix& matrix, int k, bool save);