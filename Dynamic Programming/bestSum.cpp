#include <bits/stdc++.h>
using namespace std;

vector<int> bestSum(int targetSum, vector<int> &numbers, map<int, vector<int>> &memo){
  //If a combination is readily available
  if(memo.find(targetSum) != memo.end()) return memo[targetSum];

  // checking the base cases
  if(targetSum==0) return {};   // Combination exists
  if(targetSum <0) return {-1}; // No combination
  // Recursively finding the combination
  vector<int> shortestSum = {-1};

  for(int i =0; i <(int)numbers.size(); i++){
    int remainder = targetSum - numbers[i];
    vector<int> combination = bestSum(remainder, numbers,memo);
    if(combination != (vector<int>){-1}){
      combination.push_back(numbers[i]);
      if(combination.size() < shortestSum.size() || shortestSum == (vector<int>){-1}){
        shortestSum = combination;
      }
    }
  }
  memo[targetSum] = shortestSum;
  return shortestSum;
}

int main() {
  map<int, vector<int>> memo;
  vector<int> numbers = {1,2,3,4,7};

  std::vector<int> combination = bestSum(7, numbers, memo);
  for(int x: combination) cout << x;
  return 0;
}
