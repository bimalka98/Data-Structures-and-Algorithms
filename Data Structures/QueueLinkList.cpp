#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};
//==============================================================================
// Initializing a pointer to the top Node as null: an empty linked list
Node* front = NULL;
Node* rear = NULL;

// time complexity O(1)
void enqueue(int x){ // at the end of  the linked list
  // node creation
  Node* node = new Node(); // creting nodes in dynamic memory
  node->data = x;
  node->next =NULL;

  if( front== NULL && rear == NULL ){
    front = rear = node;
    return;
  }
  rear->next = node;
  rear = node;
}

// time complexity O(1)
void dequeue(){
  Node* temp = front; // in order to free up the mem. we need a pointer to the first node;

  if(front == NULL){
    cout << "Queue is empty.\n";
    return;
  }
  if(front == rear){ //only one elemnts in queue
    front = rear = NULL;
  }
  front = front->next;
  delete temp; // free garbage memory
}

//===========
void printQueue(){
  Node* temp = front;
  while(temp!= NULL){
    cout << temp->data << '\t';
    temp = temp->next;
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
