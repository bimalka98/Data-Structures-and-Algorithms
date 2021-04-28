#include<iostream>
#include <stack>
#include <string.h>
using namespace std;

// no worries about overflow
struct Node
{
    int data;
    Node *next;
};
//==============================================================================
// Initializing a pointer to the top Node as null: an empty linked list
Node* head = NULL;

void reverseLinkedList(){
  if(head == NULL) return;

  stack<Node*> pointerStack; // data type of the stack is a pointer to a node
  Node* temp = head;
  while (temp != NULL) {
    pointerStack.push(temp); // pushing pointers
    temp = temp->next;
  }
  // top of the stack has the pointer to the last node
  temp = pointerStack.top(); // new head is the last node; top of the stack
  head = temp;
  pointerStack.pop(); // removing last node

  while(!pointerStack.empty()){
    temp->next = pointerStack.top();
    pointerStack.pop();
    temp = temp->next;
  }
  temp->next = NULL; // last node points to null. we need to set this manually.
}
//==============================================================================
// fucntion to insert at the beginning of the linked list
// time complexity  = O(1) = constant time
void insertAtBeginning(int x){
  Node*  temp = new Node(); // Initializing a node
  temp->data = x;     // add data to the node
  temp->next = head;  // this node must point to the previous first node
  head = temp;        // this new node becomes the fisrt node now.
}
//==============================================================================
void printList(){
  // low memory requirement
  // How to travel to the end of the linked list
  // linked list traversal method
  Node* temp = head;    // pointer to the head; that's all we know
  while(temp != NULL){  // And last node points to NULL pointer.
    cout << temp->data << '\t';
    temp = temp->next;
  }
  cout << '\n';
  // Now temp has the pointer to the last node;
}

int  main(){
  insertAtBeginning(5);
  insertAtBeginning(8);
  insertAtBeginning(4);
  insertAtBeginning(7);
  printList();
  reverseLinkedList();
  printList();
}
