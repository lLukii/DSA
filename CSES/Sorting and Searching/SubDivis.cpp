#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <cmath>
 
using namespace std;
#define int long long
#define all(x) begin(x), end(x)
#define lb(x) lower_bound(all(x))
#define f first
#define s second
 
template <typename T> T gcd(T a, T b){return b == 0 ? a : gcd(b, a%b);}
 
signed main(){
    int n; cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    map<int, int> mp;
    int ans = 0, c_sum = 0;
    for(int i = 0; i < n; i++){
        c_sum += nums[i];
        if(c_sum%n == 0) ans++;
        int mod = c_sum%n < 0 ? n+c_sum%n : c_sum%n;
        ans += mp[mod];
        mp[mod]++; 
    }
    cout << ans << endl;
    // cout << -5%3 << endl;
}