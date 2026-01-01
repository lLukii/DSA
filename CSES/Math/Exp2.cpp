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
 
const ll MOD = 1e9+7;
 
ll binpow(ll a, ll b, int m){
    if(b == 0) return 1;
    ll res = binpow(a, b/2, m);
    if(b%2 == 0) return (res % m * res) % m;
    else return (((res % m) * res) % m * a) % m; 
}
 
 
int main(){
    int q; cin >> q;
    while(q--){
        ll a, b, c; cin >> a >> b >> c;
        cout << binpow(a, binpow(b, c, MOD-1), MOD) << endl;
    }
