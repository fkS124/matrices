#pragma once 

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <cmath>
#include <algorithm>

class Matrix
{
    private:
        bool calculated_det = false;
        double determinant;
    public:
        int rows;
        int columns;

        std::vector< std::vector<double> > matrix;

        // Constructor
        Matrix(const int& = 1, const int& = 1);
        
        // Destructor
        ~Matrix();

        // prints the matrix in a nice way
        void showMatrix();

        // input by the user of a new matrix
        void inputMatrix();

        // input by the program of a new matrix
        void rawInputMatrix(const std::vector< std::vector<double> > &new_matrix);
        
        Matrix operator+(const Matrix& B);
        Matrix operator-(const Matrix& B);
        Matrix operator*(const Matrix& B);
        Matrix operator*(const int k);
        Matrix power(const int k);
        Matrix inversion();
        Matrix transpose();

        double det();
};