#include <vector>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>


#ifndef MATRIX_OBJECT_H
#define MATRIX_OBJECT_H
class Matrix
{
    private:
        int rows = 1;
        int columns = 1;

    public:
        std::vector< std::vector<double> > matrix;

        // Constructor
        Matrix(int n_rows, int n_columns);
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

        // returns the determinant of the matrix
        double det();
};

#endif