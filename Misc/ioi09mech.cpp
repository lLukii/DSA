/**
 * International Olympiad in Informatics 2009
 * P5 - Mecho
 */

#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define mp make_pair

int n, S, start_i, start_j, end_i, end_j; 
vector<vector<char>> grid(1001, vector<char>(1001));
vector<vector<int>> bdist(1001, vector<int>(1001, 1e9));
vector<int> dx = {0, 0, -1, 1}, dy = {-1, 1, 0, 0};

bool targeted(int mdist, int bdist){
    return mdist / S >= bdist;
}

bool in_bounds(int x, int y){
    return x >= 0 && x < n && y >= 0 && y < n;
}

bool check(int val){
    queue<pair<int, int>> q;
    q.push(mp(start_i, start_j));
    vector<vector<int>> dist(n, vector<int>(n, 1e9));
    dist[start_i][start_j] = 0; 
    while(!q.empty()){
        auto top = q.front();
        q.pop();
        for(int i = 0; i < 4; i++){
            int x = top.f+dx[i];
            int y = top.s+dy[i];
            if(in_bounds(x, y) && (grid[x][y] == 'M' || grid[x][y] == 'G') && dist[x][y] == 1e9
                && !targeted(dist[top.f][top.s] + 1, bdist[x][y] - val)){
                    dist[x][y] = dist[top.f][top.s] + 1;
                    q.push(mp(x, y));
            }
        }
    }
    // corner case check
    for(int i = 0; i < 4; i++){
        int x = end_i+dx[i], y = end_j+dy[i];
        if(in_bounds(x, y)){
            dist[end_i][end_j] = min(dist[end_i][end_j], dist[x][y]);
        }
    }
    return !(dist[end_i][end_j] == 1e9);
}

int main(){
    cin >> n >> S;
    queue<pair<int, int>> q;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> grid[i][j];
            switch(grid[i][j]){
                case 'H':
                    q.push(mp(i, j));
                    bdist[i][j] = 0;
                    break;
                case 'M':
                    start_i = i; start_j = j;
                    break;
                case 'D':
                    end_i = i; end_j = j;
                    break;
            }
        }
    }
    while(!q.empty()){
        auto top = q.front();
        q.pop();
        for(int i = 0; i < 4; i++){
            int x = top.f + dx[i];
            int y = top.s + dy[i];
            if(in_bounds(x, y) && bdist[x][y] == 1e9 && grid[x][y] != 'T' && grid[x][y] != 'D'){
                bdist[x][y] = bdist[top.f][top.s] + 1;
                q.push(mp(x, y));
            }
        }
    }

    int l = 0, r = 1e9, ans = -1;
    while(l <= r){
        int mid = (l + r)/2;
        if(check(mid)){
            ans = mid;
            l = mid+1;
        }
        else r = mid-1;
    }
    cout << ans << endl;
}