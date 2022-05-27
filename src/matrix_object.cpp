#include "../lib/matrix_object.h"
using std::string;
using std::vector;


Matrix::Matrix(const int& n_rows, const int& n_columns) {
    // get the number of row and columns
    rows = n_rows;
    columns = n_columns;

    for (int i = 0; i < rows; i++) 
        matrix.push_back(vector<double>(n_columns, 0));
}

Matrix::~Matrix(){}

int Matrix::getRowNumber() {return rows;}

int Matrix::getColumnNumber() {return columns;}

void Matrix::showMatrix() {
    std::cout << "Your " << rows << "x" << columns << " matrix ------------" << std::endl;

    // loop through rows and columns of the matrix and prints everything
    for(int row = 0; row < rows; row++) {
        for (int col = 0; col < columns; col++) 
            std::cout << matrix[row][col] << "\t";

        std::cout << std::endl;
    };

    std::cout << "----------------------------" << std::endl;
}


void Matrix::inputMatrix() {
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < columns; col++) {
            double col_val;
            std::cout << "Enter value of row " << row << " & col " << col << " : ";
            std::cin >> col_val;
            matrix[row][col] = col_val;
        }
    }
    
    showMatrix();
}


void Matrix::rawInputMatrix(const vector< vector<double> > &new_matrix) { matrix = new_matrix; }