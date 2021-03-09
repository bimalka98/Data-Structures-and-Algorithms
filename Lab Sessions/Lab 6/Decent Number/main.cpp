#include <bits/stdc++.h>
using namespace std;

vector<int> howSum(int targetSum, vector<int> &numbers, map<int, vector<int>> &memo);
void decentNumber(int n);

int main(){

decentNumber(1);

}

vector<int> howSum(int targetSum, vector<int> &numbers, map<int, vector<int>> &memo);
void decentNumber(int n);

// Complete the decentNumber function below.
void decentNumber(int n) {
    vector<int> numbers = {3,5}; // number can contains only 3s and 5s

    /* Dynamic programming approach through Memoization.
    finding the combination of 3s and 5s that sums upto given number.
    */
    map<int,vector<int>> memo;
    vector<int> combination = howSum(n, numbers, memo);

    // counting number o occurences of each number
    if(combination[0] == -1) cout << "-1" << '\n';
    else{
    int fives = count(combination.begin(), combination.end(), 5);
    int threes = count(combination.begin(), combination.end(), 3);

    //cout << fives << ' ' << threes << '\n';

    string largest;
    largest.append(threes*3,'5');//The number of 5's it contains is divisible by 3.
    largest.append(fives*5, '3');//The number of 3's it contains is divisible by 5.

    cout << largest << '\n';}
}

vector<int> howSum(int targetSum, vector<int> &numbers, map<int, vector<int>> &memo){
  //If a combination is readily available
  if(memo.find(targetSum) != memo.end()) return memo[targetSum];
  // checking the base cases
  if(targetSum==0) return {};   // Combination exists
  if(targetSum <0) return {-1}; // No combination
  // Recursively finding the combination
  for(int i =0; i <numbers.size(); i++){
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
