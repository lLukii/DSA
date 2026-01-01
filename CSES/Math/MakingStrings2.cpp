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
 
const ll MOD = 1e9+7, MAXN = 1e6;
ll fact[MAXN+1], inv[MAXN+1];
 
ll exp(ll a, ll b, ll m = MOD){
    a %= m;
    ll res = 1;
    while(b > 0){
        if(b%2 == 1) res = (res * a) % m;
        a = (a * a) % m;
        b /= 2;
    }
    return res;
}
 
int main(){
    string s; cin >> s;
    vector<int> cnt(26);
    for(char c: s){
        cnt[c-'a']++;
    }
    fact[0] = 1;
    for(int i = 1; i <= MAXN; i++){
        fact[i] = (fact[i-1] * i) % MOD;
    }
    inv[MAXN] = exp(fact[MAXN], MOD-2);
    for(int i = MAXN; i >= 1; i--){
        inv[i-1] = (inv[i] * i) % MOD;
    }
    ll ans = fact[s.size()];
    for(int i = 0; i < 26; i++){
        ans = (ans * inv[cnt[i]]) % MOD;
    }
    cout << ans << endl;
}