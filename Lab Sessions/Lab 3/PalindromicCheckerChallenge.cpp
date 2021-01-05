#include <bits/stdc++.h>
using namespace std;


int main() {

    int num_lines;
    cin >> num_lines;

    //vector<int> num_chars;
    vector<string> str;

    // Taking Inputs
    int tempVar1;
    string tempVar2;
    for (int i = 0; i < num_lines; i++){
      cin >> tempVar1 >> tempVar2;
      //num_chars.push_back(tempVar1)  ;
      str.push_back(tempVar2);
    }

    vector<string> states;
    for(string x: str){ // Iterate over each word

        string state = "No";
        for(long unsigned int i = 2; i < x.length()+1; i++ )
            {
            if (x[i] == x[i-1]){state = "Yes"; break;} // If any adjacent characters are equal. It is simply a palindrome.
            else continue;
            }
        states.push_back(state);
        }
    for(string s: states) cout << s << "\n";
    return 0;
}
