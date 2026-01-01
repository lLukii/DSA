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
	int n, k; cin >> n >> k;
	vector<pair<int, int>> events;
	multiset<int> active;
	for(int i = 0; i < n; i++){
		int a, b; cin >> a >> b;
		events.push_back({b, a});
	}
	for(int i = 0; i < k; i++){
		active.insert(0);
	}
	sort(begin(events), end(events));
	int ans = 0;
	for(auto event: events){
		if(*active.begin() <= event.s){
			int largest = *--active.upper_bound(event.s);
			active.erase(active.find(largest));
			active.insert(event.f);
			ans++;
		}
		// for(int a: active) cout << a << " ";
		// cout << endl;
	}
	cout << ans << endl;
}