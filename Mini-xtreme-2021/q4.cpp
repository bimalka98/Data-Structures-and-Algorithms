//Cash Multiplier
#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long

bool canget(int target, vector<int> & array, map<int, bool> &memo);

int main(){
  int t;
  cin >>t; //test cases

  vector<int> Multipliers = {10,20};
  map<ull, bool> memo;

  for(int i =0; i < t; i++){
    ull final;
    cin >> final;

    if(canget(final,Multipliers, memo)) cout << "YES" << '\n';
    else cout << "NO" << '\n';
  }

}

bool canget(int target, vector<int> & array, map<ull, bool> &memo){

if(memo[target]) return memo[target];
if(target ==1) return true;

//at least one element returns true it will be enough
for(int i =0; i < 2;i++){
  ull remainder = target/array[i];
  if(canget(remainder, array, memo)==true) {
    memo[target] = true;
    return memo[target];}
}
memo[target] = false;
return false;
}
