// Complete the countSort function below.
void countSort(vector<vector<string>> arr) {

// since integer associated with  sitrings less than 100
// Initiate a vector of vectors of 100 rows (0 to 99)
vector<vector<string>> sorted(100);

int size = arr.size(); // get the size of the input array to iterate
for (int i = 0; i < size; i++) {
// If the item is in the first half
    if(i < size/2) sorted[stoi(arr[i][0])].push_back("-"); // append '-'
// If the item is in the rest of the array
    else sorted[stoi(arr[i][0])].push_back(arr[i][1]);  // append the corresponding string
}
// printing the sorted list
for( int i =0; i<100; i++){
    for(string x: sorted[i]) cout << x << ' ';
}
// stoi() string to integer casting to identify the integer associated(arr[i][0])
// with the string in a particular item in the input list
