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
 
int main(){
	int q; cin >> q;
	while(q--){
		ll n; cin >> n;
		if(n == 1){
			cout << 0 << endl;
			continue;
		}
		ll l = n-1, r = 2*n, ans = n-1;
		while(l <= r){
			ll mid = l + (r-l)/2;
			ll not_cyc = ceil((double)mid/2);
			ll cyc = n - not_cyc;
			if(((cyc-1)*cyc)/2 + not_cyc >= mid){
				// we can create that many edges while ensuring that there is a sufficient amount of bridges
				ans = mid;
				l = mid+1;
			}
			else r = mid-1;
		}
		cout << ans << endl;
	}
}