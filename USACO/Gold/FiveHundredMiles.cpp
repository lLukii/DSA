/**
 * USA Computing Olympiad, US Open Gold 2019
 * P2 - I would walk 500 miles
 */

#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define mp make_pair
#define ll long long

const int A = 2019201913;
const int B = 2019201949;
const int mod = 2019201997;

vector<int> p;

int find(int x){
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}

void unite(int x, int y){
    int px = find(x);
    int py = find(y);
    if(px == py) return;
    p[py] = px;
}

bool isCon(int x, int y){
    return find(x) == find(y);
}

struct Edge{
    int dist; 
    short u, v;
};

int n, k; 
vector<Edge> edges;

int main(){
    freopen("walk.in", "r", stdin);
    freopen("walk.out", "w", stdout);
    cin >> n >> k;
    p = vector<int>(n+1);
    for(int i = 1; i <= n; i++) p[i] = i;
    for(short i = 1; i <= n; i++){
        for(short j = i+1; j <= n; j++){
            int dist = (1ll*A*i + 1ll*B*j) % mod;
            edges.push_back({dist, i, j});
        }
    }
    sort(edges.begin(), edges.end(), [](Edge &a, Edge &b){
        return a.dist < b.dist;
    });

    int n_comp = n;
    int ans = mod; 
    for(Edge edge: edges){
        int u = edge.u, v = edge.v;
        if(isCon(u, v)) continue;
        unite(u, v);
        n_comp--; 
        if(n_comp < k) ans = min(ans, edge.dist);
    }
    cout << ans << endl;
}

// I'm pretty sure this is NOT the intended solution 😭