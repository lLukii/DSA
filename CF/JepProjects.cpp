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
 
int main(){
    vector<ll> pow2(1e5+1); pow2[0] = 1;
    for(int i = 1; i <= 1e5; i++){
        pow2[i] = (pow2[i-1] * 2) % MOD;
    }
    vector<ll> prefix(1e5+1);
    for(int i = 1; i <= 1e5; i++){
        int jeap = pow2[i-1];
        jeap -= (i%2 == 0 ? pow2[i/2] : pow2[(i-1)/2]);
        prefix[i] = (prefix[i-1] + jeap) % MOD;
    }
    int q; cin >> q;
 
    while(q--){
        int l, r; cin >> l >> r;
        cout << ((prefix[r]-prefix[l-1])%MOD+MOD)%MOD << endl;
    }
}