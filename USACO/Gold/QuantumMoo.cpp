/**
 * USACO 2024 February Contest - Gold
 * Quantum Moochanics
 */

#include <iostream>
#include <iomanip>
#include <vector>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#include <queue>

using namespace std;
#define f first
#define s second
#define pii pair<int, int>
#define int long long


void solve(){
    int n; cin >> n;
    vector<int> s(n), p(n);
    priority_queue<pair<int, pii>> pq;
    vector<int> ans(n);
    vector<pii> adjacent(n);

    auto compute_cost = [&](int a, int b) -> int{
        return 2 * ceil((double)(p[b]-p[a])/(s[b]-s[a])) - (a%2 == 0);
    };

    for(int i = 0; i < n; i++) cin >> s[i];
    for(int i = 0; i < n; i++){
        cin >> p[i];
        adjacent[i] = {i-1, i+1};
    }
    for(int i = 0; i < n-1; i++){
        pq.push({-compute_cost(i, i+1), {i, i+1}});
    }

    while(!pq.empty()){
        auto next_event = pq.top();
        pq.pop();
        int meeting_time = next_event.f;
        auto cows = next_event.s;
        if(ans[cows.f] || ans[cows.s]) continue;
        ans[cows.f] = -meeting_time; ans[cows.s] = -meeting_time;
        if(cows.f != 0 && cows.s != n-1){
            int prev = adjacent[cows.f].f;
            int next = adjacent[cows.s].s;
            pq.push({-compute_cost(prev, next), {prev, next}});
        }
    }
    for(int i = 0; i < n; i++){
        cout << ans[i] << (i == n-1 ? "" : " ");
    }
    cout << endl;
}

signed main(){
    int t; cin >> t;
    while(t--){
        solve();
    }
}

// 2024 USACO Gold Feburary p3