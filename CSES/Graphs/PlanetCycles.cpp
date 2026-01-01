#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;
 
vector<int> adj, ans;
vector<vector<int> > radj;
 
void rev_dfs(int x, int siz){
    ans[x] = siz;
    for(auto v: radj[x]){
        //cout << v << endl;
        if(ans[v] == -1){
            rev_dfs(v, siz+1);
        }
    }
}
 
void floyd(int x){
    int y = x;
    do{
        x = adj[x];
        y = adj[adj[y]];
    }
    while(x != y);
    int cycle_siz = 0;
    do{
        cycle_siz++;
        x = adj[x];
    }
    while(x != y);
    do{
        ans[x] = cycle_siz;
        x = adj[x];
    }
    while(x != y);
    do{
        rev_dfs(x, cycle_siz);
        x = adj[x];
    }
    while(x != y);
}
 
int main(){
    int n; cin >> n;
    adj = vector<int>(n); ans = vector<int>(n, -1);
    radj = vector<vector<int> >(n, vector<int>(0));
    for(int i = 0; i < n; i++){
        int v; cin >> v;
        adj[i] = --v;
        radj[v].push_back(i);
    }
    for(int i = 0; i < n; i++){
        if(ans[i] == -1) floyd(i);
    }
    for(int v: ans) cout << v << " ";
}