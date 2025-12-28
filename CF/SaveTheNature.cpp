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

ll gcd(ll a, ll b){return a == 0 ? b : gcd(b, a % b);}
 
void solve(){
    int n; cin >> n;
    vector<ll> p(n);
    for(int i = 0; i < n; i++) cin >> p[i];
    ll x, a; cin >> x >> a;
    ll y, b; cin >> y >> b;
 
    ll k; cin >> k;
    ll l = 0, r = n, ans = -1;
    sort(p.rbegin(), p.rend());
    auto check = [&](int mid) -> bool{
        // choose largest floor(k /(a*b)) [tickets that go to both causes]
        ll contrib = 0, common = (a*b)/ gcd(a, b);
        for(int i = 0; i < mid/common; i++){
            contrib += (p[i] * (x+y))/100;
        }
        if(x >= y){
            for(int i = mid/common; i < mid/a; i++){
                contrib +=  (p[i] * x) / 100;
            }
            for(int i = mid/a; i < mid/a + mid/b - mid/common; i++){
                contrib += (p[i] * y) / 100;
            }
        }
        else{
            for(int i = mid/common; i < mid/b; i++){
                contrib +=  (p[i] * y) / 100;
            }
            for(int i = mid/b; i < mid/b + mid/a - mid/common; i++){
                contrib += (p[i] * x) / 100;
            }
        }
        return contrib >= k;
    };
    while(l <= r){
        int mid = (l+r)/2;
        if(check(mid)){
            ans = mid;
            r = mid-1;
        }
        else l = mid+1;
    }
    cout <<  ans << endl;
}
 
int main(){
    int q; cin >> q;
    while(q--){
        solve();
    }
}