#include <bits/stdc++.h>
using namespace std;


int bin_search(int *sorted_arr, int query ,int left, int right); // binary search function declaration

int main() {

    int len_array, num_queries;
    cin >> len_array >> num_queries; // getting numbers of inputs

    int Sorted_array[len_array];
    for(int i = 0; i < len_array; i++) cin >> Sorted_array[i]; // getting the sorted array's elemnts

    int Queries[num_queries];
    for(int i = 0; i < num_queries; i++) cin >> Queries[i]; // getting the queries to check

    int indexes[num_queries];
    for(int i =0; i < num_queries; i++) indexes[i] = bin_search(Sorted_array, Queries[i], 0, len_array-1); // searching the array for a query

    for(int ind: indexes) cout << ind << '\n'; // printing out the indexes of queries
    return 0;
}

int bin_search(int *sorted_arr, int query ,int left, int right){ // binary search implementation

    if (left <= right){ // if the element may present in the array sub arrays must have valid indexes

        int middle = (left + right)/2; // get the middle index of the array

        // if the element is present at the middle
        if (sorted_arr[middle] == query) return middle;

        // if the element is present in the left sub array
        else if (sorted_arr[middle] > query) return bin_search(sorted_arr, query ,left, middle-1);

        // if the element is present in the right sub array
        else return bin_search(sorted_arr, query ,middle+1,right);
        }

    return -1; // if the element is not in the array return -1

}
