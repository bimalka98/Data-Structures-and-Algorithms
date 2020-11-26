#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the introTutorial function below.
int introTutorial(int V, vector<int> arr) {

// arr.size() returns long unsigned int, which can not be used to compare with
// an integer. By assigning it to an int variable, it can be converted to an int
    int len = arr.size();
// In a non-void function return must be placed at the last. Therefore the
// required value is stored in a variable
    int index;
    for(int i = 0; i < len;i++){
        if (arr[i]==V){
            index =  i;
// for loop is broken at the first occurence of the V so there's no need of checking
// the rest of the vector
            break;
        }
    }
    return index;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int V;
    cin >> V;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(n); // vector of size n , consisting of integers.

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]); // string to integer conversion

        arr[i] = arr_item;
    }

    int result = introTutorial(V, arr);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);
    
    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }
    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));
    return splits;
}
