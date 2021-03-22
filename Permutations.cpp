#include "Permutations.h"
#include <sys/time.h>
#include <time.h>
#include <stdio.h>
#include <cstring>
#include <stdlib.h>  /*  for malloc */
#include "Time.h"
#include <algorithm>

void Permutations::BruteForce() {

    long i;
    struct timeval * t;
    t = (struct timeval *)malloc(sizeof(struct timeval));
    gettimeofday(t,NULL);
    time_t startSec = t->tv_sec;    
    printf("seconds = %d microseconds = %d\n",t->tv_sec - startSec,t->tv_usec); 
 
   std::cout << "--Brute Force Approach--" << std::endl;
   std::cout << "cities: " << getNumberOfCities() << std::endl;
   std::cout << "Optimal Cost: " << getFactorial(getNumberOfCities() - 1) << std::endl;
   

   int permutations[getNumberOfCities() -1] = {};
   int bestPermutations[getNumberOfCities() -1] = {};
   double bestTour = 0;
   double tour = 0;


   double distances = 0;
   for(int i =0; i < getNumberOfCities(); i++) {

       permutations[i] = i + 1;


   }
  
   bestTour += cities[0][permutations[0]];
   for(int i=0; i<getNumberOfCities(); i++) {

       bestTour += cities[permutations[i-1]][permutations[i]];
   }
   
   bestTour += cities[permutations[getNumberOfCities()]][0];
   
   do {

       tour = 0;
      
       tour += cities[0][permutations[0]];
       std::cout << cities[0][permutations[0]] << " + ";
       for(int i=1; i < getNumberOfCities(); i++) {

           tour += cities[permutations[i-1]][permutations[i]];
           std::cout << cities[permutations[i-1]][permutations[i]] << " + ";
           
       }
       
       tour += cities[permutations[getNumberOfCities()]][0];
       std::cout << cities[permutations[getNumberOfCities()]][0] << " = ";
       for(int i =0;i < getNumberOfCities(); i++) {
           std::cout << permutations[i] << ' ';

       }
       if(tour < bestTour) {


           bestTour = tour;

           std::cout << "\nPermutations " ;
           for(int i =0; i < getNumberOfCities();i++) {

               bestPermutations[i] = permutations[i];
               std::cout << bestPermutations[i] << " ";
           }
           //std::memcpy(bestPermutations, permutations, sizeof(bestPermutations));
       }

   
       std::cout << " = " << tour << std::endl;
       std::cout << std::endl;
   } while ( std::next_permutation(permutations, permutations+getNumberOfCities()));


   
   std::cout << "\nTime: "; 
   gettimeofday(t,NULL);
   std::cout << t->tv_sec - startSec << "seconds\n" << std::endl;;

   for(int i=0; i <= getNumberOfCities()-1; i++) {

       std::cout  << bestPermutations[i] << " ";


   }
  

   std::cout << bestTour << std::endl;
   std::cout << std::endl;

}

void Permutations::RunProgram() {

 /*   long i;
    struct timeval * t;
    t = (struct timeval *)malloc(sizeof(struct timeval));
    gettimeofday(t,NULL);
    time_t startSec = t->tv_sec;    
    printf("seconds = %d microseconds = %d\n",t->tv_sec - startSec,t->tv_usec); 
 */

    // Running Brute force and GA algo from here along with getting users
    // parameters for the program
    int userInputInt;
    std::string userInputString;

    std::cout << "      This Program will a number of cities you would like to simulate the\n"
              <<    "and run both a brute force algorithm and a Genetic Algorithm and evaluate\n"
              <<    "which of these are more optimal to do when your dealing with a number of \n"
              <<    "cities betweens 1 and 20. Please select the parameters youd like for this\n"
              <<    "program." << std::endl;

    std::cout << "\n\n How many cities would you like to run(between 1 and 20): ";
    std::cin >> userInputInt;
    setNumberOfCities(userInputInt);

    std::cout << "How many tours per generation would you like: ";
    std::cin >> userInputInt;
    setNumberOfTours(userInputInt);

    std::cout << "How many generations would you like to run: ";
    std::cin >> userInputInt;
    setNumberOfGenerations(userInputInt);


    std::cout << "What percentage of the generation should be comprised of mutations: ";
    std::cin >> userInputInt;
    setMutationPercentage(userInputInt);

   

    // Brute force Method
    

    BruteForce();
    // Generation Algorithm



    /*
    gettimeofday(t,NULL);
    printf("Final: seconds = %d microseconds = %d\n",t->tv_sec - startSec,t->tv_usec); 
    */

}
int Permutations::getMutationPercentage() {

    return this->mutationPercentage;
}
int Permutations::getNumberOfGenerations() {

    return this->numberOfGenerations;

}
int Permutations::getNumberOfTours(){

    return this->numberOfTours;

}
int Permutations::getNumberOfCities() {

    return this->numberOfCities;
}
void Permutations::setMutationPercentage(int mutationPercentage) {

    this->mutationPercentage = mutationPercentage;
}
void Permutations::setNumberOfGenerations(int gens){

   this->numberOfGenerations = gens; 
}

void Permutations::setNumberOfTours(int tours){

    this->numberOfTours = tours;

}
void Permutations::setNumberOfCities(int cities) {

    this->numberOfCities = cities;
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
