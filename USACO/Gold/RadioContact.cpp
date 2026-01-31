#include <iostream>
#include <vector>

using namespace std;
#define ll long long
#define f first
#define s second
const int MOD = 1e9 + 7;

int main(){
	freopen("radio.in", "r", stdin);
	freopen("radio.out", "w", stdout);
	int n, m; cin >> n >> m;
	int fx, fy, bx, by; 
	cin >> fx >> fy >> bx >> by;
	string path_f, path_b; cin >> path_f >> path_b;
	
	vector<vector<int>> dp(n+1, vector<int>(m+1, 1e9));
	vector<pair<int, int>> pos_f(n+1), pos_b(m+1);
 	pos_f[0] = {fx, fy};
 	pos_b[0] = {bx, by};

	for(int i = 1; i <= n; i++){
     	int dx = 0, dy = 0;
 		switch(path_f[i-1]){
 			case 'W': dx = -1; break;
			case 'E': dx = 1; break;
			case 'S': dy = -1; break;
			case 'N': dy = 1; break;
 		}		
     	pos_f[i].f = pos_f[i-1].f + dx;
		pos_f[i].s = pos_f[i-1].s + dy;
	}
	for(int i = 1; i <= m; i++){
		int dx = 0, dy = 0;
 		switch(path_b[i-1]){
 			case 'W': dx = -1; break;
			case 'E': dx = 1; break;
			case 'S': dy = -1; break;
			case 'N': dy = 1; break;
 		}		
     	pos_b[i].f = pos_b[i-1].f + dx;
		pos_b[i].s = pos_b[i-1].s + dy;
	}

	dp[0][0] = 0;
	for(int i = 0; i <= n; i++){
     		for(int j = 0; j <= m; j++){
     			int x = (pos_f[i].f - pos_b[j].f); 
     			int y = (pos_f[i].s - pos_b[j].s);
     			int dist = x * x + y * y;
     			if(i > 0 && j > 0) dp[i][j] = min(dp[i][j], dp[i-1][j-1]);
     			if(i > 0) dp[i][j] = min(dp[i][j], dp[i-1][j]);
     			if(j > 0) dp[i][j] = min(dp[i][j], dp[i][j-1]);
     			if(i != 0 || j != 0) dp[i][j] += dist; // otherwise must consume energy. 
		}
	}
	cout << dp[n][m] << endl;
}
