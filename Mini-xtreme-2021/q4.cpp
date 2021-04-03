//Cash Multiplier
#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long

bool canget(ull target, vector<int> & array, map<ull, bool> &memo);

int main(){
  int t;
  cin >>t; //test cases
  vector<int> Multipliers = {10,20};
  map<ull, bool> memo;
  for(int i =0; i < t; i++){
    ull final;
    cin >> final;
    bool status =  canget(final,Multipliers, memo);
    if(status) cout << "Yes" << '\n';
    else cout << "No" << '\n';
  }
return 0;
}

bool canget(ull target, vector<int> &array, map<ull, bool> &memo){
if(memo[target]) return memo[target];
if(target == 1) return true; // target perfectly divides
if (target == 0) return false;
//at least one element returns true it will be enough
for(int x: array){
  ull remainder = target/x;
  if (target%x == 0){
      if(canget(remainder, array, memo)==true) {
      memo[target] = true;
      return memo[target];}
  }
}
memo[target] = false;
return false;
}
