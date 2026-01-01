#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define ll long long
#define f first
#define s second
const int MOD = 1e9 + 7;
 
vector<int> parent, csize;
priority_queue<int> sizes;
void init(int n){
    parent = vector<int>(n);
    csize = vector<int>(n);
    for(int i = 0; i < n; i++){
        parent[i] = i;
        csize[i] = 1;
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
    parent[rootB] = rootA;
    if(rootA != rootB){
        csize[rootA] += csize[rootB];
        sizes.push(csize[rootA]);
    }
}
 
int main(){
    int n, m; cin >> n >> m;
    int num_comp = n;
    init(n);
    while(m--){
        int a, b; cin >> a >> b;
        if(find(--a) != find(--b)) num_comp--;
        unite(a, b);
        cout << num_comp << " " << sizes.top() << endl;
    }
}