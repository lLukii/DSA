#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <set>
 
using namespace std;
typedef long long ll;
#define f first
#define s second
 
int main(){
    int x, n; cin >> x >> n;
    multiset<int> sizes;
    for(int i = 0; i < n; i++){
        int v; cin >> v;
        sizes.insert(v);
    }
    ll ans = 0;
    while(1){
        int tmp = *sizes.begin();
        sizes.erase(sizes.begin());
        if(sizes.empty()) break; // no more
        int sum = (tmp + *sizes.begin());
        ans += sum*1LL;
        sizes.erase(sizes.begin());
        sizes.insert(sum);
    }
    cout << ans << endl;
}
