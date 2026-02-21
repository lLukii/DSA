#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define mp make_pair
#define ll long long

struct BIT{
    vector<ll> bit;
    int n; 
    BIT(int n) : bit(4 * n), n(n) {}

    void upd(int idx, int val){
        while(idx <= n){
            bit[idx] += val;
            idx += idx & -idx;
        }
    }

    ll qry(int idx){
        ll total = 0;
        while(idx > 0){
            total += bit[idx];
            idx -= idx & -idx;
        }
        return total;
    }
};

int main(){
    int n, q; cin >> n >> q;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    BIT bit(n);
    while(q--){
        int t; cin >> t;
        if(t == 1){
            int a, b, u; cin >> a >> b >> u;
            bit.upd(a, u);
            bit.upd(b+1, -u);
        }
        else{
            int k; cin >> k;
            cout << arr[k-1] + bit.qry(k) << endl;
        }
    }
} 