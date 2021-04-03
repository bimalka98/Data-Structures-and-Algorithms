#include <bits/stdc++.h>
using namespace std;

struct Activity{
  int start, finish;
  int duration(){
    return finish - start;
  }
};

bool compareActivity(Activity a1, Activity a2){
  return a1.finish < a2.finish;
};

int main(){

  vector<Activity> activities = {{2,8},{3,12},{1,5}};
  for (Activity x: activities) cout << x.start << '\t' << x.finish << '\n';
  cout << activities.size() << '\n';

  sort(activities.begin(), activities.end(), compareActivity);
  for (Activity x: activities) cout << x.start << '\t' << x.finish << '\n';

}
