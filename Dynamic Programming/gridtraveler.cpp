#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;

// Recursive approach
// time complexity 2^(m+n)
/*
int gridTraveler(int m, int n){
  if( m==1 && n==1) return 1;
  if( m==0 || n==0) return 0;
  return gridTraveler(m -1, n) + gridTraveler(m, n -1);
}
*/

// memoization approach to reduce time complexity
// time complexity O(m*n)
// space complexity O(m+n)
ull gridTraveler(int m, int n , std::map<string, ull > &memo){
  //defining a key containing m,n
  string key = to_string(m)+','+to_string(n);
  // if key exist in the memo
  if ( memo[key]) return memo[key];
  // base cases
  if( m==1 && n==1) return 1;
  if( m==0 || n==0) return 0;
  // if key doesnot exist
  memo[key] = gridTraveler(m -1, n, memo) + gridTraveler(m, n -1, memo);
  return memo[key];
}


//==============================================================================
int main(){
std::map<string, ull > memo;

std::cout << gridTraveler(3,3,memo) << '\n';
std::cout << gridTraveler(5,5,memo) << '\n';
std::cout << gridTraveler(18,18,memo) << '\n';


}
