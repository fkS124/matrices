#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include "../lib/matrix_object.h"


void showMatrix(std::vector< std::vector<double> > matrix, std::string header) {
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



int add(Matrix& matrixA, Matrix& matrixB) {
    int r, c;
    std::vector< std::vector<double> > new_matrix;
    std::string header;
    
    static int dim1[2] = {matrixA.getRowNumber(), matrixA.getColumnNumber()};
    static int dim2[2] = {matrixB.getRowNumber(), matrixB.getColumnNumber()};

    if (dim1[0] != dim2[0] || dim1[1] != dim2[1]) {
        std::cerr << "The two matrices haven't the same dimensions. Suming the two is impossible." << std::endl;
        return -1;
    }

    for (r = 0; r < dim1[0]; r++) {
        std::vector<double> new_row;
        for (c = 0; c < dim1[1]; c++) {
            new_row.push_back(matrixA.matrix[r][c] + matrixB.matrix[r][c]);
        };
        new_matrix.push_back(new_row);
    }

    header = "Result of addition ---------";
    showMatrix(new_matrix, header);

    return 0;
}


int sub(Matrix& matrixA, Matrix& matrixB) {
    int r, c;
    std::vector< std::vector<double> > new_matrix;
    std::string header;
    
    static int dim1[2] = {matrixA.getRowNumber(), matrixA.getColumnNumber()};
    static int dim2[2] = {matrixB.getRowNumber(), matrixB.getColumnNumber()};

    if (dim1[0] != dim2[0] || dim1[1] != dim2[1]) {
        std::cerr << "The two matrices haven't the same dimensions. Substracting the two is impossible." << std::endl;
        return -1;
    }

    for (r = 0; r < dim1[0]; r++) {
        std::vector<double> new_row;
        for (c = 0; c < dim1[1]; c++) {
            new_row.push_back(matrixA.matrix[r][c] - matrixB.matrix[r][c]);
        };
        new_matrix.push_back(new_row);
    }

    header = "Result of substraction -----";
    showMatrix(new_matrix, header);

    return 0;
}


int multWithNumber(Matrix& matrix, double n) {
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

    header = "Result of the multiplication";
    showMatrix(new_matrix, header);

    return 0;
}


int prodMatrices(Matrix& matrixA, Matrix& matrixB) {
    std::vector< std::vector<double> > new_matrix;
    std::string header;

    // check compatibility of the two matrices (M1 must have the same number of columns that M2 have of rows.)
    if (matrixA.getColumnNumber() != matrixB.getRowNumber()) {
        std::cerr << "The first matrix's number of column is not equal \n to the second's number of row. Multiplication is impossible" << std::endl;
        return -1;
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

    header = "The result of the product is :";
    showMatrix(new_matrix, header);
    return 0;
}