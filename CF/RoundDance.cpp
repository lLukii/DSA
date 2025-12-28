#include <bits/stdc++.h>
 
using namespace std;
#define f first
#define s second
#define pii pair<int, int>
#define ll long long 
#define print(x) cout << x << endl
 
bool vis[200001], cycle = true;
 
void dfs(int c, set<int> adj[]){
    vis[c] = true;
    if(adj[c].size() != 2) cycle = false;
    for(int v: adj[c]){
        if(!vis[v]) dfs(v, adj);
    }
}
 
void solve(){
    memset(vis, false, sizeof(vis));
    int n; cin >> n; 
    set<int> adj[n+1]; // duplicate edges
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        adj[i+1].insert(a);
        adj[a].insert(i+1);
    }
    int maxi = 0, no_cyc = 0;
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            cycle = true; maxi++;
            dfs(i, adj);
            no_cyc += !cycle;
        }
    }
    cout << maxi-no_cyc+(no_cyc > 0) << " " << maxi << endl;
}
 
int main(){
    int t; cin >> t;
    while(t--){
        solve();
    }
}