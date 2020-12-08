vector<int> rotateLeft(int d, vector<int> arr) {
int i = 0; // declaring a temporarily variable to store the number of steps
    while(i < d){
        int temp = *arr.begin();  // storing the first element in the vector to a temporarily variable
        arr.erase(arr.begin());   // erasing the first element
        arr.push_back(temp);      // append the stored first element at the end of the vector
        i++;                      // incrmeting the number of steps
    }
return arr; // returning the rotate array
}
