#pragma once 

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string.h>
#include <cmath>
#include <algorithm>

class Matrix
{
    private:
        int rows;
        int columns;

    public:
        std::vector< std::vector<double> > matrix;

        // Constructor
        Matrix(const int& = 1, const int& = 1);
        
        // Destructor
        ~Matrix();

        // returns the dimension of the matrix
        int getRowNumber();
        int getColumnNumber();

        // prints the matrix in a nice way
        void showMatrix();

        // input by the user of a new matrix
        void inputMatrix();

        // input by the program of a new matrix
        void rawInputMatrix(const std::vector< std::vector<double> > &new_matrix);
};