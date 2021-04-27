//==========================singly linked lists=================================

/*
 * Author : Bimalka Piyaruwan Thalagala
 * GitHub : https://github.com/bimalka98
 */

#include <iostream>
using namespace std;

//==============================================================================
struct Node
{
    int data;
    Node *next;
};
//==============================================================================
// Initializing a pointer to the head Node as null: an empty list
Node* head = NULL;
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
//==============================================================================
// Insert a node at the middle of a linked list
void insertNodeAt(int position, int value){
  //initializ the node
  Node* node = new Node();
  node->data = value;
  node->next = NULL;

  if(position ==1){     // if the linked list is empty
    node->next = head;  // NULL pointer
    head = node;
    return;
  }

  Node* temp = head;// pointer to the head; that's all we know
  for(int i = 0; i< position -2;i++) temp = temp->next;
  // now we have the pointer to the place before the  argument position
  node->next = temp->next; // now our node points to the next node
  temp->next = node; // previous node points to our node
}
//==============================================================================
// delete a node from the linked list
void deleteNodeAt(int position){
  Node* temp = head;// pointer to the head; that's all we know
  if(position==1){
    head = temp->next; // next of the head.
    delete temp;
    return;
  }
  //pointer to the node before the nodetodelete
  for(int i = 0; i< position -2;i++) temp = temp->next;
  Node* nodetodelete = temp->next;
  temp->next = nodetodelete->next;
  delete nodetodelete;
}
//==============================================================================
// Reverse a linked list iterative method
void reverseLinkedList(){
  Node* previousNode  = NULL;
  Node* currentNode   = head;   // pointer to the head; that's all we know
  Node* nextNode      = NULL;

  while(currentNode != NULL){   // And last node points to NULL pointer.
    nextNode = currentNode->next;
    currentNode->next = previousNode;
    previousNode = currentNode;
    currentNode  = nextNode;
  }
  head = previousNode;
}
//==============================================================================
// Print a linked list using recursion
// too many memory required
void printInOrder(Node* node){
  if(node == NULL) return;
  cout << node->data <<'\t';
  printInOrder(node->next);
}
//==============================================================================
// Print a linked list using recursion in the Reverse order
// just swap the two lines of the above function
void printReverseOrder(Node* node){
  if(node == NULL) return;
  printReverseOrder(node->next);
  cout << node->data <<'\t';
}

//==============================================================================
// Reverse a linked list recursion method
void reverseLinkedListRecursively(Node* node){
  if(node->next == NULL) {// we are at the last node
    head = node;
    return;
  }
  reverseLinkedListRecursively(node->next);
  Node* temp = node->next;
  temp->next = node;
  node->next = NULL;
}

//==============================================================================
int main(){
  /*
  // code snippet to check insertAtBeginning function
  get the number of nodes
  int nodes;
  cout << "How many nodes are there? ";
  cin >> nodes;

  for(int i =0; i < nodes; i++){
    int x;
    cout << "Enter the number: ";
    cin >> x;
    insertAtBeginning(x);
    printList();
  }
  */

  // code snippet to check insertNodeAt function
  insertNodeAt(1, 9);// initializing the linked list
  insertNodeAt(2, 3);
  insertNodeAt(3, 5);
  insertNodeAt(4, 7);
  printInOrder(head);
  cout << "\n";
  printReverseOrder(head);
  return 0;
}
//==============================================================================
// int main() {
//   // creating the first nodes
//   Node* node1 = new Node();
//   node1 -> data = 2;
//   node1 -> next = NULL;
//
//   // now our linked list has one node. and we need a pointer to that HEAD node
//   head = node1;
//
//   // creating the second node
//   Node* node2 = new Node();
//   node2->data = 4;
//   node2->next =NULL;
//   // set the pointer from the fisrt node1 to the node2
//   node1->next = node2;
//
//   printList();
//   return 0;
// }
