#include <iostream>
#include <vector>

using namespace std;
#define ll long long
#define f first
#define s second
const int MOD = 1e9 + 7;

ll binpow(ll a, ll b){
	if(b == 0) return 1;
	ll res = binpow(a, b / 2);
	if(b % 2 == 0) res = res * res;
	else res = res * res * a;
	res %= MOD;
	return res;
}

int main(){
	int n, m, k; cin >> n >> m >> k;
	vector<pair<int, int>> words;
	vector<int> letter_cnt(26);
	for(int i = 0; i < n; i++){
		int a, b; cin >> a >> b;
		words.push_back({a, b});
	}
	for(int i = 0; i < m; i++){
		char c; cin >> c;
		letter_cnt[c-'A']++;
	}
	vector<ll> dp(k+1);
	dp[0] = 1;
	for(int i = 1; i <= k; i++){
		for(int j = 0; j < n; j++){
			if(words[j].f <= i){
				dp[i] += dp[i - words[j].f];
				dp[i] %= MOD;
			}
		}
	}
	vector<ll> r_sum(n); // sum of the ith rhyme class. 
	for(int i = 0; i < n; i++){
		r_sum[words[i].s] += dp[k - words[i].f];
		r_sum[words[i].s] %= MOD; 
	}
	ll ans = 0;
	for(int i = 0; i < 26; i++){
		ll sum = 1;
		for(int j = 0; j < n; j++){
			sum += binpow(r_sum[j], letter_cnt[i]);
			sum %= MOD;
		}
		ans *= sum;
		ans %= MOD;
	}
	cout << ans << endl;
}