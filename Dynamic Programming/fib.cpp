#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long



ull Fibonacci(int position, map<int ,ull> &memo){
  // time complexity = 2^n
  // space complexity = n

  // ====solution through memoization====
  if (position <=2) return 1; // base case

  // if key in memo
  if (memo.find(position) != memo.end()) return memo[position];
  // if key not in memo
  else{
    memo[position] = Fibonacci(position-1, memo) + Fibonacci(position-2, memo);
    return memo[position];
  }
}


int main(){
  // memoization- through a map data structure
  map<int ,ull> memo;
  Fibonacci(100, memo);

  map<int ,ull >:: iterator  it=memo.begin();
  for(; it!=memo.end(); it++){
    cout << it->first << " " << it->second << '\n';
  }
}
