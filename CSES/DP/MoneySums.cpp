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
	vector<int> cost(n);
	for(int i = 0; i < n; i++) cin >> cost[i];
 
	int dp[MAXN + 1][n + 1];
	memset(dp, 0, sizeof(dp));
	dp[0][0] = 1;
	for(int i = 1; i <= MAXN; i++){
		for(int j = 1; j <= n; j++){
			int c = cost[j - 1];
			if(i - c >= 0){
				for(int k = 0; k < j; k++){
					dp[i][j] += dp[i - c][k];
				}
			}
		}
	}
	set<int> dist;
	for(int i = 1; i <= MAXN; i++){
		for(int j = 1; j <= n; j++){
			if(dp[i][j]){
				dist.insert(i);
				break;
			}
		}
	}
	cout << dist.size() << endl;
	for(int a: dist) cout << a << " ";
}