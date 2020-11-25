// Link:  https://www.hackerrank.com/challenges/big-sorting/problem

#include <bits/stdc++.h>

using namespace std;

// Function to compare two strings: Because converting strings back to integers is not working.
bool compstr(string a , string b){
    // "45", "46" both has the same length. so we need to compare them to get what is bigger.
    if (a.size() == b.size()) return a > b;
    // If two strings have different lengths, then there's nothing to comapre.
    return a.size() > b.size();
}

// Complete the bigSorting function below.
// Insertion Sort algorithm was used. Not efficent to handle larger inputs.
// Time out error occured for some test cases.
// Maximum scores were 4.0
vector<string> bigSorting(vector<string> unsorted) {
    int length = unsorted.size();
for(int i =1; i< length; i++){
    string key = unsorted[i];
    int j = i-1;
    while(j >=0 && compstr(unsorted[j], key)){
        unsorted[j+1] = unsorted[j];
        j-=1;
    }
    unsorted[j+1] = key;
}
return unsorted;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<string> unsorted(n);

    for (int i = 0; i < n; i++) {
        string unsorted_item;
        getline(cin, unsorted_item);
        unsorted[i] = unsorted_item;
    }

    vector<string> result = bigSorting(unsorted);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];
        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";
    fout.close();
    return 0;
}
