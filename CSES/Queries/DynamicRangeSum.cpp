#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define mp make_pair
#define ll long long

/**
 * Implemented with segtree, although there is a much cleaner sol using BIT. 
 */

struct SegTree{
    int n; 
    vector<ll> segtree;

    void build(vector<int> &a, int at, int left, int right){
        if(left == right){
            segtree[at] = a[left];
            return;
        }
        int mid = (left + right) / 2;
        build(a, 2 * at, left, mid);
        build(a, 2 * at + 1, mid + 1, right);
        segtree[at] = segtree[2 * at] + segtree[2 * at + 1];
    }

    void set(int idx, int val, int at, int left, int right){
        if(left == right){
            segtree[at] = val;
            return;
        }
        int mid = (left + right) / 2;
        if(idx <= mid) set(idx, val, 2 * at, left, mid);
        else set(idx, val, 2 * at + 1, mid + 1, right);
        segtree[at] = segtree[2 * at] + segtree[2 * at + 1];
    }

    ll query(int l, int r, int at, int q_left, int q_right){
        if(q_right < l || r < q_left) return 0;
        if(l <= q_left && q_right <= r) return segtree[at];
        int mid = (q_left + q_right) / 2;
        ll left_res = query(l, r, 2 * at, q_left, mid);
        ll right_res = query(l, r, 2 * at + 1, mid + 1, q_right);
        return left_res + right_res;
    }
    
    SegTree(vector<int> &arr, int n) : n(n){
        segtree = vector<ll>(4 * n);
        for(int i = 0; i < 4 * n; i++){
            segtree[i] = 0;
        }
        build(arr, 1, 0, n - 1);
    }

    void upd(int idx, int val){
        set(idx, val, 1, 0, n - 1);
    }

    ll query(int l, int r){
        return query(l, r, 1, 0, n - 1);
    }
};

int main(){
    int n, q; cin >> n >> q;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    SegTree st(arr, n);
    while(q--){
        int t, a, b; cin >> t >> a >> b;
        if(t == 1) st.upd(a-1, b);
        else cout << st.query(a-1, b-1) << endl;
    }
}