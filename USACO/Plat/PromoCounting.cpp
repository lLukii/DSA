#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define mp make_pair
#define ll long long

const int mod = 1e9+7;

vector<vector<int>> adj;
vector<int> pref, ft, ans;
map<int, int> comp;
int n, timer = 0;

void upd(int idx, int val){
    for(int i = idx; i <= n; i += i & -i){
        ft[i] += val;
    }
}

int qry(int idx){
    int ans = 0;
    for(int i = idx; i > 0; i -= i & -i){
        ans += ft[i];
    }
    return ans;
}

void dfs(int c, int prev){
    int idx = comp[pref[c]];
    int start_sum = qry(idx);
    int start_time = timer++;
    upd(idx, 1);
    for(int v: adj[c]){
        if(v != prev){
            dfs(v, c);
        }
    }
    int end_sum = qry(idx);
    ans[c] = timer - start_time - (end_sum - start_sum);
}

int main(){
    freopen("promote.in", "r", stdin);
    freopen("promote.out", "w", stdout);
    cin >> n;
    ft = vector<int>(4 * n);
    pref = vector<int>(n);
    ans = vector<int>(n);
    adj = vector<vector<int>>(n, vector<int>(0));

    vector<int> sorted(n);
    for(int i = 0; i < n; i++){
        cin >> pref[i];
        sorted[i] = pref[i];
    }
    sort(sorted.begin(), sorted.end());
    for(int i = 0; i < n; i++){
        comp[sorted[i]] = i+1;
    }
    for(int i = 1; i < n; i++){
        int x; cin >> x;
        adj[i].push_back(--x);
        adj[x].push_back(i);
    }
    dfs(0, -1);
    for(int i = 0; i < n; i++){
        cout << ans[i] << endl;
    }
}