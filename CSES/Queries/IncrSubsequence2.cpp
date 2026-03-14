#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define mp make_pair
#define ll long long

const int mod = 1e9 + 7;

struct BIT{
    int n;
    vector<ll> ft;
    BIT(int n) : n(n){
        ft = vector<ll>(4 * n);
    }
    void upd(int idx, ll val){
        while(idx <= n){
            ft[idx] = (ft[idx] + val) % mod;
            idx += (idx & -idx);
        }
    }
    ll qry(int idx){
        ll total = 0;
        while(idx > 0){
            total = (total + ft[idx]) % mod;
            idx -= (idx & -idx);
        }
        return total % mod;
    }
};

int main(){
    int n; cin >> n;
    vector<int> nums(n), nums_sorted(n);
    map<int, int> comp;
    for(int i = 0; i < n; i++){
        cin >> nums[i];
        nums_sorted[i] = nums[i];
    }
    sort(nums_sorted.begin(), nums_sorted.end());
    for(int i = 0; i < n; i++) comp[nums_sorted[i]] = i+1;

    BIT bit(n); 
    vector<int> dp(n);
    dp[0] = 1;
    bit.upd(comp[nums[0]], dp[0]);
    for(int i = 1; i < n; i++){
        dp[i] = bit.qry(comp[nums[i]] - 1) + 1; // add one 
        bit.upd(comp[nums[i]], dp[i]);
    }
    ll ans = 0;
    for(int i = 0; i < n; i++) ans = (ans + dp[i]) % mod;
    cout << ans << endl;
}