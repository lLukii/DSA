/**
 * USA Computing Olympiad, 2019 January Gold
 * P1 - Sleepy Cow Sorting
 */

#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define mp make_pair
#define ll long long

const int mod = 1e9 + 7;

int n; 
vector<int> ft(100002); 

void upd(int idx, int val){
    for(; idx <= n; idx += idx & -idx){
        ft[idx] += val;
    }
}

int qry(int idx){
    int total = 0;
    for(; idx > 0; idx -= idx & -idx){
        total += ft[idx];
    }
    return total;
}

int main(){
    freopen("sleepy.in", "r", stdin);
    freopen("sleepy.out", "w", stdout);
    cin >> n;
    vector<int> cows(n);
    for(int i = 0; i < n; i++) cin >> cows[i];
    int j = 0;
    for(int i = n-1; i > 0; i--){
        upd(cows[i], 1);
        if(cows[i] < cows[i-1]){
            j = i;
            break;
        }
    }
    cout << j << endl;
    for(int i = 0; i < j; i++){
        cout << j - i - 1 + qry(cows[i]) << (i == j - 1 ? "" : " ");
        upd(cows[i], 1);
    }
}