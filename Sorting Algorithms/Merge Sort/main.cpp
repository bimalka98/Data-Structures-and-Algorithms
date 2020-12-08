#include <bits/stdc++.h>
using namespace std;

 // begin = array.begin() = 0
 // end = array.end() = 8
 // middle = 4
 // [0,1,2,3,4,5,6,7,8] n1 = 4-0 +1 = 5; n2 = 8-4 = 4;

 void mergeF(int* primary_array, int begin, int middle, int end) {
   int n1 = middle - begin +1;
   int n2 = end -middle;

   // Creating arrays to store lements temporarily
   int* left_array[n1], *right_array[n2];

   // copying data into temp arrays from the original array
   for(int i = 0; i < n1;i++) left_array[i] = primary_array[begin + i];
   for(int j = 0; j< n2; j++) right_array[j] = primary_array[middle+1 +j];

   // Initializing temporarily variables
   int i = 0;
   int j = 0;
   // left_array = [0,1,2,3,4]
   // right_array = [5,6,7,8]
   for(int k = begin; k < end; k++){
     if (left_array[i] <= right_array[j]){
       primary_array[k] = left_array[i];
       i++;
     } else{
       primary_array[k] = right_array[j];
       j++;
     }
   }
 }

 void mergeSortF(int *array[], int left, int right){
   if(left < right){
     int middle = (left + right)/2;
     mergeSortF(array, left, middle);
     mergeSortF(array, middle +1 , right);
     mergeF(array, left, middle, right);
   }
 }


 int main() {

 int arr[] = {6,5,8,9,4,3,2,8,4,6};
 int len = sizeof(arr) / sizeof(int);

 cout << "Unsorted array : ";
 for(int x: arr) cout << x << ' ';
 cout << '\n';

 //mergeSortF(arr, 0, len -1);

 cout << "sorted array : ";
 for(int x: arr) cout << x << ' ';
 cout << '\n';

 return 0;
 }
