#pragma once 

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <cmath>
#include <algorithm>

using std::string, std::vector, std::cout, std::endl, std::cin;
using vec = vector<double>;
using matrix_t = vector<vec>;


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
        Matrix(matrix_t matrix_input);
        
        // Destructor
        ~Matrix();

        // prints the matrix in a nice way
        void showMatrix();

        // input by the user of a new matrix
        void inputMatrix();
        
        Matrix operator+(const Matrix& B);
        Matrix operator-(const Matrix& B);
        Matrix operator*(const Matrix& B);
        Matrix operator*(const int k);
        Matrix power(const int k);
        Matrix inversion();
        Matrix transpose();

        double det();
};