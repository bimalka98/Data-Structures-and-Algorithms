//=================================Stacks using arrays==========================

/*
 * Author : Bimalka Piyaruwan Thalagala
 * GitHub : https://github.com/bimalka98
 */

#include <iostream>
using namespace std;

// =============================Stacks using arrays=============================
// Global variable definitions
#ifndef MAX_SIZE
#define MAX_SIZE 101
#endif
int array[MAX_SIZE];
int top  = -1;

//==============================================================================
void push(int x){
  if(top== MAX_SIZE -1){
    cout << "Error: Stack Overflow.\n";
    return;
  }
  array[++top] = x;
}
//==============================================================================
void pop(){
  if(top == -1){
    cout << "Error: Stack is empty\n";
    return;
  }
  top--;
}
//==============================================================================
/* source: https://www.geeksforgeeks.org/inline-functions-cpp/
 * Execution time of small function is less than the switching time.
 * C++ provides an inline functions to reduce the function call overhead.
 * Inline function is a function that is expanded in line when it is called.
 * When the inline function is called whole code of the inline function gets
 * inserted or substituted at the point of inline function call.
 * This substitution is performed by the C++ compiler at compile time.
 * Inline function may increase efficiency if it is small.
 */

inline int Top(){return array[top];}

//==============================================================================
void printStack(){
  for(int i = 0; i <= top; i ++) cout << array[i] << '\t';
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
