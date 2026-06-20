#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    ll m;
    ll a, b;
    cin >> n >> m;
    vector<ll> res(n, -1);
    bool imp = false;
    for (ll i = 0; i < m; i++){
        cin >> a >> b;
        a--;b--;
        if (res[a] == -1 && res[b] == -1){
            res[a] = 1;
            res[b] = 2;
        }
        else if (res[a] != -1 && res[b] == -1){
            res[b] = 3 - res[a];
        }
        else if (res[b] != -1 && res[a] == -1){
            res[a] = 3 - res[b];
        }
        else if (res[a] == res[b] && res[a] != -1){
            imp = true;
        }
    }

    if (imp){
        printf("IMPOSSIBLE");
    }
    else {
        for (ll magic : res){
            if (magic != -1){
                cout << magic << " ";
            }
            else {
                cout << 1 << " ";
            }
        }
    }

    return 0;
}