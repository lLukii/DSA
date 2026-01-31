/**
 * USACO 2017 Feburary Contest - Gold
 * Why did the cow cross the road II
 */

#include <iostream>
#include <vector>

using namespace std;
#define ll long long
#define f first
#define s second
const int MOD = 1e9 + 7;

int main(){
	freopen("nocross.in", "r", stdin);
	freopen("nocross.out", "w", stdout);
	int n; cin >> n;
	vector<int> top(n+1), bottom(n+1);
	vector<vector<int>> dp(n+1, vector<int>(n+1));
	
	for(int i = 1; i <= n; i++) cin >> top[i];
	for(int i = 1; i <= n; i++) cin >> bottom[i];
	for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            dp[i][j] = max(dp[i][j], dp[i-1][j-1] + (abs(top[i] - bottom[j]) <= 4));
        }
	}
	cout << dp[n][n] << endl;
}
