//https://www.hackerrank.com/challenges/recursive-digit-sum/problem

string sumstr(string p){
    int len = p.length();
    if (len==1) return p;
    else{
        int var = 0;
        //The value of the char '0' is 48. The value of the char '1' is 49.
        //so when you do '1' - '0' you get the result 1
        for(char ch: p) var+= ch - '0';
        return sumstr(to_string(var));
    }
}

int superDigit(string n, int k) {
    int var = stoi(sumstr(n));
    return stoi(sumstr(to_string(var*k)));
}
