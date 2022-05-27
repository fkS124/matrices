#include "../lib/matrix_object.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <cmath>
#include <algorithm>

using std::string;

const double SMALL = 1.0E-30;


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


void Matrix::rawInputMatrix(const std::vector< std::vector<double> > new_matrix) {
    matrix = new_matrix;
}


double Matrix::det() {
    if (rows == 2 && columns == 2) {
        std::cout << matrix[0][0] << " "  << matrix[1][1] << " "  << matrix[0][1] << " " << matrix[1][0] << std::endl;
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    }

    int n = matrix.size();
    double det = 1;

    for (int i = 0; i < n - 1; i++) {
        int r = i;
        double maxA = abs(matrix[i][i]);
        for (int k = i + 1; k < n; k++) {
            double val = abs( matrix[k][i]);
            if (val > maxA) {
                r = k;
                maxA = val;
            }
        }
        if ( r != i ) {
            for (int j = i; j < n; j++) std::swap( matrix[i][j], matrix[r][j] );
            det = -det;
        }

        double pivot = matrix[i][i];
        if (abs(pivot) < SMALL) return 0.0;

        for (int r = i + 1; r < n; r++) {
            double multiple = matrix[r][i] / pivot;
            for (int j = i; j < n; j++) matrix[r][j] -= multiple * matrix[i][j];
        }
        det *= pivot;
    }
    det *= matrix[n-1][n-1];

    return det;
}