#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <cassert>
 
using namespace std;
 
void dfs(int i, int j, int n, int m, vector<string> &grid, vector<vector<int>> &vis){
    if(i < 0 || i >= n || j < 0 || j >= m) return;
    if(vis[i][j] || grid[i][j] == '#') return;
    vis[i][j] = true;
    dfs(i-1, j, n, m, grid, vis);
    dfs(i, j-1, n, m, grid, vis);
    dfs(i+1, j, n, m, grid, vis);
    dfs(i, j+1, n, m, grid, vis);
}
 
int main(){
    int n, m; cin >> n >> m;
    vector<string> grid(n);
    vector<vector<int>> vis(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        cin >> grid[i];
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(!vis[i][j] && grid[i][j] == '.'){
                dfs(i, j, n, m, grid, vis);
                ans++;
            }
        }
    }
    cout << ans << endl;
}