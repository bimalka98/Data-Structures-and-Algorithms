#include<iostream>
#include <queue>
using namespace std;

//==============================================================================
//dynamically crerated nodes are used to store
// Node = binary search tree
struct Node
{
    int data;
    // char data;
    Node*  leftChild;
    Node* rightChild;
};
//==============================================================================
// function to crate new nodes
Node* getNode(int x){
  Node* newNode = new Node();
  newNode->leftChild = NULL;
  newNode->data = x;
  newNode->rightChild = NULL;
  return newNode;
}
//==============================================================================
Node* insert(Node* root, int data){
  if(root == NULL) {
    root = getNode(data);
  }
  else if(data <= root->data){
    root->leftChild = insert(root->leftChild, data);
  }
  else{
    root->rightChild = insert(root->rightChild, data);
  }
  return root;
}
//==============================================================================
// search an element in the tree
bool search(Node* root, int data){
  if(root == NULL) return false;
  else if(root->data == data) return true;
  else if(data <= root->data) return search(root->leftChild, data);
  else return search(root->rightChild, data);
}
//==============================================================================
//Find min and max of a tree
int findMin(Node* root){ // root is passes as a local variable
  if(root == NULL){
    cout << "Error: Tree is empty";
    return -1;
  }

  while(root->leftChild != NULL){
    root = root->leftChild;
  }
  return root->data;
}

int findMax(Node* root){  // root is passes as a local variable
  if(root == NULL){
    cout << "Error: Tree is empty";
    return -1;
  }

  while(root->rightChild != NULL){
    root = root->rightChild;
  }
  return root->data;
}
//==============================================================================
//Find min and max of a tree recursively
int findMinRecursively(Node* root){ // root is passes as a local variable
  if(root == NULL){
    cout << "Error: Tree is empty";
    return -1;
  }
  else if(root->leftChild == NULL) return root->data;
  //search in the left subtree
  return findMinRecursively(root->leftChild);
}

int findMaxRecursively(Node* root){ // root is passes as a local variable
  if(root == NULL){
    cout << "Error: Tree is empty";
    return -1;
  }
  else if(root->rightChild == NULL) return root->data;
  //search in the right subtree
  return findMaxRecursively(root->rightChild);
}

//==============================================================================
//Find height of a binary tree
// height  = numbeer of edges in longest path from root to a leaf node
int findHeight(Node* root){
  if(root == NULL) return -1; // heght of an empty tree is -1 definition.
  int leftHeight  = findHeight( root->leftChild);
  int rightHeight = findHeight(root->rightChild);
  return max(leftHeight, rightHeight) +1;
}

//==============================================================================
// Tree traversal:
/*
 Depth first:
            Preorder traversal  -> node first
            Inorder traversal   -> node middle - gives the sorted list for binary s.t
            Postorder traversal -> node last

 Breadth first: level order -> visit all the nodes in a given level before moving to the next level

*/
void traverseBreadthFirst(Node* root){
  if(root == NULL) return;
  queue<Node*> Q;
  Q.push(root);
  while(!Q.empty()){
    Node* current = Q.front();//enqueue
    cout << current->data << '\n';
    if(current->leftChild !=NULL)  Q.push(current->leftChild);
    if(current->rightChild !=NULL)  Q.push(current->rightChild);
    Q.pop();//dequeue
  }
}

void traverseDepthFirstPreOrder(Node* root){
  if(root==NULL) return;
  cout << root->data << '\t';
  traverseDepthFirstPreOrder(root->leftChild);
  traverseDepthFirstPreOrder(root->rightChild);
}

//==============================================================================
int main(){
  Node* root = NULL;
  root = insert(root, 15);
  root = insert(root, 10);
  root = insert(root, 20);
  root = insert(root, 8);
  root = insert(root, 12);
  root = insert(root, 17);
  root = insert(root, 25);
  cout << search(root,5) <<'\n';
  cout << search(root,10) <<'\n';
  cout << "Max is: "<< findMax(root) << '\n';
  cout << "Min is: "<< findMin(root) << '\n';
  cout << "Height is: " << findHeight(root) << '\n';
  traverseBreadthFirst();

}
