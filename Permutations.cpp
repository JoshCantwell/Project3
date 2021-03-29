#include "Permutations.h"
#include <sys/time.h>
#include <time.h>
#include <stdio.h>
#include <cstring>
#include <stdlib.h>  /*  for malloc */
#include "Time.h"
#include <algorithm>
#include <vector>
void Permutations::BruteForce() {

    long i;
    struct timeval * t;
    t = (struct timeval *)malloc(sizeof(struct timeval));
    gettimeofday(t,NULL);
    time_t startSec = t->tv_sec;    
    //printf("seconds = %d microseconds = %d\n",t->tv_sec - startSec,t->tv_usec); 
 
   std::cout << "\n\n--Brute Force Approach--" << std::endl;
   std::cout << "cities: " << getNumberOfCities() << std::endl;
   std::cout << "Optimal Cost: " << getFactorial(getNumberOfCities() - 1) << std::endl;
   

   int permutations[getNumberOfCities()] = {};
   int bestPermutations[getNumberOfCities()] = {};
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
  
   //std::cout << "test" << std::endl;
   
   bestTour += cities[permutations[getNumberOfCities() - 1]][0];
   do {

       tour = 0;
      
       tour += cities[0][permutations[0]];
       //std::cout << cities[0][permutations[0]] << " + ";
       for(int i=1; i < getNumberOfCities(); i++) {

         
           tour += cities[permutations[i-1]][permutations[i]];
       //    std::cout << cities[permutations[i-1]][permutations[i]] << " + ";
           
       }
       
       tour += cities[permutations[getNumberOfCities()-1]][0];
       //std::cout << cities[permutations[getNumberOfCities()]][0] << " = ";
       /*for(int i =0;i < getNumberOfCities(); i++) {
           std::cout << permutations[i] << ' ';

       }*/
       if(tour < bestTour) {


           bestTour = tour;

           //std::cout << "\nPermutations " ;
           for(int i =0; i < getNumberOfCities();i++) {

               bestPermutations[i] = permutations[i];
               //std::cout << bestPermutations[i] << " ";
           }

           //std::memcpy(bestPermutations, permutations, sizeof(bestPermutations));
       }

   
       //std::cout << " = " << tour << std::endl;
       //std::cout << std::endl;
   } while ( std::next_permutation(permutations, permutations+getNumberOfCities()));


   
   std::cout << "Time: "; 
   gettimeofday(t,NULL);
   std::cout << t->tv_sec - startSec << "seconds\n" << std::endl;;

   for(int i=0; i <= getNumberOfCities() - 1; i++) {

       std::cout  << bestPermutations[i] << "  ";


   }
  

   std::cout << "= ";
   std::cout << bestTour << std::endl;
   std::cout << std::endl;

}

