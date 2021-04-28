// ususally run by compilers at the compile time to check syntax errors

#include<iostream>
#include <stack>
#include <string.h>
using namespace std;

char mirror(char c){
  if(c=='}') return '{';
  if(c==']') return '[';
  if(c==')') return '(';
}

bool isBalanced(string s){

  int length = s.length();
  if(length == 0) return true;

  stack<char> openings; // stack to store open brackets
  for(int i = 0; i < length; i++){
    if(s[i]=='{' || s[i]=='[' || s[i]=='(') openings.push(s[i]);

    else if(s[i]=='}' || s[i]==']' || s[i]==')'){
      if(openings.empty()) return false;
      else if(openings.top()!=mirror(s[i])) return false;
      else openings.pop();
    }
  }
  return openings.empty()? true:false;
}

int main(){
  cout << isBalanced("{[(a)]}") << '\n';
  cout << isBalanced("{[(a]}") << '\n';
}
