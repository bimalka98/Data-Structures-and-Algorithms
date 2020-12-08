// Complete the hourglassSum function below.
int hourglassSum(vector<vector<int>> arr) {

    vector<int> sums; // declaring a vector to store the sums since we have no idea about the range of sums[min, max]

    for(int i = 0; i <4; i++){
        for(int j = 0; j <4;j++){
            int sum = arr[i][j] + arr[i][j+1] + arr[i][j+2]+
                            arr[i+1][j+1] +
                  arr[i+2][j] + arr[i+2][j+1] + arr[i+2][j+2]; // calculating the sum
            sums.push_back(sum);    // appending evry sum into a vector so we can investigate later

        }
    }
    sort(sums.begin(), sums.end()); // sorting the vector to get the max sum
    return sums.back();             // Last element is the maximum sum
}
