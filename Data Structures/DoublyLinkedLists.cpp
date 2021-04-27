//==========================doubly linked lists=================================

/*
 * Author : Bimalka Piyaruwan Thalagala
 * GitHub : https://github.com/bimalka98
 */
 
// advantags : reverse look up due to previus address
// each node consists of three fields

#include <iostream>
using namespace std;
//==============================================================================

struct Node
{
    int data;
    Node *next;
    Node *prev;
};
//==============================================================================
Node* head = NULL; // headpointer: the pointer to the first node


//==============================================================================
// nodes created using normal function calls will be in stack memory and will be
// deleted when the function returns to its parent function. this happens
// automatically
// therefore we use heap memory(dynamic memory) allocation for nodes creation.

Node* getNewNode(int x){
  Node* node = new Node(); // reserve memory in the heap
  node->prev = NULL;
  node->data = x;
  node->next = NULL;
  return node;
}
//==============================================================================
void insertAtBeginning(int x){
  Node* temp = getNewNode(x); // creating a whole new node in the heap

  if(head == NULL){ // if linked list is empty
    head = temp;
    return;
  }
  head->prev = temp;//          temp           head
  temp->next = head;//      |prev|2|next| |prev|4|next|
  head = temp;
}
//==============================================================================
// we need to first find the tail of the list
void insertAtTail(int x){
  Node* node = getNewNode(x); // creating a whole new node in the heap

  if(head == NULL){ // if linked list is empty
    head = node;
    return;
  }
  Node* temp = head;
  while(temp->next != NULL) temp = temp->next; // travel to the end node

  temp->next = node;
  node->prev = temp;

}
//==============================================================================
void printList(){
  Node* temp = head; // all we know still about a linked list is pointer to its first node
  cout << "Forward: ";
  while(temp!= NULL){
    cout << temp->data << '\t';
    temp = temp->next;
  }
  cout << '\n';
}
//==============================================================================
void printReverseOrder(){
  // first we need to go to the last node
  Node* temp = head; // all we know is headpointer to first node
  if(temp==NULL) return;
  while(temp->next != NULL) temp = temp->next; // travel to the end node of the list

  cout << "Backward: ";
  while(temp != NULL){
    cout << temp->data << '\t';
    temp = temp->prev;
  }
  cout <<'\n';
}
//==============================================================================
int main(){
  insertAtTail(2);   //2
  insertAtTail(8);   //8,2
  insertAtTail(10);  //10,8,2
  insertAtTail(6);   //6,10,8,2

  printList();
  printReverseOrder();

}
