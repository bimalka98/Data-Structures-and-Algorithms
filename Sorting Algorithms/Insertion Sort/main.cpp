#include <iostream>
#include <string>

int main() {

  // Taking the number of elements in the array
  int numkeys;
  std::cout << "Enter the number of keys in array: ";
  std::cin >> numkeys;

  // Initializing an array to hold the elements(keys) and taking inputs
  int *array;
  array = new int [numkeys];
  for (int i = 0; i < numkeys; i++) std::cin >> array[i];

  // Printing the unsorted array to teminal
  std::cout << "[ " ;
  for (int i = 0; i < numkeys; i++) std::cout << array[i]  << ' ';
  std::cout << "]" << '\n';

  // Insertion sorting algorithm
  for (int i = 1; i < numkeys; i++) {
    int key = array[i];
    int j = i-1;
    while (j>=0 && array[j] > key) {
      array[j+1] = array[j];
      j-=1;
    }
    array[j+1] = key;
  }

  // Printing the sorted array
  std::cout << "[ " ;
  for (int i = 0; i < numkeys; i++) std::cout << array[i]  << ' ';
  std::cout << "]" << '\n';

  return 0;
}

// Ref : https://www.sanfoundry.com/cpp-program-implement-variable-length-array/
