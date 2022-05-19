#ifndef MATRIX_OBJECT_H
#define MATRIX_OBJECT_H
class Matrix
{
    private:
    public:
    
        int rows = 1;
        int columns = 1;
        double** matrix;

        // Constructor
        Matrix(int n_rows, int n_columns);


        // returns the dimension of the matrix
        int* getDimension();

        // prints the matrix in a good way
        void showMatrix();
};

#endif