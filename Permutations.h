#ifndef _permutations_h_
#define _permutations_h_
#include <iomanip>
#include <fstream>
#include <iostream>
using namespace std;

class Permutations { 

    public:

        Permutations() {
            distances.open("distances.txt");
            if(!distances.is_open()) {
                std::cout << "Unable to open that file!" << std::endl;
            } else {
                double city;
                for(int i = 0; i <= 19; i++) {
                    for(int j = 0; j <= 19; j++) {
                        if(i == j) {
                            cities[i][j] = 0;
                            std::cout << std::setw(6) << cities[i][j] << " ";
                        } else {
                            distances >> city;
                            cities[i][j] = city;
                            std::cout << std::setw(6) << cities[i][j] << " ";
                        }
                    }
                    std::cout << std::endl;
                }
            }
        }

        int getNumberOfCities();
        int getNumberOfTours();
        int getNumberOfGenerations();
        

        void setNumberOfGenerations(int gens);
        void setNumberOfTours(int tours);
        void setNumberOfCities(int cities);
        unsigned long long getFactorial(int x);

    private:

        double cities[20][20];
        std::ifstream distances;
};

#endif
