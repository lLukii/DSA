#include <iostream>
#include <iomanip>
#include <vector>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
 
 
using namespace std;
#define f first
#define s second
#define pii pair<int, int>
#define ll long long
int MOD = 1e9+7, MAXN = 1e5;
 
int main(){
	int n; cin >> n;
	ll sum = (n * (n + 1))/2;
	if(sum & 1){
		cout << 0 << endl;
		return 0;
	}
	sum /= 2;
	ll dp[n + 1][sum + 1];
	memset(dp, 0, sizeof(dp));
	dp[0][0] = 1;
	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= sum; j++){
			dp[i][j] += dp[i - 1][j];
			if(j - i >= 0){
				dp[i][j] += dp[i - 1][j - i];
			}
			dp[i][j] %= MOD;
		}
	}
	cout << dp[n - 1][sum] << endl;
}