//Count Dracula 1

#include <bits/stdc++.h>
using namespace std;

#include <iostream>
int main(){
    int numkeys;
    cin >> numkeys;
    int*array;
    array = new int[numkeys];
    for(int i = 0; i < numkeys; i++) std::cin >> array[i];
    // Bubble sort algorithm
    //--------------------------------------------------------------------------
    int swapps = 0;
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
                swapps+=1;
            }
        }
    }while(swapped);
    //--------------------------------------------------------------------------
    // Printing the number of swapps
    cout << swapps;
    return 0;
}
