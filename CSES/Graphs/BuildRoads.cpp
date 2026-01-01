#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
 
using namespace std;
 
 
vector<vector<int>> adj(1e5+1, vector<int>(0));
vector<bool> vis(1e5+1);
vector<int> comp;
 
void dfs(int c, int i){
    vis[c] = true;
    comp[i] = c;
    for(int v: adj[c]){
        if(!vis[v]){
            dfs(v, i);
        }
    }
}
 
int main(){
    int n, m; cin >> n >> m;
    for(int i = 0; i <m; i++){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            comp.push_back(0);
            dfs(i, ++ans-1);
        }
    }
    cout << ans-1 << endl;
    for(int i = 0; i < ans-1; i++){
        cout << comp[i] << " " << comp[i+1] << endl;
    }
    return 0;
}