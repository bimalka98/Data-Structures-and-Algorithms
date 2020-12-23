#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    int vlarrays, queries;
    cin >> vlarrays >> queries;


    int *store1[vlarrays];

    for(int i = 0; i < vlarrays;i++)  {
        int num_elements;
        cin >> num_elements;
        store1[i] = new int[num_elements];
        for(int j =0; j< num_elements; j++){
            cin >> store1[i][j];

        }
    }

    for(int i=0; i< queries; i++){
        int index, q;
        cin >> index;
        cin >> q;
        cout << store1[index][q] <<'\n';
    }

    return 0;
}
