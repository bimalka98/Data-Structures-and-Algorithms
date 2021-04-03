//Teacher and his Students
//timeout with 4 sampoles
#include <bits/stdc++.h>
using namespace std;


int main(){

  int t;
  cin >>t; //test cases
  for(int i =0; i < t; i++){

    int n,m;
    cin >> n;
    cin >> m;
    int total = n+m;

    set<unsigned long int> in = {};

    for(int j = 0; j < total; j++){
      unsigned long int val;
      cin >> val;
      if (j < n) in.emplace(val);
      else{
          bool exists = in.find(val) != in.end();//find(in.begin(), in.end(), val) != in.end();
          if (exists){
              cout << "YES" << '\n';}
          else{ cout << "NO" << '\n';
              in.emplace(val);}
      }
    }
  }
}
