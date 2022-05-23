#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include "lib/matrix_object.h"
#include "lib/cli_operations.h"
#include <vector>


int main(int argc, char** argv) 
{
    // create the array of matrices
    std::vector<Matrix> matrices;

    std::string input;
    do {
        std::cout << ">>> ";
        std::cin >> input;
        if (input == "input") {
            int n_row, n_col;
            std::cout << "Number of rows : ";
            std::cin >> n_row;
            std::cout << "Number of columns : ";
            std::cin >> n_col;

            Matrix new_matrix(n_row, n_col);
            new_matrix.inputMatrix();
            matrices.push_back(new_matrix);
        }
        else if (input == "sum") {
            int index1, index2;
            std::cout << "Enter the index of the first matrix of the sum : ";
            std::cin >> index1;
            std::cout << "Enter the index of the second matrix of the sum : ";
            std::cin >> index2;
            if (0 <= index1 < matrices.size() || 0 <= index2 < matrices.size())
                addMatrices(matrices[index1], matrices[index2], false);
            else
                std::cerr << "Error: Passed indexes are incorrect." << std::endl;
        }
        else if (input == "subtract") {
            int index1, index2;
            std::cout << "Enter the index of the first matrix of the substraction : ";
            std::cin >> index1;
            std::cout << "Enter the index of the second matrix of the substraction : ";
            std::cin >> index2;
            if (0 <= index1 < matrices.size() || 0 <= index2 < matrices.size())
                subMatrices(matrices[index1], matrices[index2], false);
            else
                std::cerr << "Error: Passed indexes are incorrect." << std::endl;
        }
        else if (input == "multk") {
            int index, k;
            std::cout << "Enter the index of the matrix to multiply : ";
            std::cin >> index;
            std::cout << "Enter the number to multiply the matrix by : ";
            std::cin >> k;
            if (0 <= index < matrices.size())
                multkMatrix(matrices[index], k, false);
            else
                std::cerr << "Error: Passed index is incorrect." << std::endl;
        }
        else if (input == "product") {
            int index1, index2;
            std::cout << "Enter the index of the first matrix of the product : ";
            std::cin >> index1;
            std::cout << "Enter the index of the second matrix of the product : ";
            std::cin >> index2;
            if (0 <= index1 < matrices.size() || 0 <= index2 < matrices.size())
                prodMatrices(matrices[index1], matrices[index2], false);
            else
                std::cerr << "Error: Passed indexes are incorrect." << std::endl;
        }
        else if (input == "show") {
            int index;
            std::cout << "Enter the index of the matrix you want to show : ";
            std::cin >> index;
            if (0 <= index < matrices.size())
                matrices[index].showMatrix();
            else 
                std::cerr << "Error: Passed index is incorrect." << std::endl;
        }
        else if (input == "det") {
            int index;
            std::cout << "Enter the index of the matrix you want to calculate the determinant of : ";
            std::cin >> index;
            if (matrices[index].getRowNumber() != matrices[index].getColumnNumber())
                std::cerr << "Error: passed matrix is invalid." << std::endl;
            else 
                detMatrix(matrices[index]);
        }
        else {
            if (input != "exit")
                std::cout << input << " is not a regognized function. Type 'help' to get all the commands." << std::endl;
        }
    } while(input != "exit");

    return 0;
}
