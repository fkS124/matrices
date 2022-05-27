#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include "../lib/matrix_object.h"
#include "../lib/matrix_operations.h"


void showMatrix(std::vector< std::vector<double> > matrix, const std::string &header) {
    std::cout << "----------------------------" << std::endl;
    std::cout << header << std::endl;
    int rows = matrix.size();
    int columns = matrix[0].size();

    // loop through rows and columns of the matrix and prints everything
    for(int row = 0; row < rows; row++) {
        for (int col = 0; col < columns; col++) {
            std::cout << matrix[row][col] << "\t";
        };
        std::cout << "\n";
    };

    std::cout << "----------------------------" << std::endl;
}


void addMatrices(Matrix& matrixA, Matrix& matrixB, bool save) {
    Matrix result = add(matrixA, matrixB);
    showMatrix(result.matrix, std::string("The result of the sum is :"));

    if (save == true) {
        // save the result
    }
}


void subMatrices(Matrix& matrixA, Matrix& matrixB, bool save) {
    Matrix result = sub(matrixA, matrixB);
    showMatrix(result.matrix, std::string("The result of the substraction is :"));

    if (save == true) {
        // save the result
    }
}


void multkMatrix(Matrix& matrixA, double n, bool save) {
    Matrix result = multWithNumber(matrixA, n);
    showMatrix(result.matrix, std::string("The result of the multiplication is :"));

    if (save == true) {
        // save the result
    }
}


void prodMatrices(Matrix& matrixA, Matrix& matrixB, bool save) {
    Matrix result = prodBetweenMatrices(matrixA, matrixB);
    showMatrix(result.matrix, std::string("The result of the product is :"));

    if (save == true) {
        // save the result
    }
}


void determinantMatrix(Matrix& matrix) {
    std::cout << "The determinant of this matrix is : " << detMatrix(matrix) << std::endl;
} 


void invMatrix(Matrix& matrix, bool save) {
    Matrix result = matrixInversion(matrix);
    if (result.getRowNumber() != 0 && result.getColumnNumber() != 0)
        showMatrix(result.matrix, std::string("The inverted matrix is :"));

    if (save == true) {
        // save the result
    }
}