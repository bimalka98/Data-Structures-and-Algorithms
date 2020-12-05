#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
//#include <bits/stdc++.h>
using namespace std;


int main() {

    int n;
    cin >>n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int intarr[n];

    for(int i=0; i<n;i++) cin >> intarr[i];
    for(int i=0; i<n;i++) cout<< intarr[n-1 -i] << " ";


    return 0;
}
