#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define f first
#define s second
#define all(x) x.begin(), x.end()
#define lb(v, x) lower_bound(v.begin(), v.end(), x)
#define ub(v, x) upper_bound(v.begin(), v.end(), x)
#define pii pair<int, int>
template <typename T> T gcd(T a, T b) {return b==0 ? a : gcd(b, a%b);}
const int MOD = 1e9+7;

void fIO(string name){
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}

int n, l; 
struct Cow{
    double weight, x, dir;
    bool out;
};

int main(){
    // fIO("meetings");
    cin >> n >> l;
    vector<Cow> cows;
    int weight = 0;
    for(int i = 0; i < n; i++){
        double w, x, d; cin >> w >> x >> d;
        cows.push_back({w, x, d, false});
        weight += w;
    }
    sort(all(cows), [](Cow &a, Cow &b){
        return a.x <= b.x;
    });
    
    bool running = true;
    int ans = 0, farm_weight = 0;
    while(running){
        double min_meeting = 1e9;
        for(int i = 0; i < n-1; i++){
            // cout << cows[i].x << " ";
            if(!cows[i].out && !cows[i+1].out){
                if(cows[i].dir == 1 && cows[i+1].dir == -1){
                    min_meeting = min(min_meeting, cows[i+1].x - cows[i].x);
                }
            }
        }
        // cout << cows[n-1].x << endl;
        if(min_meeting == 1e9) break; // no more meetings left; we will reach the desired weight having the same amt of meetings in the end

        // update the cow positions
        vector<pii> exit; 
        for(int i = 0; i < n; i++){
            cows[i].x += min_meeting/2 * cows[i].dir;
            if(!cows[i].out && (cows[i].x <= 0 || cows[i].x >= l)){
                int diff = cows[i].x >= l ? cows[i].x - l : -cows[i].x;
                exit.push_back({diff, cows[i].weight});
                cows[i].out = true;
            }
        }
        sort(all(exit)); reverse(all(exit));
        bool add = false, satis = false;
        for(auto c: exit){
            farm_weight += c.s;
            if(c.f == 0) add = true;
            if(2*farm_weight >= weight){
                satis = true;
                // ans += add;
                break;
            }
        }
        if(satis) break;
        // check for meetings
        for(int i = 0; i < n-1; i++){
            if(cows[i].x == cows[i+1].x){ // if fails, check for precision error
                cows[i].dir *= -1;
                cows[i+1].dir *= -1;
                ans++;
            }
        }
    }
    cout << ans << endl;
}