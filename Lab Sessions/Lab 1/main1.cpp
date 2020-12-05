void minimumBribes(vector<int> array) {
    int n = array.size();
    bool state = true;

    for(int i= 0; i < n ;i++ ) {
        array[i] = i+1 - array[i];
        if (array[i] < -2){
            state = false;
            break;
        }
    }
    //for(int i =0; i<n;i++) cout << array[i]<< "\t";
    if(state){
        int bribes = 0;
        int temp = 0;
        for(int i = 1; i < n; i++){
            if (array[i] != 0) temp+= array[i];
            else continue;



        }
        cout << bribes << "\n";
        }
    else cout << "Too chaotic\n";
    }
