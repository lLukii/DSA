#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
 
vector<pair<int, int>> dp;
int n; 
 
bool f(ll op, int x1, int x2, int y1, int y2){
    ll sumx = 1LL*(op/n)*dp[n].first+dp[op%n].first, sumy = 1LL*(op/n)*dp[n].second+dp[op%n].second;
    return abs(x2-x1-sumx) + abs(y2-y1-sumy) <= op;
    
}
 
int main(){
    int x1, y1; cin >> x1 >> y1;
    int x2, y2; cin >> x2 >> y2;
    cin >> n;
    string s; cin >> s;
    dp = vector<pair<int, int>>(n+1);
    for(int i = 1; i <= n; i++){
        int x = 0, y = 0;
        if(s[i-1] == 'U') y++;
        else if(s[i-1] == 'D') y--;
        else if(s[i-1] == 'L') x--;
        else x++;
        dp[i].first = dp[i-1].first + x;
        dp[i].second = dp[i-1].second + y;
    }
    
    ll l = 0, r = 1e18, ans = -1;
    while(l <= r){
        ll mid = l + (r-l)/2;
        if(f(mid, x1, x2, y1, y2)){
            ans = mid;
            r = mid-1;
        }
        else l = mid+1;
    }
    cout << ans << endl;
}