// Binary Search Algorithm

// The Algorithm : Narrows the Search by a Factor of Two at Each Iteration
// BINARY_SEARCH(List, Key)
//   if length of the List is 0
//     Return false
//   else if the middle element is equal to Key
//     return true/ return index
//   else if the Key is less than the middle element
//     BINARY_SEARCH(First Half of the List, Key)
//   Else
//     BINARY_SEARCH(Second Half of List, Key)

#include <bits/stdc++.h>
using namespace std;
int bin_search(int *sorted_list, int begin, int end, int key){
  if (end < begin) return -1;
  else {
    int middle = (begin + end)/2;
    if(sorted_list[middle] == key) {
       return middle;}
    else if (sorted_list[middle] > key){
       return bin_search(sorted_list, begin, middle-1, key);}
    else {
       return bin_search(sorted_list, middle+1, end, key);}
  }
}

int main(){
  int a[7] = {1,2,3,4,5,6,7};
  cout << bin_search(a, 0, (sizeof(a)/sizeof(int)-1), 5);
}
