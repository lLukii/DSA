#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
const int MOD = 1e9 + 7;
 
vector<int> dx = {1, -1, 0, 0};
vector<int> dy = {0, 0, -1, 1};
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m; cin >> n >> m;
    char grid[n][m], direction[n][m];
    int depth[n][m];
    map<pair<int, int>, pair<int, int>> mp;
    int start_i = 0, start_j = 0;
    int end_i = 0, end_j = 0;
    memset(depth, -1, sizeof(depth));
    memset(direction, '0', sizeof(direction));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
            if(grid[i][j] == 'A'){
                start_i = i;
                start_j = j;
            }
        }
    }
    queue<pair<int, int>> q;
    depth[start_i][start_j] = 0;
    q.push({start_i, start_j});
    while(!q.empty()){
        auto top = q.front();
        q.pop();
        if(grid[top.first][top.second] == 'B'){
            end_i = top.first;
            end_j = top.second;
            break; 
        }
        for(int i = 0; i < 4; i++){
            int x = top.first + dx[i];
            int y = top.second + dy[i];
            if(x >= 0 && x < n && y >= 0 && y < m && 
                grid[x][y] != '#' && depth[x][y] == -1){
                q.push({x, y});
                depth[x][y] = depth[top.first][top.second] + 1;
                switch(i){
                    case 0: direction[x][y] = 'D'; break;
                    case 1: direction[x][y] = 'U'; break;
                    case 2: direction[x][y] = 'L'; break;
                    case 3: direction[x][y] = 'R'; break;
                }
                mp[{x, y}] = {top.first, top.second};
            } 
        }
    }
    if(depth[end_i][end_j] == -1){
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    cout << depth[end_i][end_j] << endl;
    string out = "";
    while(true){
        out += direction[end_i][end_j];
        auto last = mp[{end_i, end_j}];
        end_i = last.first; end_j = last.second;    
        if(end_i == start_i && end_j == start_j) break;    
    }
    reverse(out.begin(), out.end());
    cout << out << endl;
}