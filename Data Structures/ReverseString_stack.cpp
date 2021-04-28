#include<iostream>
#include <stack>
#include <string.h>
using namespace std;


// time complexity is O(n);
// Space complexity is O(n);
void reverseString(char *C, int n){
    stack<char> charStack;
    for(int i =0; i < n; i++) charStack.push(C[i]); // filling the stack

    for(int i =0; i < n; i++) { // emptying the stack
      C[i] = charStack.top();
      charStack.pop();
    }
}

// there are better algorithms for this.
// Time complexity = O(n/2) = O(n)
// Space complexity =O(1); cuz we use constant memory
void reverseStringNew(char* C, int n){
  int i = 0;
  int j = n -1;
  while (i<j) { // n/2 swaps are there:
    char temp = C[i];
    C[i] = C[j];
    C[j] = temp;
    i++;j--;
  }
}





int  main(){
  char name[7] = {'B','i','m','a','l','k','a'};
  cout << name << '\n';
  reverseStringNew(name, strlen(name));
  cout << name << '\n';
}
