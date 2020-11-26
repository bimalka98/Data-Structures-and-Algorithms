//  -----------------------------------------------------------------------------
//   Author               : Bimalka Piyaruwan Thalagala
//   GitHub               : https://github.com/bimalka98
//   Last Modified        : 27.11.2020
//  -----------------------------------------------------------------------------


#include <iostream>

int main(){
    int numkeys;
    std::cout << "Enter the number of keys in array : ";
    std::cin >> numkeys;

    int*array;
    array = new int[numkeys];
    for(int i = 0; i < numkeys; i++) std::cin >> array[i];
    std::cout << "\n";
    // Printing the unsorted array to teminal
    std::cout << "[ " ;
    for (int i = 0; i < numkeys; i++) std::cout << array[i]  << ' ';
    std::cout << "]" << '\n';

    // Bubble sort algorithm
    //--------------------------------------------------------------------------
    bool swapped;
    do
    {
        swapped = false;
        for (int i = 1; i < numkeys; i++)
        {
            if (array[i-1] > array[i])
            {
                int tempvar = array[i];
                array[i] = array[i-1];
                array[i-1] = tempvar;
                swapped = true;
            }
        }
    }while(swapped);
    //--------------------------------------------------------------------------
    // Printing the sorted array
    std::cout << "[ " ;
    for (int i = 0; i < numkeys; i++) std::cout << array[i]  << ' ';
    std::cout << "]" << '\n';

    return 0;
}
