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
#define ll long long
 
void solve(){
    int n; cin >> n;
    vector<pii> prices(n);
    for(int i = 0; i < n; i++){
        int a, b; cin >> a >> b;
        prices[i] = {a, b};
    }
    sort(prices.begin(), prices.end());
    vector<int> suffix(n+1, -1e9);
    for(int i = n-1; i >= 0; i--){
        suffix[i] = max(suffix[i+1], prices[i].s);
    }
    set<int> prev;
    int ans = 1e9;
    for(int i = 0; i < n; i++){
        int largest_b = suffix[i+1];
        int l_value = -1e9, r_value = -1e9; // left/right bi values from [0, i) that are the closest to ai. 
        auto it1 = prev.upper_bound(prices[i].f);
        if(it1 != prev.begin()){
            auto it2 = --prev.upper_bound(prices[i].f);
            l_value = *it2;
        }
        if(it1 != prev.end()) r_value = *it1;
 
        int optimal_b = (abs(l_value - prices[i].f) < abs(r_value - prices[i].f) ? l_value : r_value);
        if(optimal_b >= largest_b && abs(optimal_b - prices[i].f) < abs(largest_b - prices[i].f)){ // since chosing optimal_b is merely optional, we only want to do this if our right max is less optimal. 
            largest_b = optimal_b;
        }
        ans = min(ans, abs(largest_b - prices[i].f));
        prev.insert(prices[i].s);
        // cout << largest_b << endl;
    }
    cout << ans << endl;
}
 
int main(){
    int t; cin >> t;
    while(t--){
        solve();
    }
}