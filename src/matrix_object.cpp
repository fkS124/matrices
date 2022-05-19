#include "../lib/matrix_object.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>

using std::string;


Matrix::Matrix(int n_rows, int n_columns) {
    rows = n_rows;
    columns = n_columns;
}

int* Matrix::getDimension() {
    static int dimension[2];
    dimension[0] = rows;
    dimension[1] = columns;
    return dimension;
}

void Matrix::showMatrix() {
    for(int row = 0; row <= rows; row++) {
        for (int col = 0; col <= columns; col++) {
            string val = std::to_string(matrix[row][col]);
            std::cout << val;;
        };
        printf("\n");
    };
}