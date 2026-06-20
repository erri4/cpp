#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// n <= 8
/*vector<vector<ll>> opts(vector<vector<bool>> rumors){
    vector<ll> tmp(rumors.size());
    for (ll i = 0; i < rumors.size(); i++) tmp[i] = i;
    vector<vector<ll>> res(rumors.size(), vector<ll>());
    bool bad;
    do {
        bad = false;
        for (ll i = 0; i < tmp.size(); i++){
            for (ll j = i + 1; j < tmp.size(); j++){
                if (rumors[tmp[i]][tmp[j]]){
                    bad = true;
                    break;
                }
            }
            if (bad) break;
        }
        if (!bad){
            for (ll i = 0; i < tmp.size(); i++){
                res[i].push_back(tmp[i]);
            }
        }
    } while (next_permutation(tmp.begin(), tmp.end()));
    return res;
}*/

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    ll n; ll m; ll t;
    cin >> n >> m >> t;
    ll k = -1;
    if (t == 2){
        cin >> k;
    }
    // vector<bool> op(n, true); // t = 1
    vector<vector<ll>> rumors1(n + 1, vector<ll>()); // rumors1[i] = {all those who are smaller than i}
    vector<vector<ll>> rumors2(n + 1, vector<ll>()); // rumors2[i] = {all those who are bigger than i}
    ll a; ll b; bool f;
    for (ll i = 0; i < m; i++){
        cin >> a >> b;
        rumors1[b].push_back(a); // a < b
        for (ll x : rumors1[a]){
            f = false;
            for (ll y : rumors1[b]){
                if (y == x) f = true;
            }
            if (!f) rumors1[b].push_back(x);
        }
        rumors2[a].push_back(b); // a < b
        for (ll x : rumors2[b]){
            f = false;
            for (ll y : rumors2[a]){
                if (y == x) f = true;
            }
            if (!f) rumors2[a].push_back(x);
        }
        //op[a] = false; // t = 1
    }
    for (ll i = rumors2[k].size() + 2; i <= n - rumors1[k].size(); i++) cout << i << ' ';
    //for (ll i = 1; i < n; i++) rumors[0][i] = true;

    // t = 1
    /*for (ll i = 1; i < n; i++){
        if (op[i]) cout << i << ' ';
    }*/
    // n <= 8
    /*if (t == 1){
        for (ll x : opts(rumors)[1]) cout << x << ' ';
    }
    if (t == 2){
        auto o = opts(rumors);
        vector<ll> printed;
        bool p;
        for (ll i = 0; i < o.size(); i++){
            for (ll j = 0; j < o[i].size(); j++){
                if (o[i][j] == k){
                    p = false;
                    for (ll x : printed){
                        if (x == n - i) p = true;
                    }
                    if (!p){
                        cout << n - i << ' ';
                        printed.push_back(n - i);
                    }
                }
            }
        }
    }*/
    return 0;
}