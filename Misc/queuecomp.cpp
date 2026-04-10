#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define mp make_pair
#define ll long long

const int mod = 998244353;

ll binpow(ll a, ll b){
    if(b == 0) return 1;
    ll res = binpow(a, b/2);
    if(b % 2 == 0) return res * res % mod;
    return res * res % mod * a % mod;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int q; cin >> q;
    queue<pair<ll, ll>> que; 
    ll coef = 1, cons = 0;
    while(q--){
        int qtype; cin >> qtype;
        if(qtype == 0){
            ll a, b; cin >> a >> b;
            que.push(mp(a, b));
            coef = (coef * a) % mod;
            cons = (cons * a + b) % mod;
        }
        else if(qtype == 1){
            auto top = que.front();
            que.pop();
            ll a = top.f, b = top.s;
            coef = coef * binpow(a, mod - 2) % mod; 
            cons -= coef * b; 
            cons %= mod;
        }
        else{
            ll x; cin >> x;
            cout << (coef * x + cons) % mod << endl;
        }
    }
}