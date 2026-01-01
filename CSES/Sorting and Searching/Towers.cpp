#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include <queue>
#include <cmath>
 
using namespace std;
#define ll long long 
 
 
int main(){
    int n; cin >> n;
    multiset<int> towers;
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        // for(auto element: towers) cout << element << " ";
        // cout << endl;
        auto replace = towers.upper_bound(a);
        if(replace != towers.end()){
            towers.erase(replace);
        }
        towers.insert(a);
    }
    cout << towers.size() << endl;
