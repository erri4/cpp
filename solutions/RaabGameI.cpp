#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct triplet{
    ll n;
    ll a;
    ll b;
};

int main(){
    ll t;
    cin >> t;
    vector<triplet> games(t);
    vector<ll> pa;
    vector<ll> pb;
    for (ll i = 0; i < t; i++) cin >> games[i].n >> games[i].a >> games[i].b;
    for (auto game : games){
        if (game.n - game.a - game.b < 0){
            cout << "NO" << '\n';
            continue;
        }
        if (game.n - game.a - game.b % 2 == 1){
            cout << "NO" << '\n';
            continue;
        }
        cout << "YES" << '\n';
        pa.clear();
        pb.clear();
        
    }
    return 0;
}