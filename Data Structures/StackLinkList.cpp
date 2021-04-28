//=================================Stacks=======================================

/*
 * Author : Bimalka Piyaruwan Thalagala
 * GitHub : https://github.com/bimalka98
 */

#include <iostream>
using namespace std;
//=============================Stacks using Linked lists========================
// no worries about overflow
struct Node
{
    int data;
    Node *next;
};
//==============================================================================
// Initializing a pointer to the top Node as null: an empty linked list
Node* top = NULL;

// linked lists takes O(n) to add/ delete a new node at the end.
// but stacks must operate in O(1) time complexity.
// Anyway linked lists takes O(1) to add/ delete a new node at the beginning.

void push(int x){
  Node* node = new Node(); // memeory allocation in the dynamic memory
  node->data =  x;
  node->next = top;
  top = node;
}

void pop(){
  Node* temp = top;
  if(top == NULL) return;
  top = top->next;
  delete temp;
}

void printStack(){
  Node* temp = top;
  while(temp!= NULL){
    cout << temp->data << '\t';
    temp = temp->next;
  }
  cout << '\n';
}
//==============================================================================
int main(){
  push(5);push(3);push(4);push(9);
  printStack();
  pop();
  printStack();
  return 0;
}
