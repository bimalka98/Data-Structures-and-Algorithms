// Heap Sort
#include <bits/stdc++.h>
using namespace std;

const int arraySize = 10; // We have a fixed size array
int heapSize = 7; // But variable size heap


void swap(int* array, int index1, int index2){
  int tempvar = array[index1];
  array[index1] = array[index2];
  array[index2] = tempvar;
}
/*
the LEFT procedure can compute 2i in one instruction by simply shifting
the binary representation of i left by one bit position. Similarly, the
RIGHT procedure can quickly compute 2i +1 by shifting the binary representation
of i left by one bit position and then adding in a 1 as the low-order bit. The
PARENT procedure can compute bi=2c by shifting i right one bit position
*/
inline int parent(int node) {return (node >> 1);} //parent node index
inline int left(int node) {return (node << 1);} //left child index
inline int right(int node) {return (node << 1)+1;} //right child index
inline int at(int node) {return (node-1);} // To use heap's default indexing

void insertKey(int* array, int key){ // Insert a key to a max heap
 if(heapSize <= arraySize){
   int node = heapSize+1;
   array[at(node)] = key;//insert the new member at the last free position
   while( array[at(parent(node))] < array[at(node)])
   {
     swap(array, at(node), at(parent(node))); // swap nodes if required
     node = parent(node);
   }
   heapSize++;
 }
}

void maxHeapify(int* array, int node){ // Preserve heap property
  int l = left(node);
  int r = right(node);
  int largest = node;

  // swap node with the largest child
  if( l <= heapSize && array[at(l)] > array[at(node)]) largest = l;
  else if (r <= heapSize && array[at(r)] > array[at(largest)]) largest = r;

  if (largest != node){
    swap(array,at(node), at(largest));
    maxHeapify(array, largest);
  }
}

void deleteRoot(int* array){ //Remove root from the heap
  //int root = array[at(1)]; // storing root for future use
  //Last elemeny of the heap comes to the root's place
  // array[at(1)] = array[at(heapSize)];
  swap(array, at(1), at(heapSize));//the same result can be achieved by this
  //Preserving heap properties
  maxHeapify(array,1);
  heapSize--;

}



int main(){

int  Heap[arraySize] = {50,30,20,15,10,8,16};
for(int x: Heap) cout << x << ' ';
cout << '\n' << heapSize << '\n';

deleteRoot(Heap);
for(int x: Heap) cout << x << ' ';
cout << '\n' << heapSize << '\n';

}
