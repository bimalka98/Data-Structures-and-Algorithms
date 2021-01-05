#include <bits/stdc++.h>
using namespace std;

int a(int num1,  int *array);
int b(int num2,  int *array);
int c(int num3,  int *array);

int main() {

  int num_slots; cin >> num_slots;
  int ymd[3]; for(int i =0; i <3 ; i++) cin >> ymd[i];

  int scores[num_slots];
  for(int i = 0; i < num_slots; i++) scores[i] = a(i, ymd) + b(i, ymd) + c(i, ymd);

  for(int x: scores) cout << x << ' ';
    return 0;
}

int a(int num1, int *array){
    if (num1 ==0) return array[0];
    else return (((a(num1-1, array)*a(num1-1, array) + 2*b(num1-1, array) +1)%10007 +10007)%10007 - 5000);
}
int b(int num2, int *array){
  if (num2 ==0) return array[1];
  else return (((b(num2-1, array)*b(num2-1, array) + 2*a(num2-1, array) -1)%10007 +10007)%10007 - 5000);
}
int c(int num3, int *array){
  if (num3 ==0) return array[2];
  else return (((a(num3-1, array) + b(num3-1, array) + c(num3-1, array))%121 + 121)%121 -60);
}
