#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>
 
using namespace std;
#define f first
#define s second
#define pii pair<int, int>
#define ll long long

const int MXN = 1e6+1;

vector<int> adj[MXN];
int leaf[MXN], anc[MXN], p[MXN], depth[MXN], M = 0;

void dfs(int c, int f){
	bool is_leaf = true;
	for(int v: adj[c]){
		if(v != f){
			is_leaf = false;
			depth[v] = depth[c]+1;
			dfs(v, c);
			leaf[c] += leaf[v];
		}
	}
	if(is_leaf){
		leaf[c] = 1;
		M++;
	}
}

int main(){
	int n; cin >> n;
	for(int i = 0; i < n; i++){
		int x; cin >> x;
		adj[i+1].push_back(x);
		adj[x].push_back(i+1);
		anc[i+1] = x;
	}
	dfs(0, -1);
	for(int i = 0; i < M-1; i++){
		int word; cin >> word;
		p[word] = 1;
		while(word != 0){
			leaf[word] -= p[word];
			p[anc[word]] += p[word];
			p[word] = 0;
			if(leaf[word]) break;
			word = anc[word];
		}
		cout << depth[word]+1 << endl;
	}
	cout << 0 << endl;
}