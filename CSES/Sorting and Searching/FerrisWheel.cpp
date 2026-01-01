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
    int n, x; cin >> n >> x;
    vector<int> weight(n);
    for(int i = 0; i < n; i++){
        cin >> weight[i];
    }
    sort(weight.begin(), weight.end());
    int i = 0, j = n-1, ans =0;
    while(i <= j){
        if(i == j){
            ans++;
            break;
        }
        if(weight[i] + weight[j] > x){
            ans++;
            j--;
        }
        else{
            i++;
            j--;
            ans++;
        }
    }
    cout << ans << endl;
}