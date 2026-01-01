#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
const int MOD = 1e9 + 7;
 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m; cin >> n >> m;
	vector<int> adj[100001];
	vector<int> dist(n+1, INT_MAX), parent(n+1);
	for(int i = 0; i < m; i++){
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	queue<int> q; q.push(1);
	dist[1] = 0;
	while(!q.empty()){
		int x = q.front();
		q.pop();
		for(int v: adj[x]){
			if(dist[v] == INT_MAX){
				dist[v] = dist[x] + 1;
				parent[v] = x;
				q.push(v);
			}
		}
	}
	if(dist[n] == INT_MAX){
		cout << "IMPOSSIBLE" << endl;
		return 0;
	}
	cout << dist[n] + 1 << endl;
	vector<int> path = {n};
	while(n != 1){
		n = parent[n];
		path.push_back(n);
	}
	reverse(path.begin(), path.end());
	for(int v: path) cout << v << " ";
}