// next_permutation example
#include <iostream>     // std::cout
#include <algorithm>    // std::next_permutation, std::sort

int main () {
  int myints[] = {1,2,3,4,5,6};

  std::sort (myints,myints+6);

  std::cout << "The 3! possible permutations with 3 elements:\n";
  do {
    std::cout  << myints[0] << ' ' << myints[1] << ' ' << myints[2] << ' ' << myints[3] << ' ' << myints[4] << ' ' << myints[5] << '\n';
  } while ( std::next_permutation(myints,myints+6) );

  std::cout << "After loop: " << myints[0] << ' ' << myints[1] << ' ' << myints[2] << ' ' << myints[3] << ' ' << myints[4] << ' ' << myints[5]<< '\n';

  return 0;
} 
