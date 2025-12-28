/**
 * Codeforces Round 797 Problem G
 * Rating: 2000
 */

#include <iostream>
#include <iomanip>
#include <vector>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#include <queue>
 
using namespace std;
#define f first
#define s second
#define pii pair<int, int>
#define int long long
 
void solve(){
    int n, m; cin >> n >> m;
    vector<int> carriges(n);
    for(int i = 0; i < n; i++){
        cin >> carriges[i];
    }
    set<int> pos;
    pos.insert(0);
    int threshold = carriges[0]; 
    for(int i = 0; i < n; i++){
        if(carriges[i] < threshold){
            threshold = carriges[i];
            pos.insert(i);
        }
    }
    
    while(m--){
        int k, d; cin >> k >> d; k--;
        carriges[k] -= d;
        while(1){
            auto itr = pos.lower_bound(k);
            if(itr == pos.end() || carriges[*itr] < carriges[k]) break;
            pos.erase(itr);
        }
        pos.insert(k);
        auto itr = pos.lower_bound(k);
        if(itr != pos.begin()){
            itr--;
            if(carriges[*itr] <= carriges[k]) pos.erase(++itr); // since we're adding k each time, we want to remove position k from the set if the start of the train != k. 
        }
        cout << pos.size() << " ";
    }
}
 
signed main(){
    int t; cin >> t;
    while(t--){
        solve();
        cout << endl;
    }
}