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

void solve(){
    ll a, b, c, d; cin >> a >> b >> c >> d;
    ll ans = 0;
    while(c > 0 && d > 0){
        if(a == c && b == d){
            cout << ans << endl;
            return;
        }
        ll x = min(c, d);
        ll y = max(c, d);
        if(a == c){
            ll subtract = (d - b)/x;
            if(subtract < 0 || (d - b)%x != 0) break;
            ans += subtract;
            d -= x * subtract;
        }
        else if(b == d){
            ll subtract = (c - a)/x;
            if(subtract < 0 || (c - a)%x != 0) break;
            ans += subtract;
            c -= x * subtract;
        }
        else{
            ll subtract = (y - x)/x + 1;
            ans += subtract;
            if(c == x) d -= x * subtract;
            else c -= x * subtract;
        }
    }
    cout << -1 << endl;
}

int main(){
    int t; cin >> t;
    while(t--){
        solve();
    }
}