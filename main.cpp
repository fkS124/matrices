#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include "lib/matrix_object.h"
#include "lib/matrix_operations.h"
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
            matrices.push_back(new_matrix);
        }
        else if (input == "sum") {
            int index1, index2;
            std::cout << "Enter the index of the first matrix of the sum : ";
            std::cin >> index1;
            std::cout << "Enter the index of the second matrix of the sum : ";
            std::cin >> index2;
            add(matrices[index1], matrices[index2]);
        }
        else if (input == "show") {
            int index;
            std::cout << "Enter the index of the matrix you want to show : ";
            std::cin >> index;
            if (0 <= index && index < matrices.size()) {
                matrices[index].showMatrix();
            }
        }
        else {
            if (input != "exit")
                std::cout << input << " is not a regognized function. Type 'help' to get all the commands." << std::endl;
        }
    } while(input != "exit");

    return 0;
}
