//https://github.com/OmarAhmedSaleh/competitive-programming/blob/master/HackerRank/Prim's%20(MST)%20:%20Special%20Subtree.CPP
//https://www.cplusplus.com/reference/queue/priority_queue/
void MaintainMinPQ(priority_queue<pair<int, int>> &priorityQ, int node, vector<bool> &visited,  vector<vector<pair<int, int>>> & adjList);


// Complete the prims function below.
int prims(int n, vector<vector<int>> edges, int start) {
  //creating the graph as an adjascnecy list
  vector<vector<pair<int, int>>> adjList(n+1);
  for(int i=0; i < (int)edges.size(); i++){
    //graph is undirected. Therfore we need to consider both connections.
    //Node's adjascnecy list = {{node1, weight1}, {node2, weight2},..}
    adjList[edges[i][0]].push_back({edges[i][1], edges[i][2]});
    adjList[edges[i][1]].push_back({edges[i][0], edges[i][2]});
  }

  //Initializing a priority queue to maintain the min priority queue.
  // So we can get the min edge weight simply by the top node of it.
  priority_queue<pair<int, int>> priorityQ;
  vector<bool> visited(n+1, false);
  MaintainMinPQ(priorityQ, start, visited,  adjList);

  int MST_weight = 0;
  while(! priorityQ.empty()){
    pair<int, int> tem_pair = priorityQ.top(); //maximum is at the top
    priorityQ.pop(); // removing the top pair

    int weight = -tem_pair.first;
    //cout << weight << '\n';
    int node   = tem_pair.second;
    //cout << node << '\n';

    if(!visited[node]){
      MST_weight+= weight; // edge is added to the MST
      MaintainMinPQ(priorityQ, node, visited,  adjList);
    }
  }
  return MST_weight;
}

void MaintainMinPQ(priority_queue<pair<int, int>> &priorityQ, int node, vector<bool> &visited, vector<vector<pair<int, int>>> &adjList){
  visited[node] = true; // Mark the node as visted
  for( pair<int, int> item: adjList[node]){
    // Building the minimum priority queue by using negative values of the
    // weights.
    if(!visited[item.first]) priorityQ.push({-item.second, item.first});
  }
}
