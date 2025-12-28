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
 
void solve(){
	int n, m; cin >> n >> m;
	vector<int> nums(m+1);
	for(int i = 1; i <= m; i++){
		cin >> nums[i];
	}
	sort(nums.begin(), nums.end());
	vector<int> ans(n+1, 1e9);
	ans[1] = nums[m];
	for(int i = 2; i <= n; i++){
		int min_replace = 1e9;
		for(int j = 1; j <= sqrt(i); j++){
			if(i%j == 0){
				min_replace = min(min_replace, ans[i/j]);
				min_replace = min(min_replace, ans[j]);	
			}
		}
		auto it = --lower_bound(nums.begin(), nums.end(), min_replace);
		if(it == nums.begin()){
			cout << -1 << endl;
			return;
		}
		ans[i] = *it;
	}
	for(int i = 1; i <= n; i++) cout << ans[i] << " ";
}
 
int main(){
	int t; cin >> t;
	while(t--){
		solve();
	}
}