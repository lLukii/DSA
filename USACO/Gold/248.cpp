#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define mp make_pair
#define ll long long

const int mod = 1e9+7;

int main(){
    freopen("248.in", "r", stdin);
    freopen("248.out", "w", stdout);
    int n; cin >> n;
    vector<int> a(n);
    vector<vector<int>> dp(n, vector<int>(n));
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++){
        dp[i][i] = a[i];
    }
    for(int s = 0; s < n; s++){
        for(int i = 0; i < n-s; i++){
            int k = i+s; 
            for(int j = i; j < i+s; j++){
                if(dp[i][j] == dp[j+1][k]){
                    dp[i][k] = max(dp[i][k], dp[i][j]+1);
                }
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans << endl;
}