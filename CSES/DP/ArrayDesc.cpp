#include <iostream>
#include <vector>

using namespace std;
#define ll long long
#define f first
#define s second
const int MOD = 1e9 + 7;

int main(){
	int n, m; cin >> n >> m;
    vector<int> nums(n);
	vector<vector<ll>> dp(n, vector<ll>(m+2));
    for(int i = 0; i < n; i++){
	  	cin >> nums[i];
    }
	if(!nums[0]){
		for(int i = 1; i <= m; i++) dp[0][i] = 1;
	}
	else dp[0][nums[0]] = 1; 

	for(int i = 1; i < n; i++){
		int v = nums[i];
		if(v == 0){
     			for(int j = 1; j <= m; j++){
     				dp[i][j] += dp[i-1][j-1] + dp[i-1][j] + dp[i-1][j+1];
     				dp[i][j] %= MOD;
     			}
		}
		else{
			dp[i][v] += dp[i-1][v-1] + dp[i-1][v] + dp[i-1][v+1];
			dp[i][v] %= MOD;
		}
	}
	ll ans = 0;
	for(int j = 1; j <= m; j++){
		ans += dp[n-1][j];
	}
	cout << ans % MOD << endl;
}
