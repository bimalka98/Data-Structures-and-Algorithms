#include <bits/stdc++.h>
using namespace std;

// int twoStacks(int x, vector<int> a, vector<int> b) {
//   int score = 0;
//   int sum = 0;
//
//   int ai = 0; // Poiter to the stack A
//   int bi = 0; // Poiter to the stack B
//   while((sum < x) && (sum +a[ai] < x|| sum +b[bi] < x)){ // After taking one from the stack, sum should remain lower than the x.
//     if(a[ai] < b[bi]){ // If what is available in A is less than B, take it.
//       sum+=a[ai];
//       ai++;
//       score++;
//     }
//     else{ // If what is available in B is less than A, take it.
//       sum+=b[bi];
//       bi++;
//       score++;
//     }
//
//   }
//   return score;
// }

int twoStacks(int x, vector<int> a, vector<int> b) {
  int score = 0;
  int sum = 0;

  int ai = 0; // Poiter to the stack A
  int bi = 0; // Poiter to the stack B

  while(sum +b[bi] <= x && bi < b.size()){// After taking one from the stack, sum should remain lower than the x.
      sum+=b[bi];
      bi++;
      score++;
    }
 
  for(int ai = 0; ai < a.size();ai++){
      sum+=a[ai];
      while ((sum >x) && bi >0){
          bi-=1;
          sum-=b[bi];
      }
      if(sum >x) break;
      else if (score < ai+bi+1) score = ai+bi+1;
  }

  return score;
}
