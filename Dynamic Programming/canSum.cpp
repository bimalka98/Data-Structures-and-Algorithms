#include <bits/stdc++.h>
using namespace std;

/*
// all inputs are non negative
// any element can be use any times
bool canSum(int targetsum, vector<int> & array){
// time complexity = O(m^n) m -target sum, n -lenght of array.
// space complexity = O(m)
// canSum(7, [5,3,4,7]) --> true
if(targetsum ==0) return true;
if(targetsum < 0) return false;
//at least one element returns true it will be enough
for(int i =0; i < array.size();i++){
  int remainder = targetsum - array[i];
  if(canSum(remainder, array)==true) return true;
}
return false;
}
*/

// optimization using Memoization
bool canSum(int targetsum, vector<int> & array, std::map<int, bool> &memo){
// time complexity = O(m^n) m -target sum, n -lenght of array.
// space complexity = O(m)
// canSum(7, [5,3,4,7]) --> true
if(memo[targetsum]) return memo[targetsum];
if(targetsum ==0) return true;
if(targetsum < 0) return false;

//at least one element returns true it will be enough
for(int i =0; i < array.size();i++){
  int remainder = targetsum - array[i];
  if(canSum(remainder, array, memo)==true) {
    memo[targetsum] = true;
    return memo[targetsum];}
}
memo[targetsum] = false;
return false;
}

int main(){

vector<int> array = {4,7,8,65,3,2};
std::map<int, bool> memo;

// *max_element(arr, arr + n); returns a pointer. need to convert *;
cout << canSum(31503,array, memo) << '\n';


}
