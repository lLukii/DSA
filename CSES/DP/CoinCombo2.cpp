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
int dp[MAXN + 1];
 
int main(){
    int n, x; cin >> n >> x;
    vector<int> coins(n);
    for(int i = 0; i < n; i++) cin >> coins[i];
    dp[0] = 1;
    for(int i = 0; i < n; i++){
        for(int j = 1; j <= x; j++){
            if(j - coins[i] >= 0){
                dp[j] += dp[j - coins[i]];
                dp[j] %= MOD;
            }
        }
    }
    cout << dp[x] << endl;
}