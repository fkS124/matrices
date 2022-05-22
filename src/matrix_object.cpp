#include "../lib/matrix_object.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>

using std::string;


Matrix::Matrix(int n_rows, int n_columns) {
    // get the number of row and columns
    rows = n_rows;
    columns = n_columns;
}

Matrix::~Matrix() {
}


int Matrix::getRowNumber() {
    return rows;
}

int Matrix::getColumnNumber() {
    return columns;
}


void Matrix::showMatrix() {
    std::cout << "Your " << rows << "x" << columns << " matrix ------------" << std::endl;

    // loop through rows and columns of the matrix and prints everything
    for(int row = 0; row < rows; row++) {
        for (int col = 0; col < columns; col++) {
            std::cout << matrix[row][col] << "\t";
        };
        std::cout << "\n";
    };

    std::cout << "----------------------------" << std::endl;
}


void Matrix::inputMatrix() {
    for (int row = 0; row < rows; row++) {
        std::vector<double> new_row;
        for (int col = 0; col < columns; col++) {
            int col_val;
            std::cout << "Enter value of row " << row << " & col " << col << " : ";
            std::cin >> col_val;
            new_row.push_back(col_val);
        }
        matrix.push_back(new_row);
    }
}


void Matrix::rawInputMatrix(std::vector< std::vector<double> > new_matrix) {
    matrix = new_matrix;
}


double Matrix::det() {
    if (rows == columns == 2) {
        return matrix[0][0]*matrix[1][1] - matrix[0][1]*matrix[1][0];
    }


}