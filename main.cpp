#include "lib/matrix_object.h"
#include "lib/cli_operations.h"

using std::string, std::stoi;
using word_list = std::vector<string>;
using matrix_list = std::vector<Matrix>;

const int commandNumber = 9;
string commandList[commandNumber] = {"input", "sum", "subtract", "multk", "product", "show", "det", "inv", "exit"};
int nArgs[commandNumber] = {2, 2, 2, 2, 2, 1, 1, 1, 0};
matrix_list matrices;

word_list scanInput(const string &input);
string getFunc(word_list &command);
int execFunc(const word_list &command);

int main(int argc, char** argv) 
{
    // create the string that will be used as an input
    string input;

    // program's main loop
    do {
        std::cout << ">>> ";
        std::getline(std::cin, input);

        if (input == "exit") 
            break;
        
        else if (input != "") {
            word_list command = scanInput(input);
            
            std::cout << getFunc(command) << std::endl;
        }
        
    } while(input != "exit");

    return 0;
}


word_list scanInput(const string &input) 
{
    // function to execute an inputed command
    string temp = "";
    word_list words;

    for (int i = 0; i < input.length(); i++) {
        if (input[i] == ' ') {
            words.push_back(temp);
            temp = "";
        }
        else 
            temp.push_back(input[i]);
    }
    words.push_back(temp);

    return words;
}


string getFunc(word_list &command) {
    for (int i = 0; i < commandNumber; i++) {
        if (commandList[i] == command[0] && command.size() == nArgs[i]+1) {
            int returned = execFunc(command);
            if (returned == 0)
                return " ";
            else if (returned == -1)
                return "Error: index error.";
            else    
                return "Error: wrong arguments passed.";
        }
    }

    return "Error : unrecognized command.";
}


int execFunc(const word_list &command) {
    string mainCommand = command[0];

    if (mainCommand == "input") {
        int d1 = stoi(command[1]), d2 = stoi(command[2]);
        if (d1 <= 0 || d2 <= 0) return -1;
        Matrix new_matrix(d1, d2);
        new_matrix.inputMatrix();
        matrices.push_back(new_matrix);
    }
    else if (mainCommand == "sum" || mainCommand == "subtract" || mainCommand == "product" || mainCommand == "multk") {
        int idx1 = stoi(command[1]), idx2 = stoi(command[2]);
        if (!(0 <= idx1 && idx1 < matrices.size() || 0 <= idx2 && idx2 < matrices.size() )) return -1;
        if (mainCommand == "sum")
            addMatrices(matrices[idx1], matrices[idx2], false);
        else if (mainCommand == "subtract")
            subMatrices(matrices[idx1], matrices[idx2], false);
        else if (mainCommand == "product")
            prodMatrices(matrices[idx1], matrices[idx2], false);
        else if (mainCommand == "multk")
            multkMatrix(matrices[idx1], idx2, false);
    }
    else if (mainCommand == "show" || mainCommand == "inv" || mainCommand == "det") {
        int idx1 = stoi(command[1]);
        if (!(0 <= idx1 && idx1 < matrices.size())) return -1;
        
        if (mainCommand == "show")
            matrices[idx1].showMatrix();
        
        else if (mainCommand == "inv")
            invMatrix(matrices[idx1], false);

        else if (mainCommand == "det"){}
    }

    return 0;
}