#include "Permutations.h"

void Permutations::RunProgram() {

    // Running Brute force and GA algo from here along with getting users
    // parameters for the program
    int userInputInt;
    std::String userInputString;

    std::cout << "      This Program will a number of cities you would like to simulate the\n
                  and run both a brute force algorithm and a Genetic Algorithm and evaluate\n
                  which of these are more optimal to do when your dealing with a number of \n
                  cities betweens 1 and 20. Please select the parameters youd like for this\n
                  program." << std::endl;

    std::cout << "\n\n How many cities would you like to run: ";

    std::cin >> userInputInt << std::endl;
    

}

unsigned long long Permutations::getFactorial(int x) {

    unsigned long long factorial = 1;
    if(x < 0) {

    } else {

        for(int i =1; i <=x; i++) {

            factorial *= i;
        }
    }

    return factorial;

}
