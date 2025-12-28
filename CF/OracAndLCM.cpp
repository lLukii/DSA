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
#define ll long long
 
const int MAXN = 2e5 + 1;
int max_prime[MAXN], factors[MAXN][32]; // factors[i][j] returns the number of elements with i ^ j in prime factorization. 
 
int main(){
    int n; cin >> n;
    for(int i = 2; i < MAXN; i++){
        if(!max_prime[i]){
            for(int j = i; j < MAXN; j += i){
                max_prime[j] = i;
            }
        }
    }
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        while(x > 1){
            int d = max_prime[x];
            int cnt = 0;
            while(x % d == 0){
                x /= d;
                cnt++;
            }
            factors[d][cnt]++;
        }
    }
    ll ans = 1;
    for(int i = 2; i < MAXN; i++){
        int elements = 0;
        for(int j = 31; j >= 0; j--){
            elements += factors[i][j];
            if(elements >= n-1){
                ans *= pow(i, j);
                break;
            }
        }
    }
    cout << ans << endl;
}