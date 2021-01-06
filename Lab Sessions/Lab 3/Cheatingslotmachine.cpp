 //find the strategy to find the best first and the last slot
 //machines to play with

#include <bits/stdc++.h>
using namespace std;

// Function declaration

// int a(int num1,  int *array);
// int b(int num2,  int *array);
// int c(int num3,  int *array);
int cumSum(int *arr,int start, int index);

int main(){

  int num_slots; cin >> num_slots;
  int ymd[3]; for(int i =0; i <3 ; i++) cin >> ymd[i];

  // Recusive method of score Calculating: High Time consumption
  // int scores[num_slots];
  // for(int i = 0; i < num_slots; i++) scores[i] = a(i, ymd) + b(i, ymd) + c(i, ymd);

  // Non-Recusive method of score Calculating : Look-up-table method.
  //Calculating a,b,c values otherwise we have to calculate it recursively
  //It  is time consumi9ng
  int a[num_slots] = {ymd[0]};
  int b[num_slots] = {ymd[1]};
  int c[num_slots] = {ymd[2]};
  for(int i = 0; i < num_slots-1; i++){
    a[i+1] = (((a[i]*a[i] + 2*b[i] +1)%10007 +10007)%10007 - 5000);
    b[i+1] = (((b[i]*b[i] + 2*a[i] -1)%10007 +10007)%10007 - 5000);
    c[i+1] = (((a[i] + b[i] + c[i])%121 + 121)%121 -60);
  }

  int scores[num_slots];
  for(int i = 0; i < num_slots; i++) scores[i] = a[i] + b[i] + c[i];

  // for(int x: scores) cout << x << ' ';
  // cout << '\n';


  //vector<int> cumulativeScores;
  int max = scores[0];
  for(int i = 0; i < num_slots;i++) {
    int start = i;
    for(int j = start; j < num_slots;j++){
      int cs = cumSum(scores,start, j);
      if (cs >= max) max =cs;}
    //cumulativeScores.push_back(cumSum(scores,start, j));}
  }
  // for(int x: cumulativeScores) cout << x << ' ';
  // cout << '\n';
  //sort(cumulativeScores.begin(), cumulativeScores.end());
  // for(int x : cumulativeScores) cout << x << ' ';
  // cout << '\n';
  //cout << cumulativeScores.back();
  cout << max;
  return 0;
}

// User defined functions: devide and conquer approach

int cumSum(int *arr,int start, int index){
  if (index == start) return arr[start];
  else return arr[index] + cumSum(arr,start, index -1);
}

// functions for recursive score calculations
// int a(int num1, int *array){
//     if (num1 ==0) return array[0];
//     else return (((a(num1-1, array)*a(num1-1, array) + 2*b(num1-1, array) +1)%10007 +10007)%10007 - 5000);
// }
// int b(int num2, int *array){
//   if (num2 ==0) return array[1];
//   else return (((b(num2-1, array)*b(num2-1, array) + 2*a(num2-1, array) -1)%10007 +10007)%10007 - 5000);
// }
// int c(int num3, int *array){
//   if (num3 ==0) return array[2];
//   else return (((a(num3-1, array) + b(num3-1, array) + c(num3-1, array))%121 + 121)%121 -60);
// }
