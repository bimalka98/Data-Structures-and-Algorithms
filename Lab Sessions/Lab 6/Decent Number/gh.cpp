// get combinations of threes and fives which sums upto n
void getCombinations(vector<pair<int, int>> &combs, int n) {
    int fives   = 0;
    int threes  = 0;
    while (true) {
        fives = n - threes;
        if (fives < 0) break;
        //The number of 5's it contains is divisible by 3.
        if (fives % 3 == 0) combs.push_back(make_pair(fives, threes));
        //The number of 3's it contains is divisible by 5. therefore,
        threes += 5;
    }
}


void decentNumber(int n){
  vector<pair<int, int>> combs;
  getCombinations(combs,n);
  if (combs.size() > 0) {
    pair<int, int> maximum = *max_element(combs.begin(), combs.end());
    // getting number of occurences of each number
    int fives = maximum.first;
    int threes = maximum.second;

    string largest;
    largest.append(fives,'5');
    largest.append(threes, '3');
    cout << largest << '\n';
  }
  else cout << -1 << '\n';
}
