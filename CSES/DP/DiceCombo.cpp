#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>
 
using namespace std;
#define f first
#define s second
#define pii pair<int, int>
#define ll long long
const int MOD = 1e9+7;
 
int main(){
	int n; cin >> n;
	vector<int> dp(n+1);
	dp[0] = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= 6; j++){
			if(i - j >= 0) dp[i] = (dp[i] + dp[i-j]) % MOD;
		}
		dp[i] += (i <= 6);
	}
	cout << dp[n] % MOD << endl;
}