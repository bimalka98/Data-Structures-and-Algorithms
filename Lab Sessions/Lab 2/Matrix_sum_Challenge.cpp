// Matrix Sum Challenge

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N;
    cin >> N;


    if(N == 1) cout << 1; // if N == 1 then simply return 1 as there is only that element

    else{
        long sum = 1; // variable to store the summation. Start with 1 to add N ==1 matrix's sum

        // By inspecting the matrix we can recognize a pattern for the sum for each N > 1
        // for each increment in dimension only 4 additional elements are added.
        // [3,5,7,9]    N == 3 --> 1^2 + (1+1)*i ... for i in [1,2,3,4]
        //[13,17,21,25] N == 5 --> 3^2 + (3+1)*i ... "   "
        //[31,37,43,49] N == 7 --> 5^2 + (5+1)*i ... "   "
        // All these must be added.
        // pattern for a particular n == n value --> (n^2 + (n+1)*i )... for i in [1,2,3,4]

        for(int n = 1; n < N; n+=2){
            for(int j = 1; j <5; j++) sum += (n*n + (n+1)*j);
        }
        cout << sum;
    }
    return 0;
}
