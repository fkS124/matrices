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



int add(Matrix matrix1, Matrix matrix2) {
    int r, c;
    std::vector< std::vector<double> > new_matrix;
    std::string header;
    
    static int dim1[2] = {matrix1.getRowNumber(), matrix1.getColumnNumber()};
    static int dim2[2] = {matrix2.getRowNumber(), matrix2.getColumnNumber()};

    if (dim1[0] != dim2[0] || dim1[1] != dim2[1]) {
        std::cout << "The two matrices haven't the same dimensions. Suming the two is impossible." << std::endl;
        return -1;
    }

    for (r = 0; r < dim1[0]; r++) {
        std::vector<double> new_row;
        for (c = 0; c < dim1[1]; c++) {
            new_row.push_back(matrix1.matrix[r][c] + matrix2.matrix[r][c]);
        };
        new_matrix.push_back(new_row);
    }

    header = "Result of addition ---------";
    showMatrix(new_matrix, header);

    return 0;
}


int sub(Matrix matrix1, Matrix matrix2) {
    int r, c;
    std::vector< std::vector<double> > new_matrix;
    std::string header;
    
    static int dim1[2] = {matrix1.getRowNumber(), matrix1.getColumnNumber()};
    static int dim2[2] = {matrix2.getRowNumber(), matrix2.getColumnNumber()};

    if (dim1[0] != dim2[0] || dim1[1] != dim2[1]) {
        std::cout << "The two matrices haven't the same dimensions. Substracting the two is impossible." << std::endl;
        return -1;
    }

    for (r = 0; r < dim1[0]; r++) {
        std::vector<double> new_row;
        for (c = 0; c < dim1[1]; c++) {
            new_row.push_back(matrix1.matrix[r][c] - matrix2.matrix[r][c]);
        };
        new_matrix.push_back(new_row);
    }

    header = "Result of substraction -----";
    showMatrix(new_matrix, header);

    return 0;
}


int multWithNumber(Matrix matrix, double n) {
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


int prodMatrices(Matrix matrix1, Matrix matrix2) {
    int r1, c1, r2, c2;
    std::vector< std::vector<double> > new_matrix;
    std::vector< std::vector<double> > m1Rows;
    std::vector< std::vector<double> > m2Columns;
    std::string header;
    
    // get dimensions of matrices
    r1 = matrix1.getRowNumber();
    c1 = matrix1.getColumnNumber();
    r2 = matrix2.getRowNumber();
    c2 = matrix2.getColumnNumber();

    // check compatibility of the two matrices (M1 must have the same number of columns that M2 have of rows.)
    if (c1 != r2) {
        std::cout << "The first matrix's number of column is not equal \n to the second's number of row. Multiplication is impossible" << std::endl;
        return -1;
    }

    // create the resulting 2d-array
    for (int i = 0; i < r1; i++) {
        std::vector<double> new_row;
        new_matrix.push_back(new_row);
    }

    // get matrix1's rows
    for (int r = 0; r < r1; r++) {
        m1Rows.push_back(matrix1.matrix[r]);
    }

    // create a 2d-array for storing columns
    for (int c = 0; c < c2; c++) {
        std::vector<double> new_columns;
        m2Columns.push_back(new_columns);
    }

    // get matrix2's columns
    for (int r = 0; r < r2; r++) {
        for (int c = 0; c < c2; c++) {
            m2Columns[c].push_back(matrix2.matrix[r][c]);
        }
    }

    for (int a = 0; a < m1Rows.size(); a++) {
        for (int z = 0; z < m2Columns.size(); z++) {
            double new_value = 0;
            for (int b = 0; b < m1Rows[a].size(); b++) {
                new_value += m1Rows[a][b] * m2Columns[z][b];
            }
            new_matrix[a].push_back(new_value);
        }
    }

    header = "The result of the product is :";
    showMatrix(new_matrix, header);
    return 0;
}