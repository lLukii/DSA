#include <bits/stdc++.h>
 
using namespace std;
#define f first
#define s second
#define pii pair<int, int>
#define ll long long
const int MOD = 1e9+7, MAXN = 1e6 + 1;
 
int main(){
	int n, x; cin >> n >> x;
	vector<int> pages(n), price(n);
	for(int i = 0; i < n; i++) cin >> price[i];
	for(int i = 0; i < n; i++) cin >> pages[i];
 
	int dp[n + 1][x + 1]; // dp[i][j] = maximum number of pages by choosing n pages and a price of j. 
	memset(dp, 0, sizeof(dp));
	for(int i = 1; i <= n; i++){
		int cost = price[i - 1];
		int page = pages[i - 1];
		for(int j = 1; j <= x; j++){
			dp[i][j] = dp[i - 1][j];
			if(cost <= j){
				dp[i][j] = max(dp[i][j], dp[i - 1][j - cost] + page);
			}
		}
	}
	cout << dp[n][x] << endl;
}