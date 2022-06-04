#include "../lib/matrix_object.h"
using std::string;
using std::vector;
using vec = vector<double>;
using matrix_t = vector<vec>;



Matrix::Matrix(const int& n_rows, const int& n_columns) {
    // get the number of row and columns
    rows = n_rows;
    columns = n_columns;

    for (int i = 0; i < rows; i++) 
        matrix.push_back(vec(n_columns, 0));
}

Matrix::~Matrix(){}

void Matrix::showMatrix() {
    std::cout << "Your " << rows << "x" << columns << " matrix ------------" << std::endl;

    // loop through rows and columns of the matrix and prints everything
    for(int row = 0; row < rows; row++) {
        for (int col = 0; col < columns; col++) 
            std::cout << matrix[row][col] << "\t";

        std::cout << std::endl;
    };

    std::cout << "----------------------------\n";
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

/* ------------------------ OPERATIONS --------------------------------- */

Matrix Matrix::operator+(const Matrix& B) {
        // Compute the sum of two matrices
    if (rows != B.rows || columns != B.columns) {
        std::cerr << "The two matrices haven't the same dimensions. Suming the two is impossible." << std::endl;
        return Matrix(0, 0);
    }

    Matrix result(rows, columns);

    for (int r = 0; r < result.rows; r++) {
        for (int c = 0; c < result.columns; c++) 
            result.matrix[r][c] = matrix[r][c] + B.matrix[r][c];
    }

    return result;
}

Matrix Matrix::operator-(const Matrix& B) {
        if (rows != B.rows || columns != B.columns) {
        std::cerr << "The two matrices haven't the same dimensions. Suming the two is impossible." << std::endl;
        return Matrix(0, 0);
    }

    Matrix result(rows, columns);

    for (int r = 0; r < result.rows; r++) {
        for (int c = 0; c < result.columns; c++) 
            result.matrix[r][c] = matrix[r][c] - B.matrix[r][c];
    }
    return result;
}

Matrix Matrix::operator*(const Matrix& B) {
        // Compute the product between two matrices
    Matrix result(rows, B.columns);

    // check compatibility of the two matrices (M1 must have the same number of columns that M2 have of rows.)
    if (columns != B.rows) {
        std::cerr << "The first matrix's number of column is not equal \n to the second's number of row. Multiplication is impossible" << std::endl;
        return Matrix(0, 0);
    }

    // compute the product
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < B.columns; j++) {
            
            double sum = 0; 
            for (int k = 0; k < columns; k++) 
                sum += matrix[i][k] * B.matrix[k][j];
    
            result.matrix[i][j] = sum;
        }
    }

    return result;
}


Matrix Matrix::operator*(const int k) {
    Matrix result(rows, columns);
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < columns; c++) result.matrix[r][c] = matrix[r][c] * k;
    }
    return result;
}

Matrix powerMatrix(Matrix& A, int k) {
    Matrix result(A.rows, A.columns);
    result.rawInputMatrix(A.matrix);

    if (A.rows != A.columns) return Matrix(0, 0);
    for (int i = 1; i < k; i++) result.rawInputMatrix((result * A).matrix);

    return result;
}


Matrix identityMatrix(const int dimension) {
    Matrix result(dimension, dimension);
    for (int i = 0; i < dimension; i++) result.matrix[i][i] = 1;
    return result;
}



Matrix Matrix::transpose() {
    // Transpose the given matrix
    Matrix result(rows, columns);

    for (int i = 0; i < result.rows; i++) {
        for (int j = 0; j < result.columns; j++)
            result.matrix[j][i] = matrix[i][j];
    }

    return result;
}


Matrix smallerMatrix(Matrix &matrix, int i, int j) {
    // Get a smaller matrix (useful for calculating inverse and determinant)
    Matrix result(matrix.rows-1, matrix.columns-1);

    int r = 0, c = 0;
    for (int a = 0; a < matrix.rows; a++) {
        for (int b = 0; b < matrix.columns; b++) {
            if (i != a && j != b) {
                result.matrix[r][c] = matrix.matrix[a][b];
                c++;
                if (c == result.columns) {
                    r++;
                    c = 0;
                }
                
            }
        }
    }

    return result;
}


double Matrix::det() {
    if (calculated_det) {
        return determinant;
    }
    // Calculates the determinant of a given matrix
    std::vector< std::vector<double> > m = matrix;

    if (rows == 2 && columns == 2) {
        return m[0][0]*m[1][1]-m[0][1]*m[1][0];
    }

    double det = 0;
    for (int c = 0; c < m.size(); c++) {
        Matrix smaller = smallerMatrix(*this, 0, c);
        det += (pow((-1), c)) * m[0][c] * smaller.det();
    }
    
    calculated_det = true;
    determinant = det;
    return det;
}


Matrix Matrix::inversion()
{
    double det = this->det();
    if (det == 0) {
        std::cerr << "Inversion is impossible" << std::endl;
        return Matrix(0, 0);
    }

    // Calculates if possible the inverse of a matrix
    int n = rows;
    Matrix result(n, n);
    matrix_t A = result.matrix;
    matrix_t m = matrix;

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
                Matrix minor = smallerMatrix(*this, r, c);
                cofactorRow.push_back(pow(-1, r+c) * minor.det());
            }
            cofactors.push_back(cofactorRow);
        }

        Matrix cofactorMatrix(cofactors.size(), cofactors[0].size());
        cofactorMatrix.rawInputMatrix(cofactors);
        cofactorMatrix = cofactorMatrix.transpose();
        for (int r = 0; r < cofactorMatrix.rows; r++) {
            for (int c = 0; c < cofactorMatrix.columns; c++) {
                cofactorMatrix.matrix[r][c] /= det;
            }
        }

        A = cofactorMatrix.matrix;
    }

    result.rawInputMatrix(A);
    return result;
}

Matrix Matrix::power(const int k) {
    if (k < -1 || rows != columns) {
        return Matrix(0, 0);
    }

    switch(k) {
        case -1:
            return inversion();
        case 0:
            return identityMatrix(rows); 
        default:
            return powerMatrix(*this, k);
    }
}