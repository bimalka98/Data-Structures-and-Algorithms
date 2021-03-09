// =============================================================================
// https://www.youtube.com/watch?v=kVyIhwYnLNs
void dfs(const vector<vector<int>> & vec, int s);
int dfs1(vector<vector<int>> & vec, int src, vector<bool> &visited);

int dfs(vector<vector<int>> & vec, int src, vector<bool> &visited){
  visited[src] = true;
  int ans = 1; //size of the component with current node as source
  for(int i = 0; i < vec[src][i]; ++i){ //adjascnecy list traversal
    if(!visited[vec[src][i]]) ans+= dfs(vec, vec[src][i], visited);
  }
  return ans;
}

void dfs_rec(int s){
  visited[s] = true;
  cout << s << " ";
  for(int i = 0; i < vec[s].size(); ++i){
    if(visited[vec[s][i]] == false) dfs_rec(vec[s][i]);
  }
}

void dfs(const vector<vector<int>> & vec, int s){
  stack<int> stk;
  visited[s] = true; // push start node in stack and mark it visited.
  while (!stk.empty()) {
    int node = stk.top();// pop out a nod from stack and
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

void intialize(){
  for(int i =0;i < visited.size(); ++i) visited[i]=false;
}
