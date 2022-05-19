#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include "lib/matrix_object.h"


using std::cout, std::endl;


int main(int argc, char* argv) 
{
    Matrix matrixObject(2, 2);

    matrixObject.matrix = new double* [matrixObject.rows];
    for (int i = 0; i < matrixObject.rows; i++) {
        matrixObject.matrix[i] = new double[matrixObject.columns];
    }
    matrixObject.matrix[0][0] = 1.2;
    matrixObject.matrix[0][1] = 13;
    matrixObject.matrix[1][0] = 1.5;
    matrixObject.matrix[1][1] = 0;

    matrixObject.showMatrix();

    return 0;
}