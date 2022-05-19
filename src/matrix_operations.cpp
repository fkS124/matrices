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

    if (dim1[0] != dim2[0] || dim1[1] != dim2[1])
        return -1;

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

    if (dim1[0] != dim2[0] || dim1[1] != dim2[1])
        return -1;

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