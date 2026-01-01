#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
 
using namespace std;
typedef long long ll;
#define f first
#define s second
 
int main(){
    int n; cin >> n;
    vector<int> p(n);
    for(int i = 0; i < n; i++){
        cin >> p[i];
    }
    sort(p.begin(), p.end());
    int mid = p[n/2];
    ll ans = 0;
    for(int i = 0; i < n; i++){
        ans += abs(mid-p[i]);
    }
    cout << ans << endl;
}