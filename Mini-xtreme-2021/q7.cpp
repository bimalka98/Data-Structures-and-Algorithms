// // John’s Party
// #include <bits/stdc++.h>
// using namespace std;
// #define ull unsigned long long
//
// // List of connections
// int main(){
//   int N;
//   cin >>N; //test cases
//   vector<vector<int>> connections(N+1);
//   for(int i =0; i < N; i++){
//     int u, v;
//     cin >> u >> v;
//     connections[u].push_back(v);
//   }
//   // Friends jhon wants to friends
//   int M;
//   cin >> M;
//   vector<int> friends = {}
//   for(int i=0; i < M;i++){
//     int friend;
//     cin >> friend;
//     friends.push_back(friend);
//   }
//
//   vector<int> invitees = {};
//   int i =0;
//   while(i < friends.size()){
//     bool invitees = find(invitees.begin(), invitees.end(), ) != invitees.end();
//     if (! invitees) {
//       invitees.push_back(friends[i]);
//       bool present  = find(friends.begin(), friends.end(),connections[friends[i]] ) != friends.end();
//       if(! present) friends.push_back(connections[friends[i]]);
//     }
//     i+=1;
//   }
//   cout << invitees.size();
// }
// //============================
N = int(input())
connections={}
for k in range(N):
    u,v =map(int,input().split())
    connections[u]=v

M=int(input())
friends=list(map(int,input().split()))
invitees=[]
i=0
while i< len(friends):
    if friends[i] not in invitees:
        invitees.append(friends[i])
        if connections[friends[i]] not in friends:
            friends.append(connections[friends[i]] )
    i+=1
print(len(invitees))
