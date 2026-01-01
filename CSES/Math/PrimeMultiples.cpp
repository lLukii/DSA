#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
 
using namespace std;
#define f first
#define s second
#define pii pair<int, int>
#define ll long long
 
ll max_num = 1e18;
 
int main(){
    ll n, k; cin >> n >> k;
    vector<ll> nums(k);
    for(int i = 0; i < k; i++) cin >> nums[i];
    ll ans = 0;
    for(int mask = 0; mask < 1 << k; mask++){
        ll prod = 1;
        int cnt = 0; bool overflow = false;
        for(int i = 0; i < k; i++){
            if(mask & 1 << i){
                if(prod > max_num / nums[i]) overflow = true;
                prod *= nums[i]; // prevents int overflow. We know that its not gonna change the answer otherwise. 
                cnt++;
            }
        }
        if(overflow) continue;
        if(cnt >= 1){
            ans += (cnt%2 == 1 ? n / prod : -n / prod);
        }
    }
    cout << ans << endl;
}