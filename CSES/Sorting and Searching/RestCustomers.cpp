#include <iostream>
#include <vector>
#include <cstdio>
#include <map>
 
using namespace std;
typedef long long ll;
 
int main(){
    int n;
    cin >> n;
    map<ll, int> dp;
    for(int i = 0; i < n; i++){
        int a, b; cin >> a >> b;
        dp[a]++;
        dp[++b]--;
    }
    int ans = 0, sum = 0;
    for(auto kv: dp){
        sum += kv.second;
        ans = max(ans, sum);
    }
    cout << ans;
}
