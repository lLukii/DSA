#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size(), mod = 1e9+7;
        long long dp[n][m][k];
        memset(dp, 0, sizeof(dp));
        dp[0][0][grid[0][0] % k] = 1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int m = grid[i][j] % k;
                for(int a = 0; a < k; a++){
                    int c = (((a-m)%k)+k)%k;
                    if(i > 0) dp[i][j][a] = (dp[i][j][a] + dp[i-1][j][c]) % mod;
                    if(j > 0) dp[i][j][a] = (dp[i][j][a] + dp[i][j-1][c]) % mod;
                }
            }
        }
        return dp[n-1][m-1][0];
    }
};