void Permutations::GeneticAlgorithm() {


    long i;
    struct timeval * t;
    t = (struct timeval *)malloc(sizeof(struct timeval));
    gettimeofday(t,NULL);
    time_t startSec = t->tv_sec;    
    //printf("seconds = %d microseconds = %d\n",t->tv_sec - startSec,t->tv_usec); 
 
   std::cout << "\n\n--Genetic Algorithm Approach--" << std::endl;
   std::cout << "cities: " << getNumberOfCities() << std::endl;
   std::cout << "Optimal Cost: " << getNumberOfGenerations() * getNumberOfTours() << std::endl;
   

   int permutations[getNumberOfCities()] = {};
   int mutationPermutations[getNumberOfCities()] = {};
   double eliteone = 1000;
   double elitetwo = 1000;

   

   std::vector < std::vector<int> > tours;

   std::vector < std::vector<int> > tempTours;
   std::vector < int > cities;
   std::vector <int> eliteOne;
   std::vector <int> eliteTwo;


   double distances = 0;
   
   for(int i =0; i < getNumberOfCities(); i++) {

       permutations[i] = i + 1;


   }
   for(int i =0; i < getNumberOfCities();i++) {

       mutationPermutations[i] = i + 1;

   }

   // Initial generation

   for(int i =0; i < getNumberOfTours(); i++) {

       for(int j = 0; j < getNumberOfCities(); j++) {
           
           cities.push_back(permutations[j]);
   
       }
       tours.push_back(cities);
       cities.clear();

       std::next_permutation(permutations, permutations+getNumberOfCities());

   }
/*
   for(int i = 0; i < tours.size(); i++) {
       for(int j = 0; j < tours[i].size(); j++) {
           std::cout << tours[i][j] << "  ";
       }
       std::cout << std::endl;
   }
*/




   float mutperc = getMutationPercentage()/100.0;
   int mutations = mutperc  * getNumberOfTours();;
   int w = 0;
   do{

       //std::cout << "Generation " << w << " " << std::endl;
       
       for(int i=0; i < getNumberOfTours(); i++) {
          
           double currentTour = this->cities[0][tours[i].at(0)];

           //std::cout << tours[i].at(0) << " ";
           for(int j = 1; j < tours[i].size(); j++) {
           
               currentTour += this->cities[tours[i].at(j-1)][tours[i].at(j)];
           
               //std::cout << tours[i].at(j) << " ";
           }
           currentTour += this->cities[tours[i].at(getNumberOfCities()-1)][0];

           //std::cout << " = ";
           //std::cout  << currentTour << std::endl;;
           
           
           if(currentTour < elitetwo) {
               if(currentTour < eliteone) {
                   eliteTwo = eliteOne;
                   elitetwo = eliteone;
                   eliteOne = tours[i];
                   eliteone = currentTour;
               } else if(currentTour == eliteone) {
                   
               }else {
                   eliteTwo = tours[i];
                   elitetwo = currentTour;
               }

           }

       }

       //std::cout << "\n" << elitetwo << " " << eliteone << std::endl;

       tempTours.push_back(eliteOne);
       tempTours.push_back(eliteTwo);
   
       for(int i =2; i < getNumberOfTours() -mutations; i++) {
       
           for(int j = 0; j < getNumberOfCities() ; j++) {
           
               cities.push_back(permutations[j]);
              // std::cout << permutations[j] << " ";
           }
           //std::cout << std::endl;
           tempTours.push_back(cities);
           cities.clear();
           std::next_permutation(permutations, permutations+getNumberOfCities());
       }
       for(int i =0; i < getFactorial(getNumberOfCities() - (getNumberOfTours()*getNumberOfGenerations())); i++) {

           std::next_permutation(mutationPermutations, mutationPermutations+getNumberOfCities());
       }
      

       //std::cout << mutations << std::endl;
       for(int i =0; i <  mutations; i++) {
      
           for(int j = 0; j < getNumberOfCities() ; j++) {
           
               cities.push_back(mutationPermutations[j]);
               //std::cout << mutationPermutations[j] << " ";
           }
           //std::cout << std::endl;
           tempTours.push_back(cities);
           cities.clear();
           std::next_permutation(mutationPermutations, mutationPermutations+getNumberOfCities());
       }




       tours.clear();
       tours = tempTours;
  
       tempTours.clear();
       w++;

   }while(w < getNumberOfGenerations());

   std::cout << "Time: "; 
   gettimeofday(t,NULL);
   std::cout << t->tv_sec - startSec << "seconds\n" << std::endl;;
/*
   for(int i=0; i <= getNumberOfCities() - 1; i++) {

       std::cout  << bestPermutations[i] << "  ";


   }


   std::cout << "= ";
   std::cout << bestTour << std::endl;
   std::cout << std::endl;

*/

   for(int i = 0; i < eliteOne.size();i++) {

       std::cout << eliteOne.at(i) << " ";
   }

   std::cout << "= " << eliteone << std::endl;

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

    std::cout << "\n\n      This Program will a number of cities you would like to simulate the\n"
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
    GeneticAlgorithm();



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
