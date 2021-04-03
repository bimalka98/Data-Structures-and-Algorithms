//Drone Navigation
#include <bits/stdc++.h>
using namespace std;


int main(){
  int t;
  cin >>t; //test cases
  for(int i =0; i < t; i++){
    int x,y;
    cin >> x;
    cin >> y;
    string orders;
    cin >> orders;

    int R = 0;int L = 0;int U = 0;int D = 0;

    for(char order:orders){
      if(order=='R') R++;
      else if (order =='L') L++;
      else if (order == 'U') U++;
      else D++;
    }
    bool status = true;
    if(x<0){if(L < -x) status = false;}
    else{if(R < x) status = false;}

    if(y<0){if(D < -y) status = false;}
    else{if(U < y) status = false;}

    if(status) cout << "YES" <<'\n';
    else cout << "NO" << '\n';

    }
}
