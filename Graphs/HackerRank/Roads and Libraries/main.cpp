#include <bits/stdc++.h>
using namespace std;
// int n, int c_lib, int c_road;
// n = 3;c_lib = 2; c_road = 1;

//long roadsAndLibraries(int n, int c_lib, int c_road, vector<vector<int>> cities) {

/*
  * int n: integer, the number of cities
  * int c_lib: integer, the cost to build a library
  * int c_road: integer, the cost to repair a road
  * int cities[m][2]: each cities[i]  contains two integers that represent cities
that can be connected by a new road
*/

//First we need to create a graph to identify the connection between cities.
//Here the adjascnecy list has been used.
/*
city1 | city2
1|2 :2 must be in the adjascnecy list of the 1 and vice-verca.
2|4
*/
int dfs(vector<vector<int>> & vec, int src, vector<bool> &visited){
  visited[src] = true;
  int ans = 1; //size of the component with current node as source
  for(int i = 0; i < vec[src][i]; ++i){ //adjascnecy list traversal
    if(!visited[vec[src][i]]) ans+= dfs(vec, vec[src][i], visited);
  }
  return ans;
}

void dfs(const vector<vector<int>> & vec, int s, vector<bool> &visited){
  stack<int> stk;
  stk.push(s);
  visited[s] = true; // push start node in stack and mark it visited.
  cout << stk.top() << ' ';
  while (!stk.empty()) {
    int node = stk.top();// pop out a node from stack and
    cout << "visited: "<< node << " ";
    for(int i=0; i < vec[node].size(); ++i){
      if(!visited[vec[node][i]]){
        stk.push(vec[node][i]); // push all non-visited adjacent node of popped
        // node in stack and mark them visited.
        visited[vec[node][i]] = true;
      }
    }
  }
}

int c_lib = 2;
int c_road = 1;
int main(){

  vector<vector<int>> cities = {{1, 2}, {3, 1}, {2, 3}};
  int n = cities.size();

  vector<vector<int>> vertices(n+1);
  for(int i=0; i < n; i++){
    //graph is undirected. Therfore we need to consider both connections.
    vertices[cities[i][0]].push_back(cities[i][1]);
    vertices[cities[i][1]].push_back(cities[i][0]);
  }

  //cout << vertices.size() << '\n';
  // cities start form 1,2,3,...
  for(int i=1; i < vertices.size(); i++){
  cout << i <<  " --> |";
  // printing out the adjascnecy list
  for(int j =0; j < vertices[i].size();j++) cout << vertices[i][j] << '|' ;
  cout << '\n';
  }


  vector<int> components;
  vector<bool> visited(n+1, false);
  for(bool x: visited) cout << x <<' '  ;
  cout<< '\n';
  dfs(vertices, 1, visited);
  for(bool x: visited) cout << x <<' '  ;

  // for(int i =1; i < vertices.size() ;i++){
  //   if(vertices[i].size() >0 && !visited[i]) components.push_back(dfs(vertices,i,visited));
  //   else if(vertices[i].size() ==0) components.push_back(1); // islands
  // }
  //
  //
  //
  // long long int ans = 0;
  // for(int i =0; i < components.size(); ++i){
  //   ans += min((components[i]-1)*c_road + c_lib, components[i]*c_lib);
  // }
  // return ans;
}
//}
