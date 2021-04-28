#include<iostream>
using namespace std;

#define length 10
int array[length];
int front = -1;
int rear = -1;

inline bool isQEmpty(){ return (front==-1)? true:false;}
inline bool isQfull() { return (rear=length-1)? true:false;}

// Circular array implementation of the queues
void enqueue(int x){
  // if (isQfull()){
  //   cout << "Queue is full.\n";
  //   return;
  // }
  if ((rear+1)%length == front){
    cout << "Queue is full.\n";
    return;
  }
  else if(isQEmpty()){
    front = 0; rear = 0;
  }
  // else rear++;
  else rear = (rear+1)%length;
  array[rear] = x;
}

void dequeue(){
  if(isQEmpty()){
    cout << "Queue is empty.\n";
    return;
   }
   else if(front==rear){
     front = -1;
     rear = -1;
   }
   // else front++;
   else front = (front+1)%length; //just change the pointer to th front
}

void printQueue(){
  for(int i = front; i < rear+1; i++){
    cout << array[i] << '\t';
  }
  cout << '\n';
}


int main(){
enqueue(5); enqueue(10); enqueue(15); enqueue(20); enqueue(25); enqueue(30);
enqueue(35); enqueue(40); enqueue(45); enqueue(50); enqueue(8); enqueue(7);

printQueue();
dequeue(); dequeue();
printQueue();
}
