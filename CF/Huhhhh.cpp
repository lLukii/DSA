/**
 * Codeforces Round 874 Problem G
 * Rating: 1800
 */

#include <iostream>
#include <iomanip>
#include <vector>
#include <cstring>
#include <algorithm>
#include <map>
 
using namespace std;
#define f first
#define s second
#define pii pair<int, int>
#define ll long long
 
vector<int> adj[200001];
map<pii, int> mp;
int dp[200001], ans = 0;
vector<int> edges;
 
void dfs(int c, int f){
	dp[c] = 1;
	for(int v: adj[c]){
		if(v != f){
			dfs(v, c);	
			if(dp[v] == 3){
				ans++;
				edges.push_back(mp[{v, c}]);
			}
			else dp[c] += dp[v];
		}
	}
}
 
void solve(){
	int n; cin >> n;
	memset(dp, 0, sizeof(dp)); mp.clear(); edges.clear();
	ans = 0;
	for(int i = 1; i <= n; i++) adj[i] = vector<int>(0);
	for(int i = 0; i < n-1; i++){
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
		mp[{a, b}] = i+1;
		mp[{b, a}] = i+1;
	}
	if(n%3 != 0){
		cout << -1 << endl;
		return;
	}
	dfs(1, -1);
	if(dp[1] != 3){
		cout << -1 << endl;
		return;
	}
	cout << ans << endl;
	for(int edge: edges) cout << edge << " ";
	cout << endl;
}
 
int main(){
	int t; cin >> t;
	while(t--){
		solve();
	}
}