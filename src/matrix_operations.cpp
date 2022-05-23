#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include "../lib/matrix_object.h"


Matrix add(Matrix& matrixA, Matrix& matrixB) {
    int r, c;
    std::vector< std::vector<double> > new_matrix;
    std::string header;
    
    static int dim1[2] = {matrixA.getRowNumber(), matrixA.getColumnNumber()};
    static int dim2[2] = {matrixB.getRowNumber(), matrixB.getColumnNumber()};

    if (dim1[0] != dim2[0] || dim1[1] != dim2[1]) {
        std::cerr << "The two matrices haven't the same dimensions. Suming the two is impossible." << std::endl;
        return Matrix(0, 0);
    }

    for (r = 0; r < dim1[0]; r++) {
        std::vector<double> new_row;
        for (c = 0; c < dim1[1]; c++) {
            new_row.push_back(matrixA.matrix[r][c] + matrixB.matrix[r][c]);
        };
        new_matrix.push_back(new_row);
    }

    Matrix result(dim1[0], dim1[1]);
    result.rawInputMatrix(new_matrix);
    return result;
}


Matrix sub(Matrix& matrixA, Matrix& matrixB) {
    int r, c;
    std::vector< std::vector<double> > new_matrix;
    std::string header;
    
    static int dim1[2] = {matrixA.getRowNumber(), matrixA.getColumnNumber()};
    static int dim2[2] = {matrixB.getRowNumber(), matrixB.getColumnNumber()};

    if (dim1[0] != dim2[0] || dim1[1] != dim2[1]) {
        std::cerr << "The two matrices haven't the same dimensions. Substracting the two is impossible." << std::endl;
        return Matrix(0, 0);
    }

    for (r = 0; r < dim1[0]; r++) {
        std::vector<double> new_row;
        for (c = 0; c < dim1[1]; c++) {
            new_row.push_back(matrixA.matrix[r][c] - matrixB.matrix[r][c]);
        };
        new_matrix.push_back(new_row);
    }

    Matrix result(dim1[0], dim1[1]);
    result.rawInputMatrix(new_matrix);
    return result;
}


Matrix multWithNumber(Matrix& matrix, double n) {
    int r, c;
    std::vector< std::vector<double> > new_matrix;
    std::string header;
    

    for (r = 0; r < matrix.getRowNumber(); r++) {
        std::vector<double> new_row;
        for (c = 0; c < matrix.getColumnNumber(); c++) {
            new_row.push_back(matrix.matrix[r][c] * n);
        };
        new_matrix.push_back(new_row);
    }

    Matrix result(matrix.getRowNumber(), matrix.getRowNumber());
    result.rawInputMatrix(new_matrix);
    return result;
}


Matrix prodBetweenMatrices(Matrix& matrixA, Matrix& matrixB) {
    std::vector< std::vector<double> > new_matrix;
    std::string header;

    // check compatibility of the two matrices (M1 must have the same number of columns that M2 have of rows.)
    if (matrixA.getColumnNumber() != matrixB.getRowNumber()) {
        std::cerr << "The first matrix's number of column is not equal \n to the second's number of row. Multiplication is impossible" << std::endl;
        return Matrix(0, 0);
    }

    // create the resulting 2d-array
    for (int i = 0; i < matrixA.getRowNumber(); i++) {new_matrix.push_back(std::vector<double>());}

    // compute the product
    for (int i = 0; i < matrixA.getRowNumber(); i++) {
        for (int j = 0; j < matrixB.getColumnNumber(); j++) {
            double sum = 0; 
            for (int k = 0; k < matrixA.getColumnNumber(); k++) {
                sum += matrixA.matrix[i][k] * matrixB.matrix[k][j];
            }
            new_matrix[i].push_back(sum);
        }
    }

    Matrix result(matrixA.getRowNumber(), matrixB.getColumnNumber());
    result.rawInputMatrix(new_matrix);
    return result;
}


Matrix matrixInversion(Matrix& matrix) {

    double det = matrix.det();
    std::vector< std::vector<double> > result;

    if (matrix.getColumnNumber() == matrix.getRowNumber() == 2) {
        result.push_back(std::vector<double>(matrix.matrix[1][1]/det, -1*matrix.matrix[0][1]/det));
        result.push_back(std::vector<double>(-1*matrix.matrix[1][0]/det, matrix.matrix[0][0]/det));
        Matrix resultMatrix(matrix.getRowNumber(), matrix.getColumnNumber());
        resultMatrix.rawInputMatrix(result);
        return resultMatrix;    
    }

    
}