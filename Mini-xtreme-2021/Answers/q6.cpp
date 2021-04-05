//Bridge Game 1
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 1e5 + 17, mod = 1e9 + 7;

struct Edge{
    int v, u;
    bool bl;
    int o(int x){
        return x == v ? u : v;
    }
}  edges[maxn];
int n, m, sz[maxn], hi[maxn], h[maxn];
vector<Edge*> garph[maxn];
bool mark[maxn];

void dfs(int v = 0, int p = -1){
    mark[v] = 1;
    sz[v] = 1;
    hi[v] = h[v];
    for(auto edges : garph[v]){
        int u = edges -> o(v);
        if(u != p){
            if(!mark[u]){
                h[u] = h[v] + 1;
                dfs(u, v);
                sz[v] += sz[u];
                if(hi[u] == h[u])
                    edges -> bl = 1;
                hi[v] = min(hi[v], hi[u]);
            }
            else
                hi[v] = min(hi[v], h[u]);
}    }
}
int rev(int a){
    int ans = 1;
    for(int b = mod - 2; b; b >>= 1, a = (ll) a * a % mod)
        if(b & 1)
            ans = (ll) ans * a % mod;
    return ans;
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> edges[i].v >> edges[i].u;
        edges[i].v--, edges[i].u--;
        garph[edges[i].v].push_back(&edges[i]);
        garph[edges[i].u].push_back(&edges[i]);
    }
    dfs();
    int a = 0, b = 0;
    for(int i = 0; i < m; i++)
        if(edges[i].bl){
            int cmp = min(sz[edges[i].v], sz[edges[i].u]);
            if(n % 2 == 0 && cmp % 2 == 0)
                a++;
            else
                b++;
        }
    cout << (ll) a * rev(a + b) % mod << ' ' << (ll) b * rev(a + b) % mod << '\n';
}
