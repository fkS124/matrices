#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include "../lib/matrix_object.h"


using vec = std::vector<double>;
using matrix_t = std::vector<vec>;


Matrix add(Matrix& A, Matrix& B) {
    // Compute the sum of two matrices
    Matrix result(A.getRowNumber(), A.getColumnNumber());

    if (A.getRowNumber() != B.getRowNumber() || A.getColumnNumber() != B.getColumnNumber()) {
        std::cerr << "The two matrices haven't the same dimensions. Suming the two is impossible." << std::endl;
        return Matrix(0, 0);
    }

    for (int r = 0; r < result.getRowNumber(); r++) {
        for (int c = 0; c < result.getColumnNumber(); c++) result.matrix[r][c] = A.matrix[r][c] + B.matrix[r][c];
    }
    return result;
}


Matrix sub(Matrix& A, Matrix& B) {
    // Compute the substraction between two matrices
    Matrix result(A.getRowNumber(), A.getColumnNumber());

    if (A.getRowNumber() != B.getRowNumber() || A.getColumnNumber() != B.getColumnNumber()) {
        std::cerr << "The two matrices haven't the same dimensions. Suming the two is impossible." << std::endl;
        return Matrix(0, 0);
    }

    for (int r = 0; r < result.getRowNumber(); r++) {
        for (int c = 0; c < result.getColumnNumber(); c++) result.matrix[r][c] = A.matrix[r][c] - B.matrix[r][c];
    }
    return result;
}


Matrix multWithNumber(Matrix& A, double n) {
    // Compute the product between a real number and a matrix
    Matrix result(A.getRowNumber(), A.getColumnNumber());

    for (int r = 0; r < A.getRowNumber(); r++) {
        for (int c = 0; c < A.getColumnNumber(); c++) result.matrix[r][c] = A.matrix[r][c] * n;
    }
    return result;
}


Matrix prodBetweenMatrices(Matrix& A, Matrix& B) {
    // Compute the product between two matrices
    Matrix result(A.getRowNumber(), B.getColumnNumber());

    // check compatibility of the two matrices (M1 must have the same number of columns that M2 have of rows.)
    if (A.getColumnNumber() != B.getRowNumber()) {
        std::cerr << "The first matrix's number of column is not equal \n to the second's number of row. Multiplication is impossible" << std::endl;
        return Matrix(0, 0);
    }

    // compute the product
    for (int i = 0; i < A.getRowNumber(); i++) {
        for (int j = 0; j < B.getColumnNumber(); j++) {
            double sum = 0; 
            for (int k = 0; k < A.getColumnNumber(); k++) {
                sum += A.matrix[i][k] * B.matrix[k][j];
            }
            result.matrix[i][j] = sum;
        }
    }

    return result;
}


Matrix transpose(Matrix &A) {
    // Transpose the given matrix
    Matrix result(A.getRowNumber(), A.getColumnNumber());

    for (int i = 0; i < result.getRowNumber(); i++) {
        for (int j = 0; j < result.getColumnNumber(); j++) {
            result.matrix[j][i] = A.matrix[i][j];
        }
    }

    return result;
}


Matrix smallerMatrix(Matrix &matrix, int i, int j) {
    // Get a smaller matrix (useful for calculating inverse and determinant)
    Matrix result(matrix.getRowNumber()-1, matrix.getColumnNumber()-1);

    int r = 0, c = 0;
    for (int a = 0; a < matrix.getRowNumber(); a++) {
        for (int b = 0; b < matrix.getColumnNumber(); b++) {
            if (i != a && j != b) {
                result.matrix[r][c] = matrix.matrix[a][b];
                c++;
                if (c == result.getColumnNumber()) {
                    r++;
                    c = 0;
                }
                
            }
        }
    }

    return result;
}


double detMatrix(Matrix matrix) {
    // Calculates the determinant of a given matrix
    std::vector< std::vector<double> > m = matrix.matrix;

    if (matrix.getRowNumber() == 2 && matrix.getColumnNumber() == 2) {
        return m[0][0]*m[1][1]-m[0][1]*m[1][0];
    }

    double det = 0;
    for (int c = 0; c < m.size(); c++) {
        Matrix smaller = smallerMatrix(matrix, 0, c);
        det += (pow((-1), c)) * m[0][c] * detMatrix(smaller);
    }
    return det;
}


Matrix matrixInversion(Matrix &matrix)
{
    // Calculates if possible the inverse of a matrix
    int n = matrix.getRowNumber();
    Matrix result(n, n);
    matrix_t A = result.matrix;
    matrix_t m = matrix.matrix;

    double det = detMatrix(matrix);
    if (det == 0) {
        std::cerr << "Inversion is impossible" << std::endl;
        return Matrix(0, 0);
    }


    if (n == 2) {
        A[0][0] = m[1][1]/det;
        A[0][1] = -1*m[0][1]/det;
        A[1][0] = -1*m[1][0]/det;
        A[1][1] = m[0][0]/det;
    }
    else {
        matrix_t cofactors;
        for (int r = 0; r < n; r++) {
            vec cofactorRow;
            for (int c = 0; c < n; c++) {
                Matrix minor = smallerMatrix(matrix, r, c);
                cofactorRow.push_back(pow(-1, r+c) * detMatrix(minor));
            }
            cofactors.push_back(cofactorRow);
        }

        Matrix cofactorMatrix(cofactors.size(), cofactors[0].size());
        cofactorMatrix.rawInputMatrix(cofactors);
        cofactorMatrix = transpose(cofactorMatrix);
        for (int r = 0; r < cofactorMatrix.getRowNumber(); r++) {
            for (int c = 0; c < cofactorMatrix.getColumnNumber(); c++) {
                cofactorMatrix.matrix[r][c] /= det;
            }
        }

        A = cofactorMatrix.matrix;
    }

    result.rawInputMatrix(A);
    return result;
}