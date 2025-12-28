#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long
#define f first
#define s second
const int MOD = 1e9 + 7;

struct DSU{
	vector<int> parent, sizes;
	void init(int n){
		parent = vector<int>(n);
		sizes = vector<int>(n);
		for(int i = 0; i < n; i++){
			parent[i] = i;
			sizes[i] = 1;
		}
	}
	int find(int a){
		if(parent[a] == a) return a;
		parent[a] = find(parent[a]);
		return parent[a];
	}

	void unite(int a, int b){
		int rootA = find(a);
		int rootB = find(b);
		if(rootA == rootB) return;
		if(sizes[rootA] > sizes[rootB]) swap(rootA, rootB);
		parent[rootA] = rootB;
		sizes[rootB] += sizes[rootA];
	}
};

int main(){
	freopen("mootube.in", "r", stdin);
	freopen("mootube.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, q; cin >> n >> q;
	vector<vector<int>> queries;
	vector<vector<int>> edges;
	for(int i = 0; i < n - 1; i++){
		int p, q, r; cin >> p >> q >> r;
		edges.push_back({r, --p, --q});
	}
	for(int i = 0; i < q; i++){
		int k, v; cin >> k >> v;
		queries.push_back({k, --v, i});
	}
	sort(edges.rbegin(), edges.rend());
	sort(queries.rbegin(), queries.rend());
	vector<int> ans(q);
	DSU dsu; dsu.init(n);
	for(int i = 0, j = 0; i < q; i++){
		while(j < n - 1 && edges[j][0] >= queries[i][0]){
			dsu.unite(edges[j][1], edges[j][2]);
			j++;
		}
		ans[queries[i][2]] = dsu.sizes[dsu.find(queries[i][1])] - 1;
	}
	for(int a: ans) cout << a << endl;
}