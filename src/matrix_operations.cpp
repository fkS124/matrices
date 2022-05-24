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

void getCofactor(Matrix& matrix, Matrix& temp, int p, int q) {
    int i = 0, j = 0, n = matrix.getRowNumber();

    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            if (row != p && col != q) {
                temp.matrix[i][j++] = matrix.matrix[row][col];

                if (j == n - 1) {
                    j = 0;
                    i++;
                }
            }
        }
    }
}


void adjoint(Matrix& matrix, Matrix& adj) {
    int n = matrix.getRowNumber();
    if (n == 1) {
        adj.matrix[0][0] = 1;
        return;
    }

    int sign = 1;

    // generate the temp matrix 
    Matrix temp(n, n);
    std::vector< std::vector<double> > temp_matrix;
    for (int i = 0; i < n; i++) {
        std::vector<double> new_row;
        for (int j = 0; j < n; j++) {
            new_row.push_back(0);
        }
        temp_matrix.push_back(new_row);
    }
    temp.rawInputMatrix(temp_matrix);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            getCofactor(matrix, temp, i, j);

            sign = ((i+j)%2==0)? 1: -1;

            std::cout << temp.det() << std::endl;
            adj.matrix[j][i] = sign*temp.det();
        }
    }
}


Matrix matrixInversion(Matrix& matrix) {

    double det = matrix.det();
    std::vector< std::vector<double> > result;

    if (det == 0 || matrix.getColumnNumber() != matrix.getRowNumber()) {
        std::cerr << "The matrix is singular, no inverse can be found." << std::endl;
        return Matrix(0, 0);
    }

    int n = matrix.getRowNumber();

    /* if (n == 2) {
        result.push_back(std::vector<double>(matrix.matrix[1][1]/det, -1*matrix.matrix[0][1]/det));
        result.push_back(std::vector<double>(-1*matrix.matrix[1][0]/det, matrix.matrix[0][0]/det));
        Matrix resultMatrix(matrix.getRowNumber(), matrix.getColumnNumber());
        resultMatrix.rawInputMatrix(result);
        return resultMatrix;    
    } */

    Matrix adj(n, n);
    std::vector< std::vector<double> > temp_matrix;
    for (int i = 0; i < n; i++) {
        std::vector<double> new_row;
        for (int j = 0; j < n; j++) {
            new_row.push_back(0);
        }
        temp_matrix.push_back(new_row);
    }
    adj.rawInputMatrix(temp_matrix);

    std::cout << adj.matrix[0][0] << std::endl;
    adjoint(matrix, adj);
    std::cout << adj.matrix[0][0] << std::endl;

    for (int i = 0; i < n; i++) {
        std::vector<double> new_row;
        for (int j = 0; j < n; j++) new_row.push_back(adj.matrix[i][j]/double(det));
        result.push_back(new_row);
    }

    Matrix resulting_matrix(n, n);
    resulting_matrix.rawInputMatrix(result);
    return resulting_matrix;
}

