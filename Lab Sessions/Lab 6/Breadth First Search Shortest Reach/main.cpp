vector<int> bfs(int n, int m, vector<vector<int>> edges, int s);
int dist(vector<vector<int>> adjList, int n, int s, int k );

// Complete the bfs function below.
vector<int> bfs(int n, int m, vector<vector<int>> edges, int s) {
        //creating the graph as an adjascnecy list
        std::vector<vector<int>> adjList(n+1);
        for(int i=0; i < m; i++){
          //graph is undirected. Therfore we need to consider both connections.
          adjList[edges[i][0]].push_back(edges[i][1]);
          adjList[edges[i][1]].push_back(edges[i][0]);
        }

        std::vector<int> distances;

        for(int i = 1; i <=n; i++){ // since nodes are indexed from 1
          if(i!=s) distances.push_back(dist(adjList, n, s, i));
        }
    return distances;
}

int dist(vector<vector<int>> adjList, int n, int s, int k ){

      vector<bool> visited(n+1, false);
      queue<pair<int, int>> q; // node and distance to that node from source
      q.push(make_pair(s,0));  // distance to the source is zero
      visited[s] = true;       // mark source as visited

      // BFS are implementd using queues.
      while( !q.empty()){
        pair<int, int> tem_pair = q.front(); //FIFO
        q.pop();
        int node = tem_pair.first;
        int dist = tem_pair.second;
        if (node== k) return dist; // if the required node is reached.

        for(auto itr = adjList[node].begin(); itr != adjList[node].end(); ++itr){
          if(!visited[*itr]){
            visited[*itr] = true;  // exploring all the connected nodes.
            q.push(make_pair(*itr, dist+6));
          }
        }
      } return -1; // // if the required node is not reachable.
}
