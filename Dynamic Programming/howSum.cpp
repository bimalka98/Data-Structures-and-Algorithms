#include <bits/stdc++.h>
using namespace std;

vector<int> howSum(int targetSum, vector<int> &numbers, map<int, vector<int>> &memo){
  //If a combination is readily available
  if(memo.find(targetSum) != memo.end()) return memo[targetSum];
  // checking the base cases
  if(targetSum==0) return {};   // Combination exists
  if(targetSum <0) return {-1}; // No combination
  // Recursively finding the combination
  for(int i =0; i <(int)numbers.size(); i++){
    int remainder = targetSum - numbers[i];
    vector<int> combination = howSum(remainder, numbers,memo);
    if(combination != (vector<int>){-1}){
      combination.push_back(numbers[i]);
      memo[targetSum] = combination;
      return combination;
    }
  }
  memo[targetSum] = {-1}; // Add No combination into the memoization.
  return {-1}; // No combination
}

int main() {
  map<int, vector<int>> memo;
  vector<int> numbers = {2,4};

  std::vector<int> combination = howSum(7, numbers, memo);
  for(int x: combination) cout << x;
  return 0;
}
