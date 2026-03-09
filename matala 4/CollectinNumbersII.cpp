#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using str = string;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m;
    cin >> n >> m;
    vector<ll> arr(n + 1), pos(n + 1);
    for(ll i = 1; i <= n; i++){
        cin >> arr[i];
        pos[arr[i]] = i;
    }

    ll rounds = 1;
    for(ll i = 2; i <= n; i++){
        if(pos[i] < pos[i - 1]){
            rounds++;
        }
    }

    while(m--){
        ll a, b;
        cin >> a >> b;
        ll x = arr[a];
        ll y = arr[b];
        set<ll> check;
        for(ll v : {x, x - 1, x + 1, y, y - 1, y + 1}){
            if(v >= 2 && v <= n){
                check.insert(v);
            }
        }
        for(ll v : check){
            if(pos[v] < pos[v - 1]){
                rounds--;
            }
        }
        swap(arr[a], arr[b]);
        swap(pos[x], pos[y]);
        for(ll v : check){
            if(pos[v] < pos[v - 1]){
                rounds++;
            }
        }
        cout << rounds << "\n";
    }
    return 0;
}